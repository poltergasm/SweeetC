
typedef struct {
	uint32_t x;
	uint32_t y;
	uint8_t Tick;
	uint8_t Frame;
	uint8_t Step;
	uint8_t StateNums[MAX_STATES];
    s_quad Anim[MAX_STATES][MAX_STATES];
	int8_t State;
	s_quad Sprite;
	s_image Image;
} s_entity;

typedef struct {
	s_entity *entities[250];
	void (*add)(s_entity *ent);
	void (*tick)();
	uint8_t num_ents;
} _s_ent_mgr;

_s_ent_mgr s_ent_mgr;

void s_ent_mgr_add(s_entity *ent)
{
	uint8_t y,x,sz,state;
	for (y = 0; y < MAX_STATES; y++) {
        state = y;
        sz = 0;
		for (x = 0; x < MAX_STATES; x++) {
			if (ent->Anim[y][x].h != 0) {
                sz++;
			}
		}
		ent->StateNums[state] = sz;
	}

    s_ent_mgr.entities[s_ent_mgr.num_ents] = ent;
	s_ent_mgr.num_ents++;
}

void s_ent_mgr_tick()
{
	uint8_t i;
	for (i = 0; i < s_ent_mgr.num_ents; i++) {
        s_entity *ent = s_ent_mgr.entities[i];
		if (ent->Step != 0) {
			ent->Tick = (ent->Tick+1) % ent->Step;
			if (ent->Tick == 0) {
				ent->Frame = ent->Frame % ent->StateNums[ent->State] +1;
				ent->Sprite = ent->Anim[ent->State][ent->Frame-1];
			}
		}
	}
}

void s_ent_mgr_init()
{
	s_ent_mgr.num_ents = 0;
    s_ent_mgr.add = &s_ent_mgr_add;
    s_ent_mgr.tick = &s_ent_mgr_tick;
}
