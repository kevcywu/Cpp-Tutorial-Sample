#ifndef STOPWATCH_H_DEFINED_
#define STOPWATCH_H_DEFINED_

#include <ctime>

class Stopwatch {
private:
	clock_t start_time;
	bool running;
	double elapsed_time;
public:
	Stopwatch();
	void start();
	void stop();
	void reset();
	double elapsed() const;
	bool is_running() const;

};


#endif // !STOPWATCH_H_DEFINED_
