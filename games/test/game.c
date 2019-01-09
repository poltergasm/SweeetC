#include <sweeet.h>

typedef struct {
    union {
        s_entity ent;
    } base;
} blob_s;

blob_s enemy_blob;

static void s_load() {
    enemy_blob.base.ent.x = 112;
    enemy_blob.base.ent.y = 112;
    enemy_blob.base.ent.Step = 7;
    enemy_blob.base.ent.Image = s_load_image("assets/blob.png");
    enemy_blob.base.ent.Anim[0][0] = s_new_quad(0, 0, 48, 48);
    enemy_blob.base.ent.Anim[0][1] = s_new_quad(0, 48, 48, 48);

    s_ent_mgr.add(&enemy_blob.base.ent);
}

static void s_tick() { s_ent_mgr.tick(); }

static void s_render() {
    s_print("It works!", 64, 64, 1);
    s_draw_quad(
        enemy_blob.base.ent.Image,
        enemy_blob.base.ent.x,
        enemy_blob.base.ent.y,
        false,
        enemy_blob.base.ent.Sprite);
}

int main(int argc, char *argv[])
{
    s_window Win = {
        .title = "Sweeet Demo",
        .x = S_WINDOW_CENTERED,
        .y = S_WINDOW_CENTERED,
        .w = 480,
        .h = 384,
        .fullscreen = false
    };

    s_init(&Win);
    return 0;
}
