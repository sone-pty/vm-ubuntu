#pragma once

#include <sstream>
#include <iostream>

class StringOutput
{
public:
	template <typename... Args> StringOutput& operator<<(Args&&... args)
	{
		InnerTest(_ss, std::forward<Args>(args)...);
		return *this;
	}

private:
	// 终止函数
	void InnerTest(std::stringstream& ss)
	{
		std::cout << ss.str() << std::endl;
	}

	template <typename T, typename... Args> void InnerTest(std::stringstream& ss, T&& arg, Args&&... args)
	{
		ss << std::forward<T>(arg);
		InnerTest(ss, std::forward<Args>(args)...);
	}

private:
	std::stringstream _ss;
};

template <typename T> class Parent 
{
public:
    Parent() = default;
    Parent(T arg) : _arg(arg) {}

    T GetArg() const { return _arg; }

protected:
    T _arg;
};

template <typename T, typename F> class Child : public Parent<T> 
{
public:
    Child() = default;
    Child(T arg) : Parent<T>(arg) {}
};

template <typename F> class Child<int, F> : public Parent<int> 
{
public:
    Child() = default;
    Child(int arg) { _arg = 1; }
};

// 由数组引用推断获得数组大小
template <typename T, size_t N> constexpr size_t arraySize(T (&)[N]) noexcept { return N; }