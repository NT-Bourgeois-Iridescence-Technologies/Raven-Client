#include "ChunkColumn.h"
#include <iostream>

namespace Minecraft::Internal::Chunks {
	ChunkColumn::ChunkColumn(int x, int z)
	{
		cX = x;
		cZ = z;

		sections.clear();

		for (int xx = 0; xx < CHUNK_SECTION_LENGTH; xx++) {
			for (int yy = 0; yy < CHUNK_SECTION_LENGTH; yy++) {
				biomes[xx][yy] = 1;
			}
		}
	}

	ChunkColumn::~ChunkColumn()
	{
		for (auto chnk : sections) {
			delete chnk;
		}
	}

	ChunkSection* ChunkColumn::getSection(uint8_t y)
	{
		for (auto chnk : sections) {
			if (chnk->getY() == y) {
				return chnk;
			}
		}
		return NULL;
	}

	void ChunkColumn::addSection(ChunkSection* chnks)
	{
		chnks->cX = cX;
		chnks->cZ = cZ;

		if (chnks->isEmpty()) {
			delete chnks;
		}
		else {
			sections.push_back(chnks);
		}

	}

	void ChunkColumn::clearSections()
	{
		for (auto chnk : sections) {
			delete chnk;
		}
		sections.clear();
	}

}