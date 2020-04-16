/*
 * 该题是《编程之美》第一题 =.=
 * 在任务管理器中的CPU资源监控中
 * （1）画出一条50%占用率的直线，（2）画出正弦曲线
 * 使用Windows API, sleep() 
 *
 * 需要注意的是多核和单核cpu的区别
 */


#include <vector>
#include <iostream>
#include <thread>

using namespace std;

void fn()
{
	while(1)
	{
		
	}
}

int main()
{
	std::vector<std::thread> at;
	const int num_of_cores = 4;

	for (int n = 0; n < num_of_cores; n++) 
	{
		at.push_back(std::thread(fn));
	}
	for (auto& t : at) 
		t.join();
	
	system("pause");
	return 0;
}
