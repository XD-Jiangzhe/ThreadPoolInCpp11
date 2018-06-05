# ThreadPoolCPP11
一个用c++11标准实现的可以放入任何函数签名的线程池

## 实现
线程的个数 由std::thread::hardware_concurrency()来确定
使用std::packaged_task对任务进行封装，并使用lambda对std::package_task进行二次封装
并且使用将其与future进行绑定，返回future，然后再使用右值引用，从而能够操作返回的future变量

## 使用
cmake .
make

## 接口
run（）：函数运行
add（）：来增加新的任务
std::future<std::result_of<Function(Args...)>::type> add(func,args...)
