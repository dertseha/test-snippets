## C++ variant

### Setup

#### Using [CLion](https://www.jetbrains.com/clion/)

Open the project based on `CMakeLists.txt`, run the one of the example tests.

#### On the command-line

To build the project, you need [CMake](http://www.cmake.org/) and a build chain for your platform.

Generate your project files with

```
mkdir build
cd build
cmake ..
```

Then run your build tool with the generated files.

The binary for the unit-tests is called `test-snippets-tests`.

### Further settings

#### Code formatting

Code formatting is configured in `.clang-format`. Either run `clang-format` tool manually, or use IDE integrations such
as those already provided by CLion.

> For JetBrains products, I recommend the plugin "Save Actions" to automate formatting.

#### Documentation

To extract the documentation, use [Doxygen](https://www.doxygen.nl):

```
doxygen doxygen.config
```

The result will be created in the `doc/` sub-folder.
