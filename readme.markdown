# C

Auto-generated types to make binding C code easier while preserving the semantics of the original code.


# Usage (Module)

Identifiers are almost 1:1 with C, only replacing spaces with underscores.

```c++
// Jai:
c :: #import "C";

SomeLib :: #foreign_library "somelib";
does_something :: (x: *c.char) -> c.unsigned_long_long     #foreign SomeLib;
another_thing  :: (y: c.short) -> c.unsigned_long_long_int #foreign SomeLib;

// C:
unsigned long long does_something(char* x);
unsigned long long int another_thing(short y);
```


# Usage (Static)

If you don't want to use the module version of this, you can simply copy
`generated_static.jai` into your project's directory and #load it. 

```c++
// Jai:
#load "c.jai"; // Renaming generated_static.jai to c.jai or similar is recommended.

lib :: #foreign_library "lib";
greet :: (name: *c.char) -> *c.char #foreign lib;

// C:
char* greet(const char* name);
```


# Building

Module dependent files can be generated by calling `jai generator/generate.jai`.
Note, the generator script requires `generator/sizes.c` to be compiled into a 
dynamic/shared library. This can be done by running the `build.bat/build.sh`
scripts within `generator/`.

Generating the static version of the module requires at least one of the other generated files. You can simply call `jai generator/generate_static.jai`. This
will create a `generated_static.jai` file.


# License

zlib

If this is not permissive enough let me know and I will change it.