## Quick Start!
You can find the public Edge Impulse project here:  [Acoustic Sensing of Worker Accidents](https://studio.edgeimpulse.com/public/111611/latest) .  To add this project into your account projects, click “Clone this project”  at the top of the window.

----
## Config build and flash

This project uses the `arduino-cli` compiler to build & flash new firmware. Windows users also need Arduino IDE (tested with v1.8.15).


### Usage - macOS and Linux

The script will verify if all needed libraries and the samd core is installed and install them if needed. If you prefer to do this 
step manually, follow the step in the next chapter.

For building the project:

* For audio support, use:
```
./arduino-build.sh --build
```

* For IMU sensor support, use:
```
./arduino-build.sh --build --with-imu
```


For flashing use:

```
./arduino-build.sh --flash
```


You can also do both by using:
```
./arduino-build.sh --all [--with-imu]
```


### Usage - Windows

* Run `update_libraries_windows.bat` script to install Arduino libraries.
> **Note:** If you are using the Arduino IDE downloaded from the Window Store you need to download the Arduino SAMD BOARDS (32-bits ARM Cortex-M0+) version 1.8.9 manually from the Boards Manager.

* For audio support:

    * Open the `firmware-syntiant-tinyml.ino` with the Arduino IDE.
    * Select MKRZero as board target and compile/upload.

* For IMU sensor support:
    * Open the `src/syntiant.cpp` file and uncomment the following line:
    ```
    //#define WITH_IMU
    ```
    * Open the `firmware-syntiant-tinyml.ino` with the Arduino IDE.
    * Select MKRZero as board target and compile/upload.

### Usage - Different classes

You can use this repository to build custom firmware for any Syntiant audio project. From Edge Impulse Studio, deploy your impulse as Syntiant NDP101 library. 

This will create an output zip that contains a model-parameters folder that contains dsp_blocks.h and model_metadata.h that you will need to copy to `src/model-parameters` folder.

>**Note:** In the model_variables.h file of your library, ensure `ei_model_types.h` is included using the path `#include "../edge-impulse-sdk/classifier/ei_model_types.h"`

Afterwards follow the usage instructions described above.

---
## Acknowledgement

This custom firmware repository is built from Edge Impulse firmware for Syntiant TinyML board.

Official repository is here [firmware-syntiant-tinyml](https://github.com/edgeimpulse/firmware-syntiant-tinyml)