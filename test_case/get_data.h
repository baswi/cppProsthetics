#pragma once

#include "config.h"

#include <iostream>
#include <cinttypes>
#include <fstream>
#include <string>
#include <utility>
#include <sstream>
#include <iterator>
#include <vector>


namespace prosthetics {
	namespace get_signal {

		struct emg_signal {

			using data_t = std::vector<std::pair<int, int>>;
			using emg_ampl = int;
			using signalFrame_t = std::vector<int>;

		public:
			// Constructor
			emg_signal(std::string filename)
			{
				std::ifstream input(filename);
				if (input.is_open()) {
					_data.emplace_back(0, 0);
					for (std::string line; std::getline(input, line); ) {
						std::istringstream iss(line);
						std::vector<std::string> pairs(std::istream_iterator<std::string>{iss},
							std::istream_iterator<std::string>());
						_data.emplace_back(std::stoi(pairs[0]), std::stoi(pairs[1]));
					}
				}
			}

			// TODO(me): separate container and data-access (-> Iterator!!)
			const emg_ampl & next_data() {
				return _data[_pos++].second;
			}
			// TODO(me): best would be to use a view!!
			signalFrame_t signalFrame(size_t timeFrame, size_t maxTime) {
				// timeFrame is in microseconds (0,000001 s)
				signalFrame_t values{};
				size_t frameEnd = (timeFrame + _data[_pos].first);
				if (frameEnd > maxTime)
				{
					frameEnd = maxTime;
				}
				// the very last value will not be inserted atm...
				for (; _data[_pos].first < frameEnd; ++_pos) {
					values.emplace_back(_data[_pos].second);
				}
				return values;
			}

		private:
			data_t _data;
			int _pos{ 0 };
		}; // struct emg_signal

	} // namespace get_signal
} // namespace prosthetics