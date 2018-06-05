#include <iostream>
#include <string>
#include "thread_pool.hpp"
using namespace std;


int main()
{
    std::mutex mtx;
    try
    {
        shared_ptr<jz::ThreadPool> tp(make_shared<jz::ThreadPool>());
        tp->run();

        std::vector<std::future<int>> v;
        std::vector<std::future<string>> v1;
        for (int i = 0; i <= 10; ++i)
        {
            v.push_back((tp->add([](int answer) { return answer; }, i)));
        }
        
        for (int i = 0; i <= 5; ++i)
        {
            auto ans = tp->add([](const std::string& str1, const std::string& str2)
            {
                return (str1+str2);
            }, "hello ", "world");
            v1.push_back(std::move(ans));
        }
        for (size_t i = 0; i < v.size(); ++i)
        {
            cout << v[i].get() << endl;
        }
        for (size_t i = 0; i < v1.size(); ++i)
        {
            cout<<v1[i].get()<<endl;
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

}