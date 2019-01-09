#ifndef _SWEEET_H_
#define _SWEEET_H_

#include <stdio.h>
#define SDL_DISABLE_IMMINTRIN_H
#include <SDL.h>
#include <SDL_Image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdarg.h>
#include <stdbool.h>
#include <assert.h>


#define S_WINDOW_CENTERED SDL_WINDOWPOS_CENTERED
#define MAX_PALETTES 8
#define MAX_COLORS 32
#define MAX_TEXTURES 256
#define MAX_MUSIC 50
#define MAX_SFX 100
#define MAX_SOUNDS MAX_MUSIC + MAX_SFX
#define MAX_STATES 15
#define MAP_SIZE 181

static void s_load();
static void s_tick();
static void s_render();

typedef struct {
	bool Running;
	int Palette;
	SDL_Window *Window;
	SDL_Renderer *Renderer;
	TTF_Font *Font;
} sweeetEngine;

sweeetEngine sweeet = {false, 0, NULL};

#include "events.h"
#include "core.h"
#include "palette.h"
#include "ecm.h"
#include "map.h"
#include "init.h"
#include "audio.h"
#include "input.h"
#include "render.h"

#endif