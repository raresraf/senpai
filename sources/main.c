/*
 * main.c
 *
 * Licensed under MIT license
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "universe.h"
#include "args.h"
#include "text.h"
#include "util.h"

int main(int argc, char **argv)
{
  universe_t universe;
  args_t args;
  int exit_state;

  srand((unsigned int)time(NULL));
  args_init(&args);
  if (args_parse(&args, argc, argv) == NULL)
    return (retstri(EXIT_FAILURE, TEXT_MAIN_FAILURE, __FILE__, __LINE__));
  if (universe_init(&universe, &args) == NULL)
    return (retstri(EXIT_FAILURE, TEXT_MAIN_FAILURE, __FILE__, __LINE__));

  printf(TEXT_SIMSTART, universe.part_nb, args.max_time*1E12, args.timestep*1E12);
  exit_state = universe_simulate(&universe, &args);
  printf(TEXT_SIMEND, universe.iterations);

  universe_clean(&universe);
  return (exit_state);
}
