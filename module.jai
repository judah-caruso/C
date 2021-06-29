/*
    Due to collisions between types defined in both C and Jai,
    this module MUST be imported with an alias like so:
    
        c :: import "C";
*/

#if OS == .WINDOWS {
    #load "generated_windows.jai";
}
else #if OS == .LINUX {
    #load "generated_linux.jai";
}
else {
    #load "generated_linux.jai";
}