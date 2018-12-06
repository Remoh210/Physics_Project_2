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

	//sModelDrawInfo tableInfo;
	//tableInfo.meshFileName = "table.ply";				
	//pTheVAOMeshManager->LoadModelIntoVAO(tableInfo, shaderProgramID);

	//sModelDrawInfo AxeInfo;
	//AxeInfo.meshFileName = "AxePainted.ply";					// "mig29_xyz.ply";
	//pTheVAOMeshManager->LoadModelIntoVAO(AxeInfo, shaderProgramID);
	//


	//sModelDrawInfo teapotInfo;
	//teapotInfo.meshFileName = "Utah_Teapot_xyz_n_GARBAGE_uv.ply";			// "Utah_Teapot_xyz.ply";
	//pTheVAOMeshManager->LoadModelIntoVAO(teapotInfo, shaderProgramID);

	//smodeldrawinfo ufoinfo;
	//ufoinfo.meshfilename = "ufo2uvb.ply";			// "utah_teapot_xyz.ply";
	//pthevaomeshmanager->loadmodelintovao(ufoinfo, shaderprogramid);

	//sModelDrawInfo terrainInfo;
	//terrainInfo.meshFileName = "MeshLab_Fractal_Terrain_xyz_n.ply";	// "MeshLab_Fractal_Terrain_xyz.ply";
	//// Will alow me to update the vertex data in the mesh
	//terrainInfo.bVertexBufferIsDynamic = true;
	//pTheVAOMeshManager->LoadModelIntoVAO(terrainInfo, shaderProgramID);
	//
	sModelDrawInfo sphereInfo;
	sphereInfo.meshFileName = "Sphere_320.ply";			// "Sphere_320_faces_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(sphereInfo, shaderProgramID);

	sModelDrawInfo sphereInvertedNormalsInfo;
	sphereInvertedNormalsInfo.meshFileName = "Sphere_320_faces_xyz_n_GARBAGE_uv_INVERTED_NORMALS.ply";			// "Sphere_320_faces_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(sphereInvertedNormalsInfo, shaderProgramID);


	sModelDrawInfo mig;
	mig.meshFileName = "mig.ply";			// "Sphere_320_faces_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(mig, shaderProgramID);
	//sModelDrawInfo roomInfo;
	//roomInfo.meshFileName = "roomUV.ply";			// "Sphere_320_faces_xyz.ply";
	//pTheVAOMeshManager->LoadModelIntoVAO(roomInfo, shaderProgramID);



	//sModelDrawInfo skullInfo;
	//skullInfo.meshFileName = "skull.ply";	
	//skullInfo.bVertexBufferIsDynamic = true;
	//pTheVAOMeshManager->LoadModelIntoVAO(skullInfo, shaderProgramID);

	//sModelDrawInfo knightInfo;
	//knightInfo.meshFileName = "knight.ply";
	//knightInfo.bVertexBufferIsDynamic = true;
	//pTheVAOMeshManager->LoadModelIntoVAO(knightInfo, shaderProgramID);

	//sModelDrawInfo knight2Info;
	//knight2Info.meshFileName = "knight2.ply";
	//knight2Info.bVertexBufferIsDynamic = true;
	//pTheVAOMeshManager->LoadModelIntoVAO(knight2Info, shaderProgramID);

	//sModelDrawInfo fireInfo;
	//fireInfo.meshFileName = "fireplace.ply";
	//fireInfo.bVertexBufferIsDynamic = true;
	//pTheVAOMeshManager->LoadModelIntoVAO(fireInfo, shaderProgramID);

	//sModelDrawInfo lampInfo;
	//lampInfo.meshFileName = "lantern.ply";
	//lampInfo.bVertexBufferIsDynamic = true;
	//pTheVAOMeshManager->LoadModelIntoVAO(lampInfo, shaderProgramID);

	//sModelDrawInfo CatInfo;
	//CatInfo.meshFileName = "cat.ply";
	//CatInfo.bVertexBufferIsDynamic = true;
	//pTheVAOMeshManager->LoadModelIntoVAO(CatInfo, shaderProgramID);

	//sModelDrawInfo breadInfo;
	//breadInfo.meshFileName = "bread.ply";
	//breadInfo.bVertexBufferIsDynamic = true;
	//pTheVAOMeshManager->LoadModelIntoVAO(breadInfo, shaderProgramID);


	//for debug draw only ***********************
	sModelDrawInfo cube1x1x1;
	cube1x1x1.meshFileName = "cube_flat_shaded_xyz_n_uv.ply";			// "cube_flat_shaded_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(cube1x1x1, shaderProgramID);

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
//
//	{
//		cMeshObject* pTeapot = new cMeshObject();
//		pTeapot->position = glm::vec3(40.0f, 0.0f, 0.0f);
//		pTeapot->setMeshOrientationEulerAngles(glm::vec3(-90.0f, 0.0f, 0.0f), true);
//		//		pTeapot->objColour = glm::vec3( 1.0f, 0.0f, 0.0f );
//		pTeapot->setDiffuseColour(glm::vec3(0.0f, 0.0f, 0.0f));
//
//		// Make the terrain really shinny...
//		pTeapot->setSpecularPower(100.0f);
//		pTeapot->friendlyName = "Teapot";
//		pTeapot->meshName = "Utah_Teapot_xyz_n_GARBAGE_uv.ply";		// "Utah_Teapot_xyz.ply";
//		// Note scale...
////		pTeapot->nonUniformScale = glm::vec3(0.005f,0.005f,0.005f);
//		pTeapot->setUniformScale(0.5f);
//		// Set the debug renderer here
//
//		// Texture on the teapot
//		sTextureInfo ufoTexture;
//		ufoTexture.name = "metal.bmp";
//		ufoTexture.strength = 1.0f;
//		pTeapot->vecTextures.push_back(ufoTexture);
//
//		pTeapot->pDebugRenderer = ::g_pDebugRenderer;
//
//		vec_pObjectsToDraw.push_back(pTeapot);
//	}
//

	{	// This will be our "skybox" object.
		// (could also be a cube, or whatever)
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
//	//{
//	//	cMeshObject* pSkull = new cMeshObject();
//	//	pSkull->position = glm::vec3(0.0f, 50.0f, 0.0f);
//	//	pSkull->setSpecularColour(glm::vec3(1.0f, 0.4f, 0.1f));
//	//	pSkull->setDiffuseColour(glm::vec3(1.0f, 0.4f, 0.1f));
//	//	pSkull->setSpecularPower(100.0f);
//	//	pSkull->friendlyName = "skull";
//	//	pSkull->bIsInteractable = true;
//	//	pSkull->meshName = "skull.ply";		
//	//	pSkull->setUniformScale(1.5f);
//	//	vec_pObjectsToDraw.push_back(pSkull);
//	//}
//
//
//
//	{
//		cMeshObject* pRoom = new cMeshObject();
//		pRoom->position = glm::vec3(0.0f, 0.0f, 300.0f);
//		//pSpider->postRotation = glm::vec3(0.0f, glm::radians(-20.0f), 0.0f);
//		pRoom->setDiffuseColour(glm::vec3(0.0f, 0.0f, 0.0f));
//		pRoom->friendlyName = "room";
//		pRoom->setSpecularPower(100.0f);
//		pRoom->meshName = "roomUV.ply";
//		pRoom->setUniformScale(100.0f);
//		pRoom->bIsVisible = true;
//		sTextureInfo roomTexture;
//		roomTexture.name = "roomTex.bmp";
//		roomTexture.strength = 1.0f;
//		pRoom->vecTextures.push_back(roomTexture);
//		vec_pObjectsToDraw.push_back(pRoom);
//	}
//
	//{
	//	cMeshObject* pUfo = new cMeshObject();
	//	pUfo->position = glm::vec3(0.0f, 20.0f, 0.0f);
	//	pUfo->setDiffuseColour(glm::vec3(0.0f, 0.0f, 0.0f));
	//	pUfo->friendlyName = "Ufo2UVb";
	//	pUfo->setSpecularPower(100.0f);
	//	pUfo->meshName = "Ufo2UVb.ply";
	//	pUfo->setUniformScale(10.0f);
	//	pUfo->bIsVisible = true;
	//	sTextureInfo ufoTexture;
	//	ufoTexture.name = "metal.bmp";
	//	ufoTexture.strength = 1.0f;
	//	pUfo->vecTextures.push_back(ufoTexture);
	//	vec_pObjectsToDraw.push_back(pUfo);
	//}
//
//
//
//	{
//		cMeshObject* pTable = new cMeshObject();
//		pTable->position = glm::vec3(0.0f, 10.0f, 0.0f);
//		pTable->setDiffuseColour(glm::vec3(0.0f, 0.0f, 0.0f));
//		pTable->setSpecularPower(100.0f);
//		//pTable->setUniformScale(0.9f);
//		pTable->friendlyName = "table";
//		pTable->meshName = "table.ply";
//		sTextureInfo metalTexture;
//		metalTexture.name = "metal.bmp";
//		metalTexture.strength = 1.0f;
//		pTable->vecTextures.push_back(metalTexture);
//		sTextureInfo woodTexture;
//		woodTexture.name = "wood.bmp";
//		woodTexture.strength = 0.0f;
//		pTable->vecTextures.push_back(woodTexture);
//		vec_pObjectsToDraw.push_back(pTable);
//	}
//
//	{
//		cMeshObject* pKnight = new cMeshObject();
//		pKnight->position = glm::vec3(0.0f, 10.0f, 0.0f);
//		pKnight->setDiffuseColour(glm::vec3(0.0f, 0.0f, 0.0f));
//		pKnight->setSpecularPower(100.0f);
//		pKnight->setUniformScale(10.0f);
//		pKnight->friendlyName = "knight";
//		pKnight->meshName = "knight.ply";
//		sTextureInfo knightTexture;
//		knightTexture.name = "knightTex.bmp";
//		knightTexture.strength = 1.0f;
//		pKnight->vecTextures.push_back(knightTexture);
//		vec_pObjectsToDraw.push_back(pKnight);
//	}
//
//
//	{
//		cMeshObject* pKnight2 = new cMeshObject();
//		pKnight2->position = glm::vec3(0.0f, 10.0f, 0.0f);
//		pKnight2->setDiffuseColour(glm::vec3(0.0f, 0.0f, 0.0f));
//		pKnight2->setSpecularPower(100.0f);
//		pKnight2->setUniformScale(10.0f);
//		pKnight2->friendlyName = "knight2";
//		pKnight2->meshName = "knight2.ply";
//		sTextureInfo knightTexture2;
//		knightTexture2.name = "knight2Tex.bmp";
//		knightTexture2.strength = 1.0f;
//		pKnight2->vecTextures.push_back(knightTexture2);
//		vec_pObjectsToDraw.push_back(pKnight2);
//	}
//
//	{
//		cMeshObject* pFire = new cMeshObject();
//		pFire->position = glm::vec3(0.0f, 10.0f, 0.0f);
//		pFire->setDiffuseColour(glm::vec3(0.0f, 0.0f, 0.0f));
//		pFire->setSpecularPower(100.0f);
//		pFire->setUniformScale(10.0f);
//		pFire->friendlyName = "fire";
//		pFire->meshName = "fireplace.ply";
//		sTextureInfo fireTexture;
//		fireTexture.name = "fireplace.bmp";
//		fireTexture.strength = 1.0f;
//		pFire->vecTextures.push_back(fireTexture);
//		vec_pObjectsToDraw.push_back(pFire);
//	}
//
//
//
//	{
//		cMeshObject* pLamp = new cMeshObject();
//		pLamp->position = glm::vec3(0.0f, 10.0f, 0.0f);
//		pLamp->setDiffuseColour(glm::vec3(0.0f, 0.0f, 0.0f));
//		pLamp->setSpecularPower(100.0f);
//		pLamp->setUniformScale(10.0f);
//		pLamp->friendlyName = "lamp";
//		pLamp->meshName = "lantern.ply";
//		sTextureInfo lampTexture;
//		lampTexture.name = "lantern.bmp";
//		lampTexture.strength = 1.0f;
//		pLamp->vecTextures.push_back(lampTexture);
//		vec_pObjectsToDraw.push_back(pLamp);
//	}
//
//	{
//		cMeshObject* pCat = new cMeshObject();
//		pCat->position = glm::vec3(0.0f, 10.0f, 0.0f);
//		pCat->setDiffuseColour(glm::vec3(0.0f, 0.0f, 0.0f));
//		pCat->setSpecularPower(100.0f);
//		pCat->setUniformScale(10.0f);
//		pCat->friendlyName = "cat";
//		pCat->meshName = "cat.ply";
//		sTextureInfo catTexture;
//		catTexture.name = "cat.bmp";
//		catTexture.strength = 1.0f;
//		pCat->vecTextures.push_back(catTexture);
//		vec_pObjectsToDraw.push_back(pCat);
//	}
//
//
//	{
//		cMeshObject* pBread = new cMeshObject();
//		pBread->position = glm::vec3(0.0f, 10.0f, 0.0f);
//		pBread->setDiffuseColour(glm::vec3(0.0f, 0.0f, 0.0f));
//		pBread->setSpecularPower(100.0f);
//		pBread->setUniformScale(10.0f);
//		pBread->friendlyName = "bread";
//		pBread->meshName = "bread.ply";
//		sTextureInfo breadTexture;
//		breadTexture.name = "bread.bmp";
//		breadTexture.strength = 1.0f;
//		pBread->vecTextures.push_back(breadTexture);
//		vec_pObjectsToDraw.push_back(pBread);
//	}
//
//
//
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

	pPlayerSphere->pDebugRenderer = ::g_pDebugRenderer;

	//pTerrain->nonUniformScale = glm::vec3(0.1f,0.1f,0.1f);
	vec_pObjectsToDraw.push_back(pPlayerSphere);
	}



	{	// This sphere is the tiny little debug sphere
		cMeshObject* pSphereLeft = new cMeshObject();
		pSphereLeft->setDiffuseColour(glm::vec3(1.0f, 0.0f, 0.0f));
		pSphereLeft->friendlyName = "DebugSphereLeft";
		pSphereLeft->meshName = "Sphere_320.ply";
		pSphereLeft->bIsWireFrame = true;
		pSphereLeft->bDontLight = true;
		pSphereLeft->bIsVisible = false;
		float scale = 0.25f;
		pSphereLeft->nonUniformScale = glm::vec3(scale, scale, scale);
		pSphereLeft->position = glm::vec3(0.0f, 0.0f, 0.0f);
		pSphereLeft->bIsUpdatedByPhysics = true;
		pSphereLeft->bIsDebug = true;
		pSphereLeft->pDebugRenderer = ::g_pDebugRenderer;
		pSphereLeft->pTheShape = new sSphere(scale);
		pSphereLeft->shapeType = cMeshObject::SPHERE;
		vec_pObjectsToDraw.push_back(pSphereLeft);
		
	}

	{	// This sphere is the tiny little debug sphere
		cMeshObject* pSphereRight = new cMeshObject();
		pSphereRight->setDiffuseColour(glm::vec3(1.0f, 0.0f, 0.0f));
		pSphereRight->friendlyName = "DebugSphereRight";
		pSphereRight->meshName = "Sphere_320.ply";
		pSphereRight->bIsWireFrame = true;
		pSphereRight->bIsVisible = false;
		pSphereRight->bDontLight = true;
		float scale = 0.25f;
		pSphereRight->nonUniformScale = glm::vec3(scale, scale, scale);
		pSphereRight->position = glm::vec3(0.0f, 0.0f, 0.0f);
		pSphereRight->bIsUpdatedByPhysics = true;
		pSphereRight->bIsDebug = true;
		pSphereRight->pDebugRenderer = ::g_pDebugRenderer;
		pSphereRight->pTheShape = new sSphere(scale);
		pSphereRight->shapeType = cMeshObject::SPHERE;
		vec_pObjectsToDraw.push_back(pSphereRight);

	}

	{	// This sphere is the tiny little debug sphere
		cMeshObject* pSphereNose = new cMeshObject();
		pSphereNose->setDiffuseColour(glm::vec3(1.0f, 0.0f, 0.0f));
		pSphereNose->friendlyName = "DebugSphereNose";
		pSphereNose->meshName = "Sphere_320.ply";
		pSphereNose->bIsWireFrame = true;
		pSphereNose->bDontLight = true;
		float scale = 0.25f;
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

//
//	{	// This sphere is the tiny little debug sphere
//		cMeshObject* pAxe = new cMeshObject();
//		pAxe->position = glm::vec3(0.0f, 0.0f, 0.0f);
//		pAxe->setDiffuseColour(glm::vec3(0.0f, 0.0f, 0.0f));
//		pAxe->setSpecularPower(100.0f);
//		//	pDebugSphere->objColour = glm::vec3(0.0f, 1.0f, 0.0f);
//		float scale = 30.0f;
//		pAxe->friendlyName = "AxePainted";
//		pAxe->nonUniformScale = glm::vec3(scale, scale, scale);
//		pAxe->meshName = "AxePainted.ply";
//		pAxe->bIsWireFrame = false;
//		pAxe->bIsVisible = true;
//		sTextureInfo AxeTexture;
//		AxeTexture.name = "AxeTex.bmp";
//		AxeTexture.strength = 1.0f;
//		pAxe->vecTextures.push_back(AxeTexture);
//		vec_pObjectsToDraw.push_back(pAxe);
//	}
//
//
//	{
//		cMeshObject* pCube = new cMeshObject();
//		pCube->setDiffuseColour(glm::vec3(0.0f, 1.0f, 0.0f));
//		pCube->bDontLight = true;
//		pCube->friendlyName = "DebugCube";
//		pCube->meshName = "cube_flat_shaded_xyz_n_uv.ply";		// "cube_flat_shaded_xyz.ply";
//		pCube->setUniformScale(1.0f);
//		vec_pObjectsToDraw.push_back(pCube);
//
//	}
//
//	{
//		cMeshObject* pTerrain = new cMeshObject();
//		pTerrain->bUseVertexColour = false;
//		//		pTerrain->u
//		pTerrain->meshName = "terrain.ply";		// "MeshLab_Fractal_Terrain_xyz.ply";
//		pTerrain->friendlyName = "The Terrain";
//		//pTerrain->bIsWireFrame = true;
//		pTerrain->bIsVisible = true;
//		vec_pObjectsToDraw.push_back(pTerrain);
//	}





	// ENDOF: Updated physics object





	return;
}