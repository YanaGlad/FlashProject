Flash Project
========================
### Build
```bash
mkdir build
cd build
cmake ../CMakeLists.txt
make
```
### Usage
you should use param `-d` or `--device` to pass path to your device
#### Example
```bash
FlashProject.exe -d <path to device> # e.g. F:/
```
### Contributors
- [Gorlov](https://github.com/gxrlxv) - logging, folder tree creation, uuidv4 generation function.
- [Gusarov](https://github.com/gusarow4321) - work on the main cycle of the program, the file splitting algorithm, file creation and processing, output of the result of the program.
- [Stikentzin](https://github.com/Skijetler) - checking files, working on the main program cycle, documentation, deleting uncorrupted files.
- [Zhukov](https://github.com/Abuzik) - seed and binary sequence generation.
- [Lyakishev](https://github.com/Vasillisska) - creating and processing files.
