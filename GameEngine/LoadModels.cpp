#include "globalOpenGLStuff.h"
#include "globalStuff.h"	
#include "cAABB.h"// for g_pRogerRabbit

#include "cVAOMeshManager.h"
#include "cMeshObject.h"

#include "DebugRenderer/cDebugRenderer.h"

#include <iostream>

// Loading models was moved into this function
void LoadModelTypes( cVAOMeshManager* pTheVAOMeshManager, GLuint shaderProgramID )
{


	sModelDrawInfo sphereInfo;
	sphereInfo.meshFileName = "Sphere_320.ply";			// "Sphere_320_faces_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(sphereInfo, shaderProgramID);

	sModelDrawInfo sphereInvertedNormalsInfo;
	sphereInvertedNormalsInfo.meshFileName = "Sphere_320_faces_xyz_n_GARBAGE_uv_INVERTED_NORMALS.ply";			// "Sphere_320_faces_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(sphereInvertedNormalsInfo, shaderProgramID);


	//for debug draw only ***********************
	sModelDrawInfo cube1x1x1;
	cube1x1x1.meshFileName = "cube_flat_shaded_xyz_n_uv.ply";			// "cube_flat_shaded_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(cube1x1x1, shaderProgramID);


	sModelDrawInfo beam;
	beam.meshFileName = "beam.ply";			// "cube_flat_shaded_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(beam, shaderProgramID);

	//sModelDrawInfo terrain;
	//terrain.meshFileName = "terrain.ply";			// "cube_flat_shaded_xyz.ply";
	//pTheVAOMeshManager->LoadModelIntoVAO(terrain, shaderProgramID);


	// At this point, mesh in in GPU
	std::cout << "Mesh was loaded OK" << std::endl;

	::g_pTheTextureManager->SetBasePath("assets/textures/cubemaps");
	std::string errorString;
	if (::g_pTheTextureManager->CreateCubeTextureFromBMPFiles("CityCubeMap",
		"city_lf.bmp", "city_rt.bmp",				// reverse these
		"city_dn.bmp", "city_up.bmp",				// Rotate the image "right 90 degrees")
		"city_ft.bmp", "city_bk.bmp", true, errorString))
	{
		std::cout << "Loaded the city cube map OK" << std::endl;
	}
	else
	{
		std::cout << "Error: city cube map DIDN't load. On no!" << std::endl;
	}
	//::g_pTheTextureManager->SetBasePath("assets/textures");

	//if (!::g_pTheTextureManager->Create2DTextureFromBMPFile("roomTex.bmp", true))
	//{
	//	std::cout << "Didn't load texture" << std::endl;
	//}
	//::g_pTheTextureManager->Create2DTextureFromBMPFile("grass.bmp", true);
	//::g_pTheTextureManager->Create2DTextureFromBMPFile("metal.bmp", true);
	//::g_pTheTextureManager->Create2DTextureFromBMPFile("wood.bmp", true);
	//::g_pTheTextureManager->Create2DTextureFromBMPFile("knightTex.bmp", true);
	//::g_pTheTextureManager->Create2DTextureFromBMPFile("knight2Tex.bmp", true);
	//::g_pTheTextureManager->Create2DTextureFromBMPFile("fireplace.bmp", true);
	//::g_pTheTextureManager->Create2DTextureFromBMPFile("lantern.bmp", true);
	//::g_pTheTextureManager->Create2DTextureFromBMPFile("cat.bmp", true);
	//::g_pTheTextureManager->Create2DTextureFromBMPFile("bread.bmp", true);
	//::g_pTheTextureManager->Create2DTextureFromBMPFile("AxeTex.bmp", true);

	

	return;
}

	
// Loads the models we are drawing into the vector
void LoadModelsIntoScene( std::vector<cMeshObject*> &vec_pObjectsToDraw )
{


	{	
		cMeshObject* pSkyBoxObject = new cMeshObject();
		pSkyBoxObject->setDiffuseColour(glm::vec3(1.0f, 105.0f / 255.0f, 180.0f / 255.0f));
		pSkyBoxObject->bUseVertexColour = false;
		pSkyBoxObject->friendlyName = "SkyBoxObject";
		float scale = 5000.0f;
		pSkyBoxObject->nonUniformScale = glm::vec3(scale, scale, scale);
		pSkyBoxObject->meshName = "Sphere_320_faces_xyz_n_GARBAGE_uv_INVERTED_NORMALS.ply";			// "Sphere_320_faces_xyz.ply";
//		pSkyBoxObject->bIsWireFrame = true;
		pSkyBoxObject->bIsDebug = true;
		// Invisible until I need to draw it
		pSkyBoxObject->bIsVisible = false;

		vec_pObjectsToDraw.push_back(pSkyBoxObject);
	}

	{	// This sphere is the tiny little debug sphere
	cMeshObject* pPlayerSphere = new cMeshObject();
	//		pPlayerSphere->objColour = glm::vec3( 1.0f, 105.0f/255.0f, 180.0f/255.0f );
	pPlayerSphere->setDiffuseColour(glm::vec3(1.0f, 105.0f / 255.0f, 180.0f / 255.0f));
	pPlayerSphere->friendlyName = "DebugSphere";
	float scale = 1.0f;
	pPlayerSphere->nonUniformScale = glm::vec3(scale, scale, scale);
	pPlayerSphere->meshName = "Sphere_320.ply";
	pPlayerSphere->bIsWireFrame = true;

	pPlayerSphere->position = glm::vec3(-100.0f, 10.0f, 0.0f);
	//pPlayerSphere->velocity = glm::vec3(5.0f, 10.0f, 0.0f);		// starts at "up" at 10 mps
	//pPlayerSphere->accel = glm::vec3(0.0f, -5.0f, 0.0f);
	pPlayerSphere->bIsUpdatedByPhysics = true;
	pPlayerSphere->bIsDebug = true;
	pPlayerSphere->bIsVisible = false;

	pPlayerSphere->pDebugRenderer = ::g_pDebugRenderer;

	//pTerrain->nonUniformScale = glm::vec3(0.1f,0.1f,0.1f);
	vec_pObjectsToDraw.push_back(pPlayerSphere);
	}



	{	
		cMeshObject* pSphereLeft = new cMeshObject();
		pSphereLeft->setDiffuseColour(glm::vec3(1.0f, 0.0f, 0.0f));
		pSphereLeft->friendlyName = "DebugSphereLeft";
		pSphereLeft->meshName = "Sphere_320.ply";
		pSphereLeft->bIsWireFrame = true;
		pSphereLeft->bDontLight = true;
		pSphereLeft->bIsVisible = false;
		float scale = 1.0f;
		pSphereLeft->nonUniformScale = glm::vec3(scale, scale, scale);
		pSphereLeft->position = glm::vec3(0.0f, 0.0f, 0.0f);
		pSphereLeft->bIsUpdatedByPhysics = true;
		pSphereLeft->bIsDebug = true;
		pSphereLeft->pDebugRenderer = ::g_pDebugRenderer;
		pSphereLeft->pTheShape = new sSphere(scale);
		pSphereLeft->shapeType = cMeshObject::SPHERE;
		vec_pObjectsToDraw.push_back(pSphereLeft);
		
	}

	{	
		cMeshObject* pSphereRight = new cMeshObject();
		pSphereRight->setDiffuseColour(glm::vec3(0.0f, 0.0f, 1.0f));
		pSphereRight->friendlyName = "DebugSphereRight";
		pSphereRight->meshName = "Sphere_320.ply";
		pSphereRight->bIsWireFrame = true;
		pSphereRight->bIsVisible = false;
		pSphereRight->bDontLight = true;
		float scale = 1.0f;
		pSphereRight->nonUniformScale = glm::vec3(scale, scale, scale);
		pSphereRight->position = glm::vec3(0.0f, 1.0f, 0.0f);
		pSphereRight->bIsUpdatedByPhysics = true;
		pSphereRight->bIsDebug = true;
		pSphereRight->pDebugRenderer = ::g_pDebugRenderer;
		pSphereRight->pTheShape = new sSphere(scale);
		pSphereRight->shapeType = cMeshObject::SPHERE;
		vec_pObjectsToDraw.push_back(pSphereRight);

	}

	{	
		cMeshObject* pSphereNose = new cMeshObject();
		pSphereNose->setDiffuseColour(glm::vec3(0.0f, 1.0f, 0.0f));
		pSphereNose->friendlyName = "DebugSphereNose";
		pSphereNose->meshName = "Sphere_320.ply";
		pSphereNose->bIsWireFrame = true;
		pSphereNose->bDontLight = true;
		pSphereNose->bIsVisible = false;
		float scale = 1.0f;
		pSphereNose->nonUniformScale = glm::vec3(scale, scale, scale);
		pSphereNose->position = glm::vec3(0.0f, 0.0f, 0.0f);
		pSphereNose->bIsUpdatedByPhysics = true;
		pSphereNose->bIsDebug = true;
		pSphereNose->pDebugRenderer = ::g_pDebugRenderer;
		pSphereNose->pTheShape = new sSphere(scale);
		pSphereNose->shapeType = cMeshObject::SPHERE;
		vec_pObjectsToDraw.push_back(pSphereNose);

	}



	{

		cMeshObject* pDebugCube = new cMeshObject();
		pDebugCube->setDiffuseColour(glm::vec3(0.0f, 1.0f, 0.0f));
		pDebugCube->bDontLight = true;
		pDebugCube->position = glm::vec3(0.0f, 0.0f, 0.0f);
		pDebugCube->friendlyName = "DebugCube";
		pDebugCube->bIsDebug = true;
		pDebugCube->meshName = "cube_flat_shaded_xyz_n_uv.ply";		// "cube_flat_shaded_xyz.ply";
		pDebugCube->setUniformScale(1.0f);
		pDebugCube->bIsWireFrame = true;
		vec_pObjectsToDraw.push_back(pDebugCube);
	}




	return;
}