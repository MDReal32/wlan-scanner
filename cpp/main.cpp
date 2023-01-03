#include <iostream>

#include "utils/exists_in_arg.h"
#include "core.h"

using namespace std;

int main(int argc, char *argv[]) {
  bool is_dev_mode = exists_in_arg(argc, argv, "--dev");
  bool is_json_mode = exists_in_arg(argc, argv, "--json");

  string data = get_data(is_dev_mode, is_json_mode);
  cout << data << endl;

  return 0;
}
