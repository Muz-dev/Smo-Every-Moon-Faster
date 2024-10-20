# Info

This is a mario odyssey mod that makes it so that every moon that you collect makes mario faster. you start off at a very slow speed but after you collect moon you will everytually become alot faster than normal. This mod is not finished but it hopefully will be soon.
Thanks to [LynxDev2](https://github.com/LynxDev2) for the base and help with making the mod

# Building

First setup the project

`cmake -S . -B build -G Ninja --toolchain=cmake/toolchain.cmake`

Finally build with

`ninja -C build`

This will build the files into /deploy/subsdk9/




# smo-exlaunch-base-clang
A base project that allows you to create code mods for smo with exlaunch using clang.
This also includes a custom actor factory to allow adding custom actors.

This project uses [Sanae](https://github.com/Sanae6)'s [marsmallow](https://github.com/odyssey-modding/marshmallow) as a base. Marsmallow allows you to make switch mods using clang.

## Original Marshmallow Readme
------------------------------
A clang based version of [exlaunch](https://github.com/shadowninja108/exlaunch/) with some useful built-in tools.
Supporting clang directly allows better integration with IDEs via clangd and various other clang tools.
This project does not depend on the devkitPro switch toolchain.


## Credits
- [shadowninja108](https://github.com/shadowninja108)
  - [exlaunch](https://github.com/shadowninja108/exlaunch)
  - Lots of love <3
- [EngineLessCC](https://github.com/EngineLessCC)
  - [exlaunch-cmake](https://github.com/EngineLessCC/exlaunch-cmake/)
- [CraftyBoss](https://github.com/CraftyBoss)
  - [SMO-Exlaunch-Base](https://github.com/CraftyBoss/SMO-Exlaunch-Base/)
- [Atmosphère contributors](https://github.com/Atmosphere-NX/Atmosphere/graphs/contributors)
  - [Atmosphère](https://github.com/Atmosphere-NX/Atmosphere/)
- [Thog](https://github.com/Thog)
  - [oss-rtld](https://github.com/Thog/oss-rtld)
------------------------------
