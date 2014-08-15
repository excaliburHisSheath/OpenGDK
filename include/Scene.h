#pragma once

#include <vector>

class Scene
{
public:
	Scene( Ogre::Root* root, Ogre::RenderWindow* renderWindow );

	void Update( const Input& input );

	GameObject AddGameObject( const char* name = "Game Object" );
	Camera AddCameraComponent( GameObject& gameObject );
	Behavior AddBehaviorComponent( GameObject& gameObject, BehaviorFunction behavior );

	void AddMeshToGameObject( GameObject& gameObject, const char* name, const char* mesh );
	void SetGameObjectLook( GameObject& gameObject, float x, float y, float z );

	GameObjectComponent* FindComponent( GameObject& gameObject );
	CameraComponent* FindComponent( Camera& camera );

private:
	std::vector< GameObjectComponent > gameObjects;
	std::vector< CameraComponent > cameraComponents;
	std::vector< BehaviorComponent > behaviorComponents;

	Ogre::Root* root;
	Ogre::SceneManager* sceneManager;
	Ogre::RenderWindow* renderWindow;
};
