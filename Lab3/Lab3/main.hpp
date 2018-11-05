#pragma once

#include <intrin.h>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

void cpuid_0_test();
void cpuid_1_test();
void cpuid_0x80000000_test();
void cpuid_0x80000001_test();
void cpuid_0x80000002_4_test();

template <class T>
std::string items_to_string(std::initializer_list<T> items, int take_bytes = 4);

const char* get_bit_status(std::bitset<32>::reference bit);