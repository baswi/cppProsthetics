#include <iostream>
#include <thread>
#include <cinttypes>
#include <fstream>
#include <string>
#include <utility>
#include <sstream>
#include <iterator>
#include <vector>
#include "config.h"
#include "get_data.h"
#include "MUsignal_analyser.h"
#include "noiseFilter.h"
#include "parsing_and_stuff.h"
#include "signal_and_MU-control.h"



int main() {

	prosthetics::get_signal::emg_signal input("formated_signal.txt");
	prosthetics::CandC::signalControl control(input);
	// both in microseconds (0,000001 s) (200 Hz = 5 ms(period))
	size_t frameSize = 500;
	size_t runTime = 1200000;
	int threshold = 2000;
	size_t frames = 4;

	control.testRun(frameSize, runTime, threshold, frames);

}
