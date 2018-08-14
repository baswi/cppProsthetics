#pragma once

#include "config.h"

#include <iostream>
#include <cinttypes>
#include <fstream>
#include <string>
#include <utility>
#include <sstream>
#include <iterator>


namespace prosthetics {
namespace get_signal {

	struct emg_signal {

		typedef std::pair<int, int> data_t;
		using emg_ampl = int;
	public:
		// Constructor
		emg_signal(std::string filename)
		{
			std::ifstream input(filename);
			if (input.is_open()) {
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



	private:
		std::vector<std::pair<int, int>> _data;
		int _pos{ 0 };
	}; // struct emg_signal

} // namespace get_signal
} // namespace prosthetics