#include "exists_in_arg.h"

bool exists_in_arg(int argc, char *argv[], const char *arg) {
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], arg) == 0) {
      return true;
    }
  }

  return false;
}
