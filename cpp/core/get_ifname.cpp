#include "./get_ifname.h"

string prefix = "wlan";

string get_ifname() {
  struct if_nameindex *if_nidxs, *intf;
  if_nidxs = if_nameindex();

  if (if_nidxs != nullptr) {
    for (intf = if_nidxs; intf->if_index != 0 || intf->if_name != nullptr; intf++) {
      string ifname = intf->if_name;

      if (ifname.find(prefix) != string::npos) {
        if_freenameindex(if_nidxs);
        return ifname;
      }
    }

    if_freenameindex(if_nidxs);
  }

  return {};
}