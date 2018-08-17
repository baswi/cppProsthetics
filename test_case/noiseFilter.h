#pragma once

#include "config.h"


namespace prosthetics {
namespace noiseFilter {

	template <typename T>
	decltype(auto) noFilter(T&& values) {
		return values;
	}; // class noFilter

} // namespace noiseFilter
} // namespace prosthetics