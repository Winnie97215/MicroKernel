/*
** print_u.c for my_printf in /home/klarma_n//work/systeme_unix/my_printf/print
** 
** Made by nicolas klarman
** Login   <klarma_n@epitech.net>
** 
** Started on  Fri Nov 18 11:22:34 2011 nicolas klarman
** Last update Fri Nov 18 22:18:45 2011 nicolas klarman
*/

#include "stdlib.h"
#include "printf.h"

int	print_u(va_list *ap)
{
  return (put_nbr_base_u(va_arg(*ap, unsigned int), "0123456789"));
}
