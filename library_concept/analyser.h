#pragma once

namespace prosthetics {

	template<class signal_Type>	class analyser;

	// perfect forwarding!?!
	constexpr signal_Type run(/* signal_Type input */);


} // namespace prosthetics