#include "LPF.h"

LowPassFilter::LowPassFilter(float RC, int init_val){
	LowPassFilter::prev_val = init_val;
	LowPassFilter::RC = RC;
	LowPassFilter::prev_time = 0;
}
float LowPassFilter::Perform_analog(int value){
	int dt = clock()*1000/CLOCKS_PER_SEC;
	float alpha = dt / (RC + dt);
	prev_val = prev_val + (alpha * (value - prev_val));
	cout << "lpf: " << prev_val << endl;
	return prev_val;
}
int LowPassFilter::Perform_digital(int value){
	float result = Perform_analog(value);
	if(result < 0.6)
		return 0;
	else if(result > 1.4)
		return 2;
		
	return 1;
}
