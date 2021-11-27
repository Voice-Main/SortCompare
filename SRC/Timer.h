#pragma once

#include <iostream>
#include <chrono>

class Timer
{
private:

	std::chrono::time_point<std::chrono::steady_clock> start;
	std::chrono::duration<float> duration;
public:

	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer() 
	{
		auto end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		printDuration();
	}
	void printDuration()
	{
		std::cout << "持续时间 : " << duration.count() * 1000.f << "ms\n";
	}

};