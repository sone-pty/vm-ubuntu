#include "cpp_test.h"

#include <vector>
#include <array>
#include <iostream>
#include <string>

using namespace std;

template <typename T> void print(T&& a) { cout << a << endl; }
template <typename T, typename... Args> void print(T&& a, Args&&... arg)
{
    cout << a << " ";
    print(forward<Args>(arg)...);
}

//--------------转发失败情况测试---------------------
//空指针转发需要传入nullptr而不是NULL或者0
void forward_fail_test_intptr(int*)
{
    cout << "forward int* succ" << endl;
}

void forward_fail_test_intptr(int)
{
    cout << "forward int* failed" << endl;
}

template <typename... Args> void forward_fail_test(Args&&... args)
{
    forward_fail_test_intptr(forward<Args>(args)...);
}

//--------------转发失败情况测试---------------------

class Test
{
public:
    Test() { cout << "default construct" << endl; }
    Test(const Test& t) { cout << "Test copy construct" << endl; }
    Test(Test&& t) { cout << "Test move construct" << endl; }
    void operator=(const Test& t) { cout << "Test assign(const Test&)" << endl; }
    void operator=(Test&& t) { cout << "Test assign(Test&&)" << endl; }

    static void func(vector<int>&& a) { cout << "vector<int>&&" << endl; }
    template <typename T> static void func(T&& a) { cout << "T&&" << endl; }
    template <typename T> static void forward_T(T&& a) { process_1(a); }

private:
    static void process_1(const string&) { print("process_1", "string&"); }
    static void process_1(string&&) { print("process_1", "string&&"); }
};

void process(const string& lvalArg) { print("left"); }
void process(string&& rvalArg) { print("right"); }

template<typename T> void logAndProcess(T&& param)
{
    process(param);
}

void MainFunc(const Test& t) { }

// 引用折叠作用于四种情况: 1. 模板实例化 2. auto类型推导 3. typedef和别名声明的产生和使用 4. decltype

int main(void)
{
    return 0;
}