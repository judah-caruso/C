/*
    Due to collisions between types defined in both C and Jai,
    this module MUST be imported with an alias like so:
    
        c :: import "C";
*/

#scope_module;

#if OS == .WINDOWS {
    #load "generated_windows.jai";
    #assert(size_of(uintptr_t) >= size_of(u32), "uintptr_t was defined with an incorrect size: %%", size_of(uintptr_t));
    #assert(size_of(long_double) >= size_of(double), "long double was defined with an incorrect size: %%!", size_of(long_double));
}
else #if OS == .LINUX {
    #load "generated_linux.jai";
}
else {
    #load "generated_linux.jai";
}