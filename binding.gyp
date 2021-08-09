{
  "targets": [
    {
      "target_name": "wpi-node",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [ "wpi-node.cc" ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        'WiringPi/wiringPi',
        'WiringPi/devLib',
        '/usr/local/include'
      ],
      'ldflags':['-lwiringPi'],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}
