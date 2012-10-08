#ifndef INCLUDED_PROFILING_H_
#define INCLUDED_PROFILING_H_

#include <iostream>
#include <string>

using namespace std;

size_t fun(string value);
size_t fun2(string const &value);
size_t callFun(string const &prog);   // calls fun 10,000,000 times
size_t callFun2(string const &prog);  // calls fun2 10,000,000 times

#endif