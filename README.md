# Debug Profile

Macros used for performance analysis of C++ code. Compile with the symbol `ENABLE_PROFILING` to enable.

The macros included in this library can track the performance times for either entire functions or specific blocks of code.

This was inspired by the article:

Hjelstrom, Greg, and Byon Garrabrant. "Real-Time Hierarchical Profiling." *Game Programming Gems 3*, Charles River Media, 2002, pp 146-152.

## Features

The benefits of this library over other profiling tools are:

- Performance times are only collected on the sections of code that you specify. This is useful for when you are only interested
  in reviewing certain sections of code, rather than the entire codebase.
- Along with collecting function times (`PROFILE()`), specific blocks of code can also be tracked (`PROFILE_SECTION_START()`).
- When a section of code that is being profiled calls another profiled code block, then the first block will be paused. This will
  thus only show the time it took to execute the code in the initial block, excluding the time it took to call any subsequent blocks
  that are also being tracked. This is an important distinction from other profiling systems.
    
Profiling information will be written to standard output and a specified file (`SET_PROFILER_REPORT_PATH()`).

## Building

Include the files `debug_profile.cpp` and `debug_profile.h` in your project and use the macros as shown in the [example](#example).

## Building the Help

For full documentation, open the file `Doxyfile` in [Doxygen](https://github.com/doxygen/doxygen) and run it.

## Example {#example}

```cpp
int main()
    {
    SET_PROFILER_REPORT_PATH("c:\\temp\\profile.csv"); // optionally write to log file
    otherFunction();
    complexFunction();
    return 0; // profiler will now dump its results to the log file and standard out
    }

void otherFunction()
    {
    PROFILE();
    ...code
    }

void complexFunction()
    {
    some code...

    PROFILE_SECTION_START("complex function subsection");
    ...possible bottleneck code being profiled
    PROFILE_SECTION_END();

    more code...
    }
```

