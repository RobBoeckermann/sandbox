# Effective C++ (Third Edition) - Scott Meyers

## prefer explicit constructor declarations 

- to prevent unintented implicit type conversions.

## prefer pass-by-reference-to-const to pass-by-value

- to avoid unnecessary copy constructors and destructors.
- to avoid slicing off derived features when the base copy constuctor is called.
- (this does not apply to built-in types and STL iterator and function object types)

## prefer the compiler (const, enum, inline) to the preprocessor (#define)

## use const whenever possible

## always initialize objects

- make sure that all constructors initialize everything in the object using member initialization:

```
TestClass::TestClass(std::string& name)
: theName(name),
  theGame()
{}
```
instead of assignments:

```
TestClass::TestClass(std::string& name) {
    theName = name;
}
```
to avoid assigning the value twice (once in the default constructor and again in the assignment).

While not always needed, it's easier to always use the initialization list for all members.

## the relative order of initialization of non-local static objects defined in different translation units is undefined

this problem is solved by moving each non-local static object into its own function, where it's declared static. These functions return references to the objects they contain:

```
FileSystem& tfs() {
    static FileSystem fs;
    return fs;
}
```

in multithreaded applications, this approach could cause initialization-related race conditions. this can be solved by manually invoking all the reference-returning functions during the single-threaded startup portion of the program.


