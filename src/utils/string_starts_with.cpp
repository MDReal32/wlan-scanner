#include "./string_starts_with.h"

bool string_starts_with(char*& str, const char*& prefix) {
  int string_length = strlen(str);
  return string_length >= strlen(prefix) && (strncmp(prefix, str, 4) == 0);
}