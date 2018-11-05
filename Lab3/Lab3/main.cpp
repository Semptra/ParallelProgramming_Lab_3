#include "main.hpp"

int main()
{
	cpuid_0_test();
	cpuid_1_test();
	cpuid_0x80000000_test();
	cpuid_0x80000001_test();
	cpuid_0x80000002_4_test();

	std::cout << std::endl;

	system("Pause");

	return 0;
}

void cpuid_0_test()
{
	int result[4];

	std::cout << "__cpuid(0)" << std::endl;

	__cpuid(result, 0);

	std::cout << "Highest function supported: " << result[0] << std::endl;
	std::cout << "Manufacturer ID: " << items_to_string({ result[1], result[3], result[2] }) << std::endl;
	std::cout << std::endl;
}

void cpuid_1_test()
{
	int result[4];

	std::cout << "__cpuid(1)" << std::endl;

	__cpuid(result, 1);

	auto bits = std::bitset<32>(result[2]);

	std::cout << "sse3 - " << get_bit_status(bits[0]) << std::endl;
	std::cout << "pclmulqdq - " << get_bit_status(bits[1]) << std::endl;
	std::cout << "dtes64 - " << get_bit_status(bits[2]) << std::endl;
	std::cout << "monitor - " << get_bit_status(bits[3]) << std::endl;
	std::cout << "ds-cpl - " << get_bit_status(bits[4]) << std::endl;
	std::cout << "vmx - " << get_bit_status(bits[5]) << std::endl;
	std::cout << "smx - " << get_bit_status(bits[6]) << std::endl;
	std::cout << "est - " << get_bit_status(bits[7]) << std::endl;
	std::cout << "tm2 - " << get_bit_status(bits[8]) << std::endl;
	std::cout << "cnxt-id - " << get_bit_status(bits[9]) << std::endl;
	std::cout << "sdbg - " << get_bit_status(bits[10]) << std::endl;
	std::cout << "fma - " << get_bit_status(bits[11]) << std::endl;
	std::cout << "cx16 - " << get_bit_status(bits[12]) << std::endl;
	std::cout << "xtpr - " << get_bit_status(bits[13]) << std::endl;
	std::cout << "pdcm - " << get_bit_status(bits[14]) << std::endl;
	std::cout << "pcid - " << get_bit_status(bits[16]) << std::endl;
	std::cout << "dca - " << get_bit_status(bits[17]) << std::endl;
	std::cout << "sse4.1 - " << get_bit_status(bits[18]) << std::endl;
	std::cout << "sse4.2 - " << get_bit_status(bits[19]) << std::endl;
	std::cout << "x2apic - " << get_bit_status(bits[20]) << std::endl;
	std::cout << "movbe - " << get_bit_status(bits[21]) << std::endl;
	std::cout << "popcnt - " << get_bit_status(bits[22]) << std::endl;
	std::cout << "tsc-deadline - " << get_bit_status(bits[23]) << std::endl;
	std::cout << "aes - " << get_bit_status(bits[24]) << std::endl;
	std::cout << "xsave - " << get_bit_status(bits[25]) << std::endl;
	std::cout << "osxsave - " << get_bit_status(bits[26]) << std::endl;
	std::cout << "avx - " << get_bit_status(bits[27]) << std::endl;
	std::cout << "f16c - " << get_bit_status(bits[28]) << std::endl;
	std::cout << "rdrnd - " << get_bit_status(bits[29]) << std::endl;
	std::cout << "hypervisor - " << get_bit_status(bits[30]) << std::endl;

	std::cout << std::endl;
}

void cpuid_0x80000000_test()
{
	int result[4];

	std::cout << "__cpuid(0x80000000)" << std::endl;

	__cpuid(result, 0x80000000);

	auto bits = std::bitset<32>(result[3]);

	std::cout << "3DNow! (AMD) - " << get_bit_status(bits[31]) << std::endl;;
	std::cout << "3DNow!2 (AMD) - " << get_bit_status(bits[30]) << std::endl;;
	std::cout << std::endl;
}

void cpuid_0x80000001_test()
{
	int result[4];

	std::cout << "__cpuid(0x80000001)" << std::endl;

	__cpuid(result, 0x80000001);

	auto bits = std::bitset<32>(result[2]);

	std::cout << "SSE4A - " << get_bit_status(bits[6]) << std::endl;
	std::cout << "SSE5 - " << get_bit_status(bits[11]) << std::endl;
	std::cout << std::endl;
}

void cpuid_0x80000002_4_test()
{
	int result[4];

	std::cout << "__cpuid(0x80000002 - 0x80000004)" << std::endl;
	std::cout << "Processor Brand: ";

	for (int i = 0x80000002; i <= 0x80000004; i++)
	{
		__cpuid(result, i);

		std::cout << items_to_string({ result[0], result[1], result[2], result[3] });
	}

	std::cout << std::endl;
}

template <class T>
std::string items_to_string(std::initializer_list<T> items, int take_bytes)
{
	std::ostringstream oss("");

	for (auto item : items)
	{
		oss << std::string((const char *)&item, take_bytes);
	}

	return oss.str();
}

const char* get_bit_status(std::bitset<32>::reference bit)
{
	if (bit)
	{
		return "Supported";
	}
	else
	{
		return "Not supported";
	}
}