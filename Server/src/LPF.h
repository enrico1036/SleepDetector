#ifndef LPF
#define LPF

#include <stdexcept>
#include <chrono>
#include <iostream>

using namespace std;

class LowPassFilter{
private:
	float prev_val;
	int prev_time;
	float RC;
    
public:
    LowPassFilter(float RC, int init_val);
    float Perform_analog(int value);
    int Perform_digital(int value);

};
#endif // LPF
