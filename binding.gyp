{
  "targets": [
    {
      "target_name": "wlan_scanner",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "./cpp/index.cpp",
        "./cpp/core.cpp",
        "./cpp/core/get_ifname.cpp",
        "./cpp/core/scan_wireless_network.cpp",
        "./cpp/helpers/wifi_access_point.cpp",
      ],
      'include_dirs': [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "libraries": [
        "-liw"
      ],
      "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ],
    }
  ]
}