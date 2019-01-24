#include "globalStuff.h"

#include <glm/vec4.hpp> 
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp> 


void PlayerCollisionTest(double deltaTime, GLuint shaderProgramID)
{
	cMeshObject* pPlayer = findObjectByFriendlyName("xwing");
	cMeshObject* pDebugSphereLeft = findObjectByFriendlyName("DebugSphereLeft");
	cMeshObject* pDebugSphereRight = findObjectByFriendlyName("DebugSphereRight");
	cMeshObject* pDebugSphereNose = findObjectByFriendlyName("DebugSphereNose");
	
	if (b_landingMode == false ) {
		if (camera.Front.y > 0.22f) { pPlayer->adjMeshOrientationEulerAngles(glm::vec3(0.005f, 0.0f, 0.0f), false); }
		if (camera.Front.y < -0.22f) { pPlayer->adjMeshOrientationEulerAngles(glm::vec3(-0.005f, 0.0f, 0.0f), false); }
		if (camera.Front.x < 0.22f) { pPlayer->adjMeshOrientationEulerAngles(glm::vec3(0.0f, 0.005f, 0.0f), false); }
		if (camera.Front.x > -0.22f) { pPlayer->adjMeshOrientationEulerAngles(glm::vec3(0.0, -0.005f, 0.0f), false); }

		glm::vec4 vecForwardDirection_ModelSpace = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);

		glm::quat qPlayer29Rotation = pPlayer->getQOrientation();
		glm::mat4 matQPlayer29rotation = glm::mat4(qPlayer29Rotation);
		glm::vec4 vecForwardDirection_WorldSpace = matQPlayer29rotation * vecForwardDirection_ModelSpace;
		vecForwardDirection_WorldSpace = glm::normalize(vecForwardDirection_WorldSpace);
		float forwardSpeed = xwingSpeed;
		float forwardSpeedThisFrame = forwardSpeed * deltaTime;
		pPlayer->velocity = vecForwardDirection_WorldSpace * forwardSpeed;
	}


	glm::vec4 noseContactPoint_ModelSpace = glm::vec4(0.0f, 0.0f, 2.4705f, 1.0f);
	glm::vec4 leftWingTipContactPoint_ModelSpace = glm::vec4(1.8692f, 0.0f, -1.5f, 1.0f);
	glm::vec4 rightWingTipContactPoint_ModelSpace = glm::vec4(-1.8692f, 0.0f, -1.5f, 1.0f);

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
	LightManager->vecLights.at(7)->position = glm::vec4(noseContactPoint_WorldSpace);
	LightManager->vecLights.at(7)->SetRelativeDirection(glm::normalize(pPlayer->velocity));

	return;
}