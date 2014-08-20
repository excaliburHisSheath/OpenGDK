#pragma once

class GameObject;

class CameraComponent
{
public:
	CameraComponent( Ogre::Camera* cam, Ogre::Viewport* view );

private:
	component_id id;

	Ogre::Camera* camera;
	Ogre::Viewport* viewport;

	friend class Scene;
};

class Camera final : ComponentLocator
{
public:
	Camera( Scene* scene = nullptr, component_id id = 0, size_t index = 0 );

	void Destroy() override;
};