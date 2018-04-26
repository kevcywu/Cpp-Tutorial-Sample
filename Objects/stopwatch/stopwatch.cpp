#include "stdafx.h"
#include <iostream>
#include "Stopwatch.h"

Stopwatch::Stopwatch() : start_time(0), running(false), elapsed_time(0.0) {}

void Stopwatch::start() {
	if (!running) {
		running = true;
		start_time = clock();
	}
}

void Stopwatch::stop() {
	if (running) {
		clock_t stop_time = clock();
		running = false;
		elapsed_time += static_cast<double> (stop_time - start_time) / CLOCKS_PER_SEC;
	}
}

double Stopwatch::elapsed() const {
	if (running) {
		clock_t current_time = clock();
		return elapsed_time + static_cast<double> (current_time - start_time) / CLOCKS_PER_SEC;
	}
	else
		return elapsed_time;
}

bool  Stopwatch::is_running() const {
	return running;
}

void Stopwatch::reset() {
	running = false;
	elapsed_time = 0.0;
}