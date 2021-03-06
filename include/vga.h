#ifndef VGA_H
#define VGA_H

#include "kernel.h"

#define VGA_BUFFER_BASE_MODE ((uint16_t*) 0x000B8000)
#define VGA_BUFFER_MODE (0xB8000 + 160)
#define MICRO_CHAR 6

#define MAKE_COLOR(fg, bg) (((fg) & 0x0F) | (((bg) & 0x0F) << 4))
#define MAKE_VGAENTRY(c, color) ((c) | ((color) << 8))

typedef enum e_vga_color
  {
    COLOR_BLACK = 0,
    COLOR_BLUE = 1,
    COLOR_GREEN = 2,
    COLOR_CYAN = 3,
    COLOR_RED = 4,
    COLOR_MAGENTA = 5,
    COLOR_BROWN = 6,
    COLOR_LIGHT_GREY = 7,
    COLOR_DARK_GREY = 8,
    COLOR_LIGHT_BLUE = 9,
    COLOR_LIGHT_GREEN = 10,
    COLOR_LIGHT_CYAN = 11,
    COLOR_LIGHT_RED = 12,
    COLOR_LIGHT_MAGENTA = 13,
    COLOR_LIGHT_BROWN = 14,
    COLOR_WHITE = 15,
  } vga_color;

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 24;
static const vga_color fg_default_color = COLOR_LIGHT_GREEN;
static const vga_color bg_default_color = COLOR_BLACK;

typedef struct s_console
{
  size_t terminal_row;
  size_t terminal_column;
  uint8_t terminal_color;
  uint16_t* terminal_buffer;
} vga_terminal;

vga_terminal *get_terminal_instance();

void     terminal_clear_buffer(vga_terminal *pterm);
void     terminal_initialize(vga_terminal *pterm);
void     terminal_initialize_with_color(vga_terminal *pterm, vga_color fg, vga_color bg);
void     terminal_setcolor(vga_terminal *pterm, vga_color fg, vga_color bg);
int     terminal_put_vgaentry_at(vga_terminal *pterm, uint32_t c, vga_color color, size_t x, size_t y);
int     terminal_putchar(vga_terminal *pterm, uint32_t c);
int     terminal_putchar_with_color(vga_terminal *pterm, uint32_t c);
int     terminal_putstr(vga_terminal *pterm, const char *str);
int	terminal_putstrn(vga_terminal *pterm, const char* data, int n);
int     terminal_putstr_with_color(vga_terminal *pterm, const char *str);
void     printk(int color, char *str);
void     printkc(int color, char c);
void     scrollup(vga_terminal *pterm, uint8_t n);
void     printTaskBar(vga_terminal *pterm);
void	 terminal_show_cursor(vga_terminal *pterm);

#endif
