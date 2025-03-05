#include <stdio.h>
#include "olive.c"
#include <stdint.h>
#include <string.h>
#include <errno.h>

#define WIDTH 800
#define HEIGHT 600

static uint32_t pixels[HEIGHT*WIDTH];

int main(void)
{
    olivec_fill(pixels, WIDTH, HEIGHT, 0xFF00FF00);
    const char *file_path = "../output.ppm";
    Errno err = olivec_save_to_ppm_file(pixels, WIDTH, HEIGHT, file_path);
    if (err) {
        fprintf(stderr, "ERROR: could not save file %s: %s\n", file_path, strerror(errno));
        return -1;
    }
    return 0;
}
