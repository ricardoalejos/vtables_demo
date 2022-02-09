# Demostration of the virtual tables in C

## Introduction

Virtual tables contain a set of functions that compose an interface.

In this example project, we create a `switchable` interface which contains two functions: `switchable_turn_on()` and `switchable_turn_off()`. Then, we create a concrete implementation for `lamp` objects. Finally, we create an application in which we create a `lamp` and run its `switchable` implementation.

## Build instructions

```
# 1. Setup the build environment
source setenv.sh
# 2. Delete any artifacts from a past build (if any)
vtables_clean
# 3. Let the build scripts find all source files and configure the project
vtables_configure
# 4. Run the build
vtables_build
```

When the build is done, the demo appliation should become available in the out/bin subdirectory.

## Virtual tables versus straight function addition

Virtual tables (Listing 2) are an alternative technique to the inclusion of the function pointers straight in each instance of the appliation objects (Listing 1). They require more code, but they save some memory.

```c
struct my_class {
    void(*method_1)(struct my_class * self);
    void(*method_2)(struct my_class * self);
    void(*method_3)(struct my_class * self);
    void * data;
};
```

**Listing 1**. Each instance of my_class will have a reference to each one of its methods.

```c
struct my_class_methods;  // Forward declaration of the vtable

struct my_class {
    struct my_class_methods * implementation;
    void * data;
};

struct my_class_methods {
    void(*method_1)(struct my_class * self);
    void(*method_2)(struct my_class * self);
    void(*method_3)(struct my_class * self);
};
```

**Listing 2**. Only one copy of my_class_methods is necessary. Although we had to write a bit more code.

## Interface definition recipe

We have defined the example interface `switchable` in source/switchable. It only consists of one header file. And such header file contains the following sections:

1. **Base definitions**. These include an abstract type definiton of the objects that satisfy the interface (like `typedef struct x_s x_t`), and an enumeration of relevant error codes.
2. **Implementer's definitions**. These are useful for implementer modules. Those are the ones creating concrete instances of the interface.
3. **Application's definitions**. These are intended to be used by the application. Ideally, the application should only use the base and the application definitions.

The application definitions contain a set of `static inline` functions. Using these, the application can hide the redirections to the interface implementations. In consequence, the interface module can be swapped by any other alternate implementation that defines the same abstract datatype and function prototypes (reduces coupling between the application and the module).
