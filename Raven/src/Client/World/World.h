#pragma once
#include <cstdint>
#include "../Player/Player.h"
#include "../Rendering/Sky.h"
#include <Utilities/Timer.h>
#include "../Chunk/ChunkColumn.h"
#include "../Rendering/Light.h"

namespace Minecraft::Internal{

	using namespace Minecraft::Internal::Chunks;
	struct TimeDataStruct {
		uint64_t age;
		uint64_t timeOfDay;
	};

	class World{
	public:

		World();
		~World();

		void init();
		void cleanup();

		void update();
		void tickUpdate();
		void chunkGenUpdate();
		void draw();

		TimeDataStruct timeData;
		bool is_loading;
		Player* player;
		Rendering::Sky* sky;
		Utilities::Timer timer;
		std::map<mc::Vector3i, ChunkColumn*> chunkMap;
		Rendering::SkyLight* sun;
		unsigned int sun_tex;
		unsigned int dirt_tex;


		Rendering::SkyLight* mun;
		unsigned int mun_tex;
		glm::ivec2 lastPos;
	private:

	};

	extern World* g_World;
}