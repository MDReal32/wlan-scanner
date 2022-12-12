#include "./get_ifname.h"

char *get_ifname() {
  struct if_nameindex *if_nidxs, *intf;
  if_nidxs = if_nameindex();
  const char *prefix = "wlan";

  if (if_nidxs != NULL) {
    for (intf = if_nidxs; intf->if_index != 0 || intf->if_name != NULL; intf++) {
      char *ifname = intf->if_name;
      if (string_starts_with(ifname, prefix)) {
        return ifname;
      }
    }

    if_freenameindex(if_nidxs);
  }

  return NULL;
}