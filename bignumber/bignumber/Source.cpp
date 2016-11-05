#include <string>
#include <bitset>
#include "Source.h"
using namespace std;

#define MASK 0x1

class Int64
{
private:
	bitset<64> value;

	static int* StringToValue(string str);
public:
	Int64();
	Int64(string value);
	Int64 Add(Int64);
	Int64 Substract(Int64);
	Int64 Multiply(Int64);
	string ToString();
	static Int64 StringToInt64(string str);
};

int* Int64::StringToValue(string str)
{
	unsigned int temp[2];
	for (int i = str.size(); i >= 0; --i)
	{

	}


	return 0;
}

Int64::Int64()
{
}

Int64::Int64(string str)
	: Int64()
{
	auto temp = StringToValue(str);
	for (int i = 0; i < 2;++i)
	{
	}
}

Int64 Int64::Add(Int64 B)
{
	int carry = 0;

	for (int i = 0; i < 2; ++i)
	{


	}

	return Int64(*this);
}

Int64 Int64::Substract(Int64)
{
	return Int64();
}

Int64 Int64::Multiply(Int64)
{
	return Int64();
}

string Int64::ToString()
{
	return string();
}

Int64 Int64::StringToInt64(string value)
{
	return Int64();
}
void main()
{
}