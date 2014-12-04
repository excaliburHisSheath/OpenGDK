#pragma once

#include <vector>
#include <utility>

class Gunship;

class Scene
{
public:
	Gunship* gunship;

	std::vector< GameObjectComponent > gameObjects;

	Ogre::Root* root;
	Ogre::SceneManager* sceneManager;
	Ogre::RenderWindow* renderWindow;

	Scene( Gunship* gunship, Ogre::Root* root, Ogre::RenderWindow* renderWindow );

	void Update( const Input& input, float delta );

	// javascript helper functions
	ComponentInfo AddGameObject( const char* name = "GameObject" );
	void AddCameraComponent( ComponentInfo& gameObject );
	void AddMesh( ComponentInfo& gameObject, const char* mesh );

	GameObjectComponent* FindGameObject( ComponentInfo& gameObjectInfo );
};
