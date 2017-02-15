#pragma once

using Bit = bool;
using Boolean = Bit;

using Byte1 = signed char;
using Byte2 = signed short;
using Byte4 = signed long;
using Byte8 = signed long long;

using uByte1 = unsigned char;
using uByte2 = unsigned short;
using uByte4 = unsigned long;
using uByte8 = unsigned long long;

using SizeType = uByte4;	//size_t

template<class T, T min, T max> class ScopingType
{
	T value;

public:
	ScopingType(T value)
		{
			if (value > max)
				this->value = max;
			else if (value < min)
				this->value = min;
			else this->value = value;
		}
	operator T()
	{
		return value;
	}
};