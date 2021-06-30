#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef enum {
    Type_Flags_None,
    Type_Flags_Unsigned,
    Type_Flags_Float,
} Type_Flags;

typedef struct {
    char* type_id;
    size_t size;
    Type_Flags flags;
} Type_Description;

typedef struct {
    size_t count;
    Type_Description* list;
} Type_List;

// via: https://en.wikipedia.org/wiki/C_data_types#Main_types
// and: https://en.cppreference.com/w/cpp/language/types#Properties
static Type_Description types[] = {
    // Standard types
    { "char"  , sizeof(char)  , Type_Flags_Unsigned },
    { "short" , sizeof(short) , Type_Flags_None     },
    { "int"   , sizeof(int)   , Type_Flags_None     },
    { "long"  , sizeof(long)  , Type_Flags_None     },
    { "float" , sizeof(float) , Type_Flags_Float    },
    { "double", sizeof(double), Type_Flags_Float    },

    { "short_int"    , sizeof(short int)    , Type_Flags_None  },
    { "long_long"    , sizeof(long long)    , Type_Flags_None  },
    { "long_long_int", sizeof(long long int), Type_Flags_None  },

    // Unsigned types
    { "unsigned_char"         , sizeof(unsigned char)         , Type_Flags_Unsigned },
    { "unsigned_short"        , sizeof(unsigned short)        , Type_Flags_Unsigned },
    { "unsigned_short_int"    , sizeof(unsigned short int)    , Type_Flags_Unsigned },
    { "unsigned"              , sizeof(unsigned)              , Type_Flags_Unsigned },
    { "unsigned_int"          , sizeof(unsigned int)          , Type_Flags_Unsigned },
    { "unsigned_long"         , sizeof(unsigned long)         , Type_Flags_Unsigned },
    { "unsigned_long_long"    , sizeof(unsigned long long)    , Type_Flags_Unsigned },
    { "unsigned_long_long_int", sizeof(unsigned long long int), Type_Flags_Unsigned },

    // Signed types
    { "signed_char"         , sizeof(signed char)         , Type_Flags_None },
    { "signed_short"        , sizeof(signed short)        , Type_Flags_None },
    { "signed_short_int"    , sizeof(signed short int)    , Type_Flags_None },
    { "signed"              , sizeof(signed)              , Type_Flags_None },
    { "signed_int"          , sizeof(signed int)          , Type_Flags_None },
    { "signed_long"         , sizeof(signed long)         , Type_Flags_None },
    { "signed_long_long"    , sizeof(signed long long)    , Type_Flags_None },
    { "signed_long_long_int", sizeof(signed long long int), Type_Flags_None },

    // Extended types
    // @Todo(Judah): Add int_leastX_t, int_fastX_t, and intX_t types?
    { "size_t"   , sizeof(size_t)   , Type_Flags_Unsigned },
    { "intptr_t" , sizeof(intptr_t) , Type_Flags_None     },
    { "uintptr_t", sizeof(uintptr_t), Type_Flags_Unsigned },
    { "ptrdiff_t", sizeof(ptrdiff_t), Type_Flags_Unsigned },
    { "wchar_t"  , sizeof(wchar_t)  , Type_Flags_Unsigned },

    // Platform-specific types
    // @Todo(Judah): Make defines more exhaustive, define more platform-specific types.
    #if defined(__linux__)
    { "ssize_t"    , sizeof(ssize_t), Type_Flags_None  },
    { "long_double", sizeof(double) , Type_Flags_Float }, 
    #endif

    #if defined(_WIN32) 
    { "long_double", sizeof(long double), Type_Flags_Float },
    #endif

    #if defined(__APPLE__)
    #endif
};

#define NUMBER_OF_TYPES sizeof(types) / sizeof(types[0])
static Type_List type_list = { .count = NUMBER_OF_TYPES, .list = types };

#if defined(_WIN32)
    #define DLL_VISIBLE __declspec(dllexport)
#endif

#if defined(__linux__)
    #define DLL_VISIBLE __attribute__((visibility("default")))
#endif

// Workaround until we can bind variables directly
DLL_VISIBLE Type_List get_type_list() { return type_list; }