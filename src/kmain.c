#include "vga.h"
#include "mylib.h"

void kmain()
{
  vga_terminal *pterm = get_terminal_instance();
  terminal_initialize(pterm);

  printk(2,"Mikro\n");
  printk(3,"     is\n");
  printk(4,"       the\n");
  printk(5,"          best\n");
  printk(6,"              kernel\n");
}
