# C

Jai->C data types for use in bindings.

# Usage

Identifiers are 1:1 with C with the addition of underscores instead of spaces.
This means editor macros should be able to auto-translate the types for you.

```c
unsigned long long does_something(char* x);
unsigned long long int another_thing(short y);
```

```c++
c :: #import "C";

Library :: #foreign_library "something";

does_something :: (x: *c.char) -> c.unsigned_long_long #foreign Library;
another_thing  :: (y: c.short) -> c.unsigned_long_long_int #foreign Library;
```

# License

MIT
