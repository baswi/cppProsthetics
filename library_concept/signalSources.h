#pragma once

namespace prosthetics {

	template<class signal_Type /*??, size_t N_SignalSources ??*/>	class signalSources;

	// the signalSources has to return/outStream signal_Type for every single SignalSource
	constexpr signal_Type next(/* size_t signalNumber */);
    // ??    and/or operator>>   ??

} // namespace prosthetics