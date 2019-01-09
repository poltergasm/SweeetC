typedef struct {
	s_image Tiles;
	uint8_t TileHeight;
	uint8_t TileWidth;
	s_quad Quads[MAP_SIZE];
} s_atlas;

typedef struct {
	s_atlas *Atlas;
	uint8_t Data[6];
	void (*Render)();
} s_map;

void s_atlas_generate_quads(s_atlas *atlas, s_map *map)
{
	int w,h;
	uint8_t x,y,rows,cols;
	SDL_QueryTexture(atlas->Tiles.Texture, NULL, NULL, &w, &h);
	/*rows = w / atlas->TileWidth;
	cols = h / atlas->TileHeight;
	for (y = 0; y < cols; y++) {
		for (x = 0; x < rows; x++) {

		}
	}*/
}

void s_map_render(s_map *map)
{
}

void s_map_init(s_map *map, s_atlas *atlas, uint8_t data[])
{
	assert(atlas->TileWidth > 0);
	assert(atlas->TileHeight > 0);
	map->Atlas = atlas;
	s_atlas_generate_quads(atlas, map);
	uint8_t i;
	// turn Data into 2D array from data
	int w,h;
	uint8_t rows,cols;
	SDL_QueryTexture(atlas->Tiles.Texture, NULL, NULL, &w, &h);
	rows = w / atlas->TileWidth;
	cols = h / atlas->TileHeight;
	for (i = 0; i < 6; i++) {
		map->Data[i] = data[i];
	}
}