#include"barray.h"

// ********** barry **********

// ---------- 构造、析构函数 ----------
x::barray::barray() noexcept :ba(0x00), t(0)
{}

x::barray::barray(barray const& origin_barray)
{
	if (origin_barray.t == 0)
	{
		t = 0;
		ba = 0x00;
		return;
	}
	t = origin_barray.t;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < t; ++i)
		ba[i] = origin_barray.ba[i];
}

x::barray::barray(int const& array_length, unsigned char const& value)
{
	if (array_length <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	t = array_length;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < t; ++i)
		ba[i] = value;
}

x::barray::~barray()
{
	if (t > 0)
		delete[]ba;
	ba = 0x00;
	t = 0;
}

// ----- 数组初始化 -----
x::barray::barray(std::string const& origin_string)
{
	if (origin_string.length() == 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	if (origin_string.length() > INT_MAX)
		t = INT_MAX;
	else
		t = origin_string.length();
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < t; ++i)
		ba[i] = origin_string[i];
}

x::barray::barray(char const* const origin_char, int const& origin_char_len)
{
	if (origin_char_len <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	t = origin_char_len;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	try
	{
		for (int i = 0; i < t; ++i)
			ba[i] = origin_char[i];
	}
	catch (std::exception &e)
	{
		delete[]ba;
		t = 0;
		ba = 0x00;
		throw(e);
	}
}

x::barray::barray(unsigned char const* const origin_uchar, int const& origin_uchar_len)
{
	if (origin_uchar_len <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	t = origin_uchar_len;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	try
	{
		for (int i = 0; i < t; ++i)
			ba[i] = origin_uchar[i];
	}
	catch (std::exception &e)
	{
		delete[]ba;
		t = 0;
		ba = 0x00;
		throw(e);
	}
}

x::barray::barray(bool const* const origin_bool, int const& origin_bool_len)
{
	if (origin_bool_len <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	t = origin_bool_len;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	try
	{
		for (int i = 0; i < t; ++i)
			if (origin_bool[i])
				ba[i] = 1;
			else
				ba[i] = 0;
	}
	catch (std::exception &e)
	{
		delete[]ba;
		t = 0;
		ba = 0x00;
		throw(e);
	}
}

x::barray::barray(short const* const origin_short, int const& origin_short_len)
{
	if (origin_short_len <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	if (origin_short_len > INT_MAX / 2)
		t = INT_MAX - 1;
	else
		t = origin_short_len * 2;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i, j;
	try
	{
		for (i = 0; i < t / 2; ++i)
			for (j = 0; j < 2; ++j)
				ba[i * 2 + j] = origin_short[i] >> j * 8;
	}
	catch (std::exception &e)
	{
		delete[]ba;
		t = 0;
		ba = 0x00;
		throw(e);
	}
}

x::barray::barray(unsigned short const* const origin_ushort, int const& origin_ushort_len)
{
	if (origin_ushort_len <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	if (origin_ushort_len > INT_MAX / 2)
		t = INT_MAX - 1;
	else
		t = origin_ushort_len * 2;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i, j;
	try
	{
		for (i = 0; i < t / 2; ++i)
			for (j = 0; j < 2; ++j)
				ba[i * 2 + j] = origin_ushort[i] >> j * 8;
	}
	catch (std::exception &e)
	{
		delete[]ba;
		t = 0;
		ba = 0x00;
		throw(e);
	}
}

x::barray::barray(int const* const origin_int, int const& origin_int_len)
{
	if (origin_int_len <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	if (origin_int_len > INT_MAX / 4)
		t = INT_MAX - 3;
	else
		t = origin_int_len * 4;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i, j;
	try
	{
		for (i = 0; i < t / 4; ++i)
			for (j = 0; j < 4; ++j)
				ba[i * 4 + j] = origin_int[i] >> j * 8;
	}
	catch (std::exception &e)
	{
		delete[]ba;
		t = 0;
		ba = 0x00;
		throw(e);
	}
}

x::barray::barray(unsigned int const* const origin_uint, int const& origin_uint_len)
{
	if (origin_uint_len <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	if (origin_uint_len > INT_MAX / 4)
		t = INT_MAX - 3;
	else
		t = origin_uint_len * 4;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i, j;
	try
	{
		for (i = 0; i < t / 4; ++i)
			for (j = 0; j < 4; ++j)
				ba[i * 4 + j] = origin_uint[i] >> j * 8;
	}
	catch (std::exception &e)
	{
		delete[]ba;
		t = 0;
		ba = 0x00;
		throw(e);
	}
}

x::barray::barray(long long const* const origin_long, int const& origin_long_len)
{
	if (origin_long_len <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	if (origin_long_len > INT_MAX / 8)
		t = INT_MAX - 7;
	else
		t = origin_long_len * 8;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i, j;
	try
	{
		for (i = 0; i < t / 8; ++i)
			for (j = 0; j < 8; ++j)
				ba[i * 8 + j] = origin_long[i] >> j * 8;
	}
	catch (std::exception &e)
	{
		delete[]ba;
		t = 0;
		ba = 0x00;
		throw(e);
	}
}

x::barray::barray(unsigned long long const* const origin_ulong, int const& origin_ulong_len)
{
	if (origin_ulong_len <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	if (origin_ulong_len > INT_MAX / 8)
		t = INT_MAX - 7;
	else
		t = origin_ulong_len * 8;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i, j;
	try
	{
		for (i = 0; i < t / 8; ++i)
			for (j = 0; j < 8; ++j)
				ba[i * 8 + j] = origin_ulong[i] >> j * 8;
	}
	catch (std::exception &e)
	{
		delete[]ba;
		t = 0;
		ba = 0x00;
		throw(e);
	}
}

// ----- 单个数据类型初始化 -----
x::barray::barray(bool, char const& origin_char)
{
	t = 1;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	ba[0] = origin_char;
}

x::barray::barray(bool, unsigned char const& origin_uchar)
{
	t = 1;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	ba[0] = origin_uchar;
}

x::barray::barray(bool, bool const& origin_bool)
{
	t = 1;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	if (origin_bool)
		ba[0] = 1;
	else
		ba[0] = 0;
}

x::barray::barray(bool, short const& origin_short)
{
	t = 2;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < 2; ++i)
		ba[i] = origin_short >> i * 8;
}

x::barray::barray(bool, unsigned short const& origin_ushort)
{
	t = 2;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < 2; ++i)
		ba[i] = origin_ushort >> i * 8;
}

x::barray::barray(bool, int const& origin_int)
{
	t = 4;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < 4; ++i)
		ba[i] = origin_int >> i * 8;
}

x::barray::barray(bool, unsigned int const& origin_uint)
{
	t = 4;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < 4; ++i)
		ba[i] = origin_uint >> i * 8;
}

x::barray::barray(bool, long long const& origin_long)
{
	t = 8;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < 8; ++i)
		ba[i] = origin_long >> i * 8;
}

x::barray::barray(bool, unsigned long long const& origin_ulong)
{
	t = 8;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < 8; ++i)
		ba[i] = origin_ulong >> i * 8;
}

// ---------- 功能函数 ----------
bool x::barray::set_length(int const& array_length, unsigned char const& value)
{
	if (array_length < 0)
		return false;
	if (t == array_length)
	{
		for (int i = 0; i < t; ++i)
			ba[i] = value;
		return true;
	}
	else if (t == 0)
	{
		t = array_length;
		try
		{
			ba = new unsigned char[t];
		}
		catch (std::exception& e)
		{
			t = 0;
			ba = 0x00;
			throw(e);
		}
		for (int i = 0; i < t; ++i)
			ba[i] = value;
		return true;
	}
	else if (array_length == 0)
	{
		delete[]ba;
		t = 0;
		ba = 0x00;
		return true;
	}
	delete[]ba;
	t = array_length;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < t; ++i)
		ba[i] = value;
	return true;
}

int x::barray::get_length() const noexcept
{
	return t;
}

void x::barray::clear() noexcept
{
	delete[]ba;
	t = 0;
	ba = 0x00;
}

// ---------- 重载运算符 ----------
// ----- operator[]重载 -----
unsigned char& x::barray::operator[](int const& num) const
{
	if (num < 0 || num >= t)
		throw(index_error("Index out of range!"));
	return ba[num];
}

// ----- operator=重载 -----
x::barray& x::barray::operator=(x::barray const& right_barray)
{
	if (this == &right_barray)
		return *this;
	if (t != 0 && t != right_barray.t)
		delete[]ba;
	if (right_barray.t == 0)
	{
		t = 0;
		ba = 0x00;
		return *this;
	}
	if (t != right_barray.t)
	{
		t = right_barray.t;
		try
		{
			ba = new unsigned char[t];
		}
		catch (std::exception& e)
		{
			t = 0;
			ba = 0x00;
			throw(e);
		}
	}
	for (int i = 0; i < t; ++i)
		ba[i] = right_barray.ba[i];
	return *this;
}

x::barray& x::barray::operator=(char const& right_char)
{
	if (t > 1)
		delete[]ba;
	if (t == 1)
	{
		ba[0] = right_char;
		return *this;
	}
	t = 1;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	ba[0] = right_char;
	return *this;
}

x::barray& x::barray::operator=(unsigned char const& right_uchar)
{
	if (t > 1)
		delete[]ba;
	if (t == 1)
	{
		ba[0] = right_uchar;
		return *this;
	}
	t = 1;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	ba[0] = right_uchar;
	return *this;
}

x::barray& x::barray::operator=(bool const& right_bool)
{
	if (t > 1)
		delete[]ba;
	if (t == 1)
	{
		if (right_bool)
			ba[0] = 1;
		else
			ba[0] = 0;
		return *this;
	}
	t = 1;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	if (right_bool)
		ba[0] = 1;
	else
		ba[0] = 0;
	return *this;
}

x::barray& x::barray::operator=(short const& right_short)
{
	if (t != 2 && t > 0)
		delete[]ba;
	if (t == 2)
	{
		for (int i = 0; i < 2; ++i)
			ba[i] = right_short >> i * 8;
		return *this;
	}
	t = 2;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < 2; ++i)
		ba[i] = right_short >> i * 8;
	return *this;
}

x::barray& x::barray::operator=(unsigned short const& right_ushort)
{
	if (t != 2 && t > 0)
		delete[]ba;
	if (t == 2)
	{
		for (int i = 0; i < 2; ++i)
			ba[i] = right_ushort >> i * 8;
		return *this;
	}
	t = 2;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < 2; ++i)
		ba[i] = right_ushort >> i * 8;
	return *this;
}

x::barray& x::barray::operator=(int const& right_int)
{
	if (t != 4 && t > 0)
		delete[]ba;
	if (t == 4)
	{
		for (int i = 0; i < 4; ++i)
			ba[i] = right_int >> i * 8;
		return *this;
	}
	t = 4;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < 4; ++i)
		ba[i] = right_int >> i * 8;
	return *this;
}

x::barray& x::barray::operator=(unsigned int const& right_uint)
{
	if (t != 4 && t > 0)
		delete[]ba;
	if (t == 4)
	{
		for (int i = 0; i < 4; ++i)
			ba[i] = right_uint >> i * 8;
		return *this;
	}
	t = 4;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < 4; ++i)
		ba[i] = right_uint >> i * 8;
	return *this;
}

x::barray& x::barray::operator=(long long const& right_long)
{
	if (t != 8 && t > 0)
		delete[]ba;
	if (t == 8)
	{
		for (int i = 0; i < 8; ++i)
			ba[i] = right_long >> i * 8;
		return *this;
	}
	t = 8;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < 8; ++i)
		ba[i] = right_long >> i * 8;
	return *this;
}

x::barray& x::barray::operator=(unsigned long long const& right_ulong)
{
	if (t != 8 && t > 0)
		delete[]ba;
	if (t == 8)
	{
		for (int i = 0; i < 8; ++i)
			ba[i] = right_ulong >> i * 8;
		return *this;
	}
	t = 8;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < 8; ++i)
		ba[i] = right_ulong >> i * 8;
	return *this;
}

// ----- operator==重载 -----
bool x::barray::operator==(x::barray const& right_barray) const noexcept
{
	if (t != right_barray.t)
		return false;
	if (t == 0)
		return true;
	for (int i = 0; i < t; ++i)
		if (ba[i] != right_barray.ba[i])
			return false;
	return true;
}

bool x::barray::operator==(char const& right_char) const noexcept
{
	if (t != 1)
		return false;
	if (ba[0] != unsigned char(right_char))
		return false;
	return true;
}

bool x::barray::operator==(unsigned char const& right_uchar) const noexcept
{
	if (t != 1)
		return false;
	if (ba[0] != right_uchar)
		return false;
	return true;
}

bool x::barray::operator==(bool const& right_bool) const noexcept
{
	if (t != 1)
		return false;
	if (right_bool&&ba[0] != 1)
		return false;
	if (!right_bool&&ba[0] != 0)
		return false;
	return true;
}

bool x::barray::operator==(short const& right_short) const noexcept
{
	if (t != 2)
		return false;
	for (int i = 0; i < t; ++i)
		if (ba[i] != unsigned char(right_short >> i * 8))
			return false;
	return true;
}

bool x::barray::operator==(unsigned short const& right_ushort) const noexcept
{
	if (t != 2)
		return false;
	for (int i = 0; i < t; ++i)
		if (ba[i] != unsigned char(right_ushort >> i * 8))
			return false;
	return true;
}

bool x::barray::operator==(int const& right_int) const noexcept
{
	if (t != 4)
		return false;
	for (int i = 0; i < t; ++i)
		if (ba[i] != unsigned char(right_int >> i * 8))
			return false;
	return true;
}

bool x::barray::operator==(unsigned int const& right_uint) const noexcept
{
	if (t != 4)
		return false;
	for (int i = 0; i < t; ++i)
		if (ba[i] != unsigned char(right_uint >> i * 8))
			return false;
	return true;
}

bool x::barray::operator==(long long const& right_long) const noexcept
{
	if (t != 8)
		return false;
	for (int i = 0; i < t; ++i)
		if (ba[i] != unsigned char(right_long >> i * 8))
			return false;
	return true;
}

bool x::barray::operator==(unsigned long long const& right_ulong) const noexcept
{
	if (t != 8)
		return false;
	for (int i = 0; i < t; ++i)
		if (ba[i] != unsigned char(right_ulong >> i * 8))
			return false;
	return true;
}

// ----- operator!=重载 -----
bool x::barray::operator!=(x::barray const& right_barray) const noexcept
{
	if (t != right_barray.t)
		return true;
	if (t == 0)
		return false;
	for (int i = 0; i < t; ++i)
		if (ba[i] != right_barray.ba[i])
			return true;
	return false;
}

bool x::barray::operator!=(char const& right_char) const noexcept
{
	if (t != 1)
		return true;
	if (ba[0] != unsigned char(right_char))
		return true;
	return false;
}

bool x::barray::operator!=(unsigned char const& right_uchar) const noexcept
{
	if (t != 1)
		return true;
	if (ba[0] != right_uchar)
		return true;
	return false;
}

bool x::barray::operator!=(bool const& right_bool) const noexcept
{
	if (t != 1)
		return true;
	if (right_bool&&ba[0] != 1)
		return true;
	if (!right_bool&&ba[0] != 0)
		return true;
	return false;
}

bool x::barray::operator!=(short const& right_short) const noexcept
{
	if (t != 2)
		return true;
	for (int i = 0; i < t; ++i)
		if (ba[i] != unsigned char(right_short >> i * 8))
			return true;
	return false;
}

bool x::barray::operator!=(unsigned short const& right_ushort) const noexcept
{
	if (t != 2)
		return true;
	for (int i = 0; i < t; ++i)
		if (ba[i] != unsigned char(right_ushort >> i * 8))
			return true;
	return false;
}

bool x::barray::operator!=(int const& right_int) const noexcept
{
	if (t != 4)
		return true;
	for (int i = 0; i < t; ++i)
		if (ba[i] != unsigned char(right_int >> i * 8))
			return true;
	return false;
}

bool x::barray::operator!=(unsigned int const& right_uint) const noexcept
{
	if (t != 4)
		return true;
	for (int i = 0; i < t; ++i)
		if (ba[i] != unsigned char(right_uint >> i * 8))
			return true;
	return false;
}

bool x::barray::operator!=(long long const& right_long) const noexcept
{
	if (t != 8)
		return true;
	for (int i = 0; i < t; ++i)
		if (ba[i] != unsigned char(right_long >> i * 8))
			return true;
	return false;
}

bool x::barray::operator!=(unsigned long long const& right_ulong) const noexcept
{
	if (t != 8)
		return true;
	for (int i = 0; i < t; ++i)
		if (ba[i] != unsigned char(right_ulong >> i * 8))
			return true;
	return false;
}

// ----- operator+重载 -----
x::barray x::barray::operator+(x::barray const& right_barray) const
{
	if (t == 0)
		return right_barray;
	if (right_barray.t == 0)
		return *this;
	barray a;
	if (right_barray.t > INT_MAX - t)
		a.t = INT_MAX;
	else
		a.t = t + right_barray.t;
	try 
	{
		a.ba = new unsigned char[a.t];
	}
	catch (std::exception& e)
	{
		a.t = 0;
		a.ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < t; ++i)
		a.ba[i] = ba[i];
	for (i; i < a.t; ++i)
		a.ba[i] = right_barray.ba[i - t];
	return a;
}

x::barray x::barray::operator+(char const& right_char) const
{
	if (t == 0)
		return barray(bool(), right_char);
	barray a;
	if (t == INT_MAX)
		a.t = INT_MAX;
	else
		a.t = t + 1;
	try
	{
		a.ba = new unsigned char[a.t];
	}
	catch (std::exception& e)
	{
		a.t = 0;
		a.ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < t; ++i)
		a.ba[i] = ba[i];
	for (i; i < a.t; ++i)
		a.ba[i] = right_char;
	return a;
}

x::barray x::barray::operator+(unsigned char const& right_uchar) const
{
	if (t == 0)
		return barray(bool(), right_uchar);
	barray a;
	if (t == INT_MAX)
		a.t = INT_MAX;
	else
		a.t = t + 1;
	try
	{
		a.ba = new unsigned char[a.t];
	}
	catch (std::exception& e)
	{
		a.t = 0;
		a.ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < t; ++i)
		a.ba[i] = ba[i];
	for (i; i < a.t; ++i)
		a.ba[i] = right_uchar;
	return a;
}

x::barray x::barray::operator+(bool const& right_bool) const
{
	if (t == 0)
		return barray(bool(), right_bool);
	barray a;
	if (t == INT_MAX)
		a.t = INT_MAX;
	else
		a.t = t + 1;
	try
	{
		a.ba = new unsigned char[a.t];
	}
	catch (std::exception& e)
	{
		a.t = 0;
		a.ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < t; ++i)
		a.ba[i] = ba[i];
	for (i; i < a.t; ++i)
		if (right_bool)
			a.ba[i] = 1;
		else
			a.ba[i] = 0;
	return a;
}

x::barray x::barray::operator+(short const& right_short) const
{
	if (t == 0)
		return barray(bool(), right_short);
	barray a;
	if (t > INT_MAX - 2)
		a.t = INT_MAX;
	else
		a.t = t + 2;
	try
	{
		a.ba = new unsigned char[a.t];
	}
	catch (std::exception& e)
	{
		a.t = 0;
		a.ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < t; ++i)
		a.ba[i] = ba[i];
	for (i; i < a.t; ++i)
		a.ba[i] = right_short >> (i - t) * 8;
	return a;
}

x::barray x::barray::operator+(unsigned short const& right_ushort) const
{
	if (t == 0)
		return barray(bool(), right_ushort);
	barray a;
	if (t > INT_MAX - 2)
		a.t = INT_MAX;
	else
		a.t = t + 2;
	try
	{
		a.ba = new unsigned char[a.t];
	}
	catch (std::exception& e)
	{
		a.t = 0;
		a.ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < t; ++i)
		a.ba[i] = ba[i];
	for (i; i < a.t; ++i)
		a.ba[i] = right_ushort >> (i - t) * 8;
	return a;
}

x::barray x::barray::operator+(int const& right_int) const
{
	if (t == 0)
		return barray(bool(), right_int);
	barray a;
	if (t > INT_MAX - 4)
		a.t = INT_MAX;
	else
		a.t = t + 4;
	try
	{
		a.ba = new unsigned char[a.t];
	}
	catch (std::exception& e)
	{
		a.t = 0;
		a.ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < t; ++i)
		a.ba[i] = ba[i];
	for (i; i < a.t; ++i)
		a.ba[i] = right_int >> (i - t) * 8;
	return a;
}

x::barray x::barray::operator+(unsigned int const& right_uint) const
{
	if (t == 0)
		return barray(bool(), right_uint);
	barray a;
	if (t > INT_MAX - 4)
		a.t = INT_MAX;
	else
		a.t = t + 4;
	try
	{
		a.ba = new unsigned char[a.t];
	}
	catch (std::exception& e)
	{
		a.t = 0;
		a.ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < t; ++i)
		a.ba[i] = ba[i];
	for (i; i < a.t; ++i)
		a.ba[i] = right_uint >> (i - t) * 8;
	return a;
}

x::barray x::barray::operator+(long long const& right_long) const
{
	if (t == 0)
		return barray(bool(), right_long);
	barray a;
	if (t > INT_MAX - 8)
		a.t = INT_MAX;
	else
		a.t = t + 8;
	try
	{
		a.ba = new unsigned char[a.t];
	}
	catch (std::exception& e)
	{
		a.t = 0;
		a.ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < t; ++i)
		a.ba[i] = ba[i];
	for (i; i < a.t; ++i)
		a.ba[i] = right_long >> (i - t) * 8;
	return a;
}

x::barray x::barray::operator+(unsigned long long const& right_ulong) const
{
	if (t == 0)
		return barray(bool(), right_ulong);
	barray a;
	if (t > INT_MAX - 8)
		a.t = INT_MAX;
	else
		a.t = t + 8;
	try
	{
		a.ba = new unsigned char[a.t];
	}
	catch (std::exception& e)
	{
		a.t = 0;
		a.ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < t; ++i)
		a.ba[i] = ba[i];
	for (i; i < a.t; ++i)
		a.ba[i] = right_ulong >> (i - t) * 8;
	return a;
}

// ----- operator+=重载 -----
x::barray& x::barray::operator+=(x::barray const& right_barray)
{
	if (t == 0)
		return *this = right_barray;
	if (right_barray.t == 0)
		return *this;
	barray a = *this;
	if (this == &right_barray)
	{
		delete[]ba;
		if (a.t > INT_MAX / 2)
			t = INT_MAX;
		else
			t = 2 * a.t;
		try
		{
			ba = new unsigned char[t];
		}
		catch (std::exception& e)
		{
			t = 0;
			ba = 0x00;
			throw(e);
		}
		for (int i = 0; i < t; ++i)
			ba[i] = a.ba[i%a.t];
		return *this;
	}
	delete[]ba;
	if (a.t > INT_MAX - right_barray.t)
t = INT_MAX;
	else
	t = a.t + right_barray.t;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < a.t; ++i)
		ba[i] = a.ba[i];
	for (i; i < t; ++i)
		ba[i] = right_barray.ba[i - a.t];
	return *this;
}

x::barray& x::barray::operator+=(char const& right_char)
{
	if (t == 0)
		return *this = right_char;
	barray a = *this;
	if (t < INT_MAX)
		++t;
	delete[]ba;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < a.t; ++i)
		ba[i] = a.ba[i];
	for (i; i < t; ++i)
		ba[i] = right_char;
	return *this;
}

x::barray& x::barray::operator+=(unsigned char const& right_uchar)
{
	if (t == 0)
		return *this = right_uchar;
	barray a = *this;
	if (t < INT_MAX)
		++t;
	delete[]ba;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < a.t; ++i)
		ba[i] = a.ba[i];
	for (i; i < t; ++i)
		ba[i] = right_uchar;
	return *this;
}

x::barray& x::barray::operator+=(bool const& right_bool)
{
	if (t == 0)
		return *this = right_bool;
	barray a = *this;
	if (t < INT_MAX)
		++t;
	delete[]ba;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < a.t; ++i)
		ba[i] = a.ba[i];
	for (i; i < t; ++i)
		if (right_bool)
			ba[i] = 1;
		else
			ba[i] = 0;
	return *this;
}

x::barray& x::barray::operator+=(short const& right_short)
{
	if (t == 0)
		return *this = right_short;
	barray a = *this;
	if (t > INT_MAX - 2)
		t = INT_MAX;
	else
		t += 2;
	delete[]ba;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < a.t; ++i)
		ba[i] = a.ba[i];
	for (i; i < t; ++i)
		ba[i] = right_short >> (i - a.t) * 8;
	return *this;
}

x::barray& x::barray::operator+=(unsigned short const& right_ushort)
{
	if (t == 0)
		return *this = right_ushort;
	barray a = *this;
	if (t > INT_MAX - 2)
		t = INT_MAX;
	else
		t += 2;
	delete[]ba;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < a.t; ++i)
		ba[i] = a.ba[i];
	for (i; i < t; ++i)
		ba[i] = right_ushort >> (i - a.t) * 8;
	return *this;
}

x::barray& x::barray::operator+=(int const& right_int)
{
	if (t == 0)
		return *this = right_int;
	barray a = *this;
	if (t > INT_MAX - 4)
		t = INT_MAX;
	else
		t += 4;
	delete[]ba;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < a.t; ++i)
		ba[i] = a.ba[i];
	for (i; i < t; ++i)
		ba[i] = right_int >> (i - a.t) * 8;
	return *this;
}

x::barray& x::barray::operator+=(unsigned int const& right_uint)
{
	if (t == 0)
		return *this = right_uint;
	barray a = *this;
	if (t > INT_MAX - 4)
		t = INT_MAX;
	else
		t += 4;
	delete[]ba;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < a.t; ++i)
		ba[i] = a.ba[i];
	for (i; i < t; ++i)
		ba[i] = right_uint >> (i - a.t) * 8;
	return *this;
}

x::barray& x::barray::operator+=(long long const& right_long)
{
	if (t == 0)
		return *this = right_long;
	barray a = *this;
	if (t > INT_MAX - 8)
		t = INT_MAX;
	else
		t += 8;
	delete[]ba;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < a.t; ++i)
		ba[i] = a.ba[i];
	for (i; i < t; ++i)
		ba[i] = right_long >> (i - a.t) * 8;
	return *this;
}

x::barray& x::barray::operator+=(unsigned long long const& right_ulong)
{
	if (t == 0)
		return *this = right_ulong;
	barray a = *this;
	if (t > INT_MAX - 8)
		t = INT_MAX;
	else
		t += 8;
	delete[]ba;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < a.t; ++i)
		ba[i] = a.ba[i];
	for (i; i < t; ++i)
		ba[i] = right_ulong >> (i - a.t) * 8;
	return *this;
}

// ----- operator*重载 -----
x::barray x::barray::operator*(int const& multiple) const
{
	if (t == 0)
		return *this;
	barray a;
	if (multiple <= 0)
		return a;
	if (t > INT_MAX / multiple)
		a.t = INT_MAX;
	else
		a.t = multiple * t;
	try
	{
		a.ba = new unsigned char[a.t];
	}
	catch (std::exception& e)
	{
		a.t = 0;
		a.ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < a.t; ++i)
		a.ba[i] = ba[i%t];
	return a;
}

x::barray x::operator*(int const& multiple, x::barray const& right_barray)
{
	if (right_barray.t == 0)
		return right_barray;
	barray a;
	if (multiple <= 0)
		return a;
	if (right_barray.t > INT_MAX / multiple)
		a.t = INT_MAX;
	else
		a.t = multiple * right_barray.t;
	try
	{
		a.ba = new unsigned char[a.t];
	}
	catch (std::exception& e)
	{
		a.t = 0;
		a.ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < a.t; ++i)
		a.ba[i] = right_barray.ba[i%right_barray.t];
	return a;
}

// ----- operator*=重载 -----
x::barray& x::barray::operator*=(int const& multiple)
{
	if (t == 0)
		return *this;
	if (multiple <= 0)
	{
		delete[]ba;
		t = 0;
		return *this;
	}
	barray a = *this;
	delete[]ba;
	if (a.t > INT_MAX / multiple)
		t = INT_MAX;
	else
		t = multiple * a.t;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < t; ++i)
		ba[i] = a.ba[i%a.t];
	return *this;
}








/*

x::barray_long::barray_long()
{
	ba = 0x00;
	t = 0;
	status = code::INIT;
}

x::barray_long::barray_long(const long long& array_length, unsigned char value)
{
	if (array_length <= 0)
	{
		ba = 0x00;
		t = 0;
		status = code::INIT;
		return;
	}
	t = array_length;
	ba = new unsigned char[t];
	for (long long i = 0; i < t; ++i)
		ba[i] = value;
	status = code::NORMAL;
}

x::barray_long::barray_long(const barray_long& origin_barray)
{
	if (origin_barray.t == 0)
	{
		t = 0;
		ba = 0x00;
		status = code::INIT;
		return;
	}
	t = origin_barray.t;
	ba = new unsigned char[t];
	status = code::NORMAL;
	for (long long i = 0; i < t; ++i)
		ba[i] = origin_barray.ba[i];
}

x::barray_long::barray_long(const barray& origin_barray)
{
	if (origin_barray.get_length() == 0)
	{
		t = 0;
		ba = 0x00;
		status = code::INIT;
		return;
	}
	t = origin_barray.get_length();
	ba = new unsigned char[t];
	status = code::NORMAL;
	for (long long i = 0; i < t; ++i)
		ba[i] = origin_barray[i];
}

x::barray_long::~barray_long()
{
	if (t > 0)
		delete[]ba;
	ba = 0x00;
	t = 0;
	status = code::INIT;
}

bool x::barray_long::set_length(const long long& array_length, unsigned char value)
{
	if (array_length < 0)
		return false;
	if (t == array_length)
		return true;
	else if (t == 0)
	{
		t = array_length;
		ba = new unsigned char[t];
		for (long long i = 0; i < t; ++i)
			ba[i] = value;
		status = code::NORMAL;
		return true;
	}
	else if (array_length == 0)
	{
		delete[]ba;
		t = 0;
		ba = 0x00;
		status = code::INIT;
		return true;
	}
	delete[]ba;
	t = array_length;
	ba = new unsigned char[t];
	for (long long i = 0; i < t; ++i)
		ba[i] = value;
	status = code::NORMAL;
	return true;
}

long long x::barray_long::get_length() const
{
	return t;
}

int x::barray_long::get_status() const
{
	return status;
}

unsigned char& x::barray_long::operator[](const long long& num) const
{
	return ba[num];
}

x::barray_long& x::barray_long::operator=(const x::barray_long& right_barray)
{
	if (t != 0 && t != right_barray.t)
		delete[]ba;
	if (right_barray.t == 0)
	{
		t = 0;
		ba = 0x00;
		status = code::INIT;
		return *this;
	}
	t = right_barray.t;
	ba = new unsigned char[t];
	for (long long i = 0; i < t; ++i)
		ba[i] = right_barray.ba[i];
	status = code::NORMAL;
	return *this;
}

bool x::barray_long::operator==(const x::barray_long& right_barray) const
{
	if (t != right_barray.t)
		return false;
	if (t == 0)
		return true;
	for (long long i = 0; i < t; ++i)
		if (ba[i] != right_barray.ba[i])
			return false;
	return true;
}

bool x::barray_long::operator!=(const x::barray_long& right_barray) const
{
	if (t != right_barray.t)
		return true;
	if (t == 0)
		return true;
	for (long long i = 0; i < t; ++i)
		if (ba[i] != right_barray.ba[i])
			return true;
	return false;
}

x::barray_long x::barray_long::operator+(const x::barray_long& right_barray) const
{
	if (t == 0)
		return right_barray;
	if (right_barray.t == 0)
		return *this;
	barray_long a;
	a.t = t + right_barray.t;
	a.ba = new unsigned char[a.t];
	long long i;
	for (i = 0; i < t; ++i)
		a.ba[i] = ba[i];
	for (i; i < a.t; ++i)
		a.ba[i] = right_barray.ba[i - t];
	a.status = code::NORMAL;
	return a;
}

x::barray_long& x::barray_long::operator+=(const x::barray_long& right_barray)
{
	if (t == 0)
		return *this = right_barray;
	if (right_barray.t == 0)
		return *this;
	barray_long a = *this;
	t = a.t + right_barray.t;
	delete[]ba;
	ba = new unsigned char[t];
	long long i;
	for (i = 0; i < a.t; ++i)
		ba[i] = a.ba[i];
	for (i; i < t; ++i)
		ba[i] = right_barray.ba[i - a.t];
	return *this;
}

x::barray_long x::barray_long::operator*(const int& multiple) const
{
	if (t == 0)
		return *this;
	barray_long a;
	if (multiple <= 0)
		return a;
	a.t = multiple * t;
	a.ba = new unsigned char[a.t];
	a.status = code::NORMAL;
	for (long long i = 0; i < a.t; ++i)
		a.ba[i] = ba[i%t];
	return a;
}

x::barray_long& x::barray_long::operator*=(const int& multiple)
{
	if (t == 0)
		return *this;
	if (multiple <= 0)
	{
		delete[]ba;
		t = 0;
		status = code::INIT;
		return *this;
	}
	barray_long a = *this;
	t = multiple * a.t;
	ba = new unsigned char[t];
	for (long long i = 0; i < t; ++i)
		ba[i] = a.ba[i%a.t];
	return *this;
}

x::barray_long x::operator*(const int& multiple, const x::barray_long& right_barray)
{
	if (right_barray.t == 0)
		return right_barray;
	barray_long a;
	if (multiple <= 0)
		return a;
	a.t = multiple * right_barray.t;
	a.ba = new unsigned char[a.t];
	a.status = code::NORMAL;
	for (long long i = 0; i < a.t; ++i)
		a.ba[i] = right_barray.ba[i%right_barray.t];
	return a;
}

*/