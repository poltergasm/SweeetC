#include <sweeet.h>

static void s_load() {}
static void s_tick() {}
static void s_render() {
    s_print("It works!", 64, 64, 1);
}

int main(int argc, char *argv[])
{
    s_window Win = {
        .title = "My Sweeet App",
        .x = S_WINDOW_CENTERED,
        .y = S_WINDOW_CENTERED,
        .w = 800,
        .h = 640,
        .fullscreen = false
    };

    s_init(&Win);
    return 0;
}