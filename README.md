STDEXEC Experiments
===================

This is just a series of small codes to help me understand the design patterns
of [C++ p2300](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2022/p2300r5.html). 

Codes
-----
* [hello/hello.cpp](hello/hello.cpp) - A simple hello world.
* [hello/hello\_deferred.cpp](hello/hello_deferred.cpp) - A simple hello world that attaches to the
  scheduler later.
* [vecadd/vecadd.cpp](vecadd/vecadd.cpp) - A simple vector addition. Set STDEXEC\_NUM\_THREADS to
  vary number of threads used.
