#pragma once

#include <vector>
#include <unordered_map>

#include "Entity/ComponentManager.h"
#include "Components/SimpleStructComponent.h"

namespace Ogre
{
	class Entity;
	class SceneManager;
}

namespace Gunship
{
	class Scene;

	namespace Components
	{
		struct Transform;

		/**
		 * @brief Component representing a mesh resource.
		 */
		struct Mesh : public SimpleStructComponent
		{
			Ogre::Entity* mesh;
			Ogre::String meshName; ///< @todo This shouldn't be necessary, find a way to get rid of it.
		};

		class MeshManager : public ComponentManager< MeshManager >
		{
		public:
			MeshManager( Scene& scene );

			Mesh& Assign( Entity::ID entityID, const char* meshName );

			void Destroy( Entity::ID entityID );

			const std::vector< Mesh > components() const;

		private:
			Scene& _scene;

			std::vector< Mesh > _meshes;
			std::unordered_map< Entity::ID, size_t > _indices;

			std::vector< Entity::ID > _markedForDestruction;
			std::unordered_multimap< Ogre::String, Mesh > _pooledMeshes;

			void DestroyAll( Entity::ID entityID ) override;
			void DestroyAllMarked() override;

			void DestroyImmediate( Entity::ID entityID );
		};
	}
}
