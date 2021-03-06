#include <OgreRoot.h>
#include <OgreCamera.h>
#include <OgreRenderWindow.h>
#include <OgreSceneManager.h>
#include <Compositor/OgreCompositorManager2.h>

#include "Scene.h"
#include "Components/Camera.h"
#include "Components/Transform.h"

namespace Gunship
{
	namespace Components
	{
		Camera::Camera( const Scene& scene,
		                Transform& transform,
		                const char* cameraName )
		{
			// create camera and add it to scene heirarchy
			camera = scene.sceneManager().createCamera( cameraName );

			camera->detachFromParent();
			transform.node->attachObject( camera );

			camera->setNearClipDistance( 0.5f );
			camera->setFarClipDistance( 1000.0f );

			// setup the camera's compositor
			// each camera gets a workspace.
			// This probably isn't a good idea.
			Ogre::CompositorManager2* pCompositorManager =
				scene.ogreRoot().getCompositorManager2();
			const Ogre::String workspaceName = "scene workspace";
			const Ogre::IdString workspaceID( workspaceName );
			pCompositorManager->createBasicWorkspaceDef( workspaceID,
			                                             Ogre::ColourValue::Red );
			pCompositorManager->addWorkspace( &scene.sceneManager(),
			                                  &scene.renderWindow(),
			                                  camera,
			                                  workspaceID,
			                                  true );
		}

		CameraManager::CameraManager( Scene& scene )
			: _scene( scene )
		{
		}

		Camera& CameraManager::Assign( Entity::ID entity )
		{
			return Assign( entity,
			               _scene,
			               _scene.componentManager< TransformManager >().Get( entity ) );
		}
	}
}
