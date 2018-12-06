#include "globalStuff.h"

// These are for the transformation glm stuff
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective


void PlayerCollisionTest(double deltaTime, GLuint shaderProgramID)
{
	cMeshObject* pPlayer = findObjectByFriendlyName("mig");
	cMeshObject* pDebugSphereLeft = findObjectByFriendlyName("DebugSphereLeft");
	cMeshObject* pDebugSphereRight = findObjectByFriendlyName("DebugSphereRight");
	cMeshObject* pDebugSphereNose = findObjectByFriendlyName("DebugSphereNose");

	if (b_landingMode == false) {
		if (camera.Front.y > 0.3f) { pPlayer->adjMeshOrientationEulerAngles(glm::vec3(0.01f, 0.0f, 0.0f), false); }
		if (camera.Front.y < -0.3f) { pPlayer->adjMeshOrientationEulerAngles(glm::vec3(-0.01f, 0.0f, 0.0f), false); }
		if (camera.Front.x < 0.3f) { pPlayer->adjMeshOrientationEulerAngles(glm::vec3(0.0f, 0.01f, 0.0f), false); }
		if (camera.Front.x > -0.3f) { pPlayer->adjMeshOrientationEulerAngles(glm::vec3(0.0, -0.01f, 0.0f), false); }
		glm::vec4 vecForwardDirection_ModelSpace = glm::vec4(0.0f, 0.0f, /**/1.0f/**/, 1.0f);

		glm::quat qMig29Rotation = pPlayer->getQOrientation();
		glm::mat4 matQMig29rotation = glm::mat4(qMig29Rotation);

		glm::vec4 vecForwardDirection_WorldSpace = matQMig29rotation * vecForwardDirection_ModelSpace;

		vecForwardDirection_WorldSpace = glm::normalize(vecForwardDirection_WorldSpace);

		float forwardSpeed = 10.0f;
		float forwardSpeedThisFrame = forwardSpeed * deltaTime;

		glm::vec3 positionAdjustThisFrame = vecForwardDirection_WorldSpace * forwardSpeedThisFrame;
		pPlayer->position += positionAdjustThisFrame;
	}

	//camera.Position = glm::vec3(pPlayer->position.x, pPlayer->position.y, pPlayer->position.z + 1.0f);


	glm::vec4 noseContactPoint_ModelSpace = glm::vec4(0.0f, 0.0f, 0.4705f, 1.0f);
	glm::vec4 leftWingTipContactPoint_ModelSpace = glm::vec4(0.3692f, 0.0f, -0.9f, 1.0f);
	glm::vec4 rightWingTipContactPoint_ModelSpace = glm::vec4(-0.3692f, 0.0f, -0.9f, 1.0f);

	glm::mat4 matTransform = glm::mat4(1.0f);	
	glm::mat4 matTranslation = glm::translate(glm::mat4(1.0f),
		pPlayer->position);

	matTransform = matTransform * matTranslation;		

	glm::quat qRotation = pPlayer->getQOrientation();

	glm::mat4 matQrotation = glm::mat4(qRotation);

	matTransform = matTransform * matQrotation;


	glm::vec4 noseContactPoint_WorldSpace = glm::vec4(0.0f);
	glm::vec4 leftWingTipContactPoint_WorldSpace = glm::vec4(0.0f);
	glm::vec4 rightWingTipContactPoint_WorldSpace = glm::vec4(0.0f);

	noseContactPoint_WorldSpace = matTransform * noseContactPoint_ModelSpace;
	leftWingTipContactPoint_WorldSpace = matTransform * leftWingTipContactPoint_ModelSpace;
	rightWingTipContactPoint_WorldSpace = matTransform * rightWingTipContactPoint_ModelSpace;


	glm::mat4 matIdentity = glm::mat4(1.0f);

	// nose:

	pDebugSphereNose->position = noseContactPoint_WorldSpace;

	//left wing point:
	pDebugSphereLeft->position = leftWingTipContactPoint_WorldSpace;
	//Right wing point
	pDebugSphereRight->position = rightWingTipContactPoint_WorldSpace;


	return;
}