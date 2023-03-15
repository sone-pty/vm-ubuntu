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

class Test
{
public:
    Test() = default;

    static void func(vector<int>&& a) { cout << "vector<int>&&" << endl; }
    template <typename T> static void func(T&& a) { cout << "T&&" << endl; }
    template <typename T> static void forward_T(T&& a) { process_1(a); }

private:
    static void process_1(const string&) { print("process_1", "string&"); }
    static void process_1(string&&) { print("process_1", "string&&"); }
};

void process(const string& lvalArg) { print("left"); }
void process(string&& rvalArg) { print("right"); }

template<typename T>                        //用以转发param到process的模板
void logAndProcess(T&& param)
{
    process(param);
}

int main(void)
{
    string&& rs = "sdsd";
    logAndProcess(std::move(rs));
    return 0;
}