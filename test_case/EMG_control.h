#pragma once

// TODO (me): this needs to be separated into Filters, EMG_control (maybe Signal_analysis)

#include "config.h"

namespace prosthetics {
namespace EMG_control {

	const int NOISE_BUFFER_SIZE{128};

	class emg_control
	{


// TODO (me):  this is the container part for the EMG control -> separate it from the 'real' control
		struct EMGchannel_t
		{
			int pin;

// TODO (me):  this should be some sort of FIFO storage + some usability:  std::queue  or  stay with std::vector   and build a wrapper around it?!?
			CIRCLE_BUFFER noiseFloor = CIRCLE_BUFFER(NOISE_BUFFER_SIZE);

			NB_TIMER HOLD_timer;

			bool active;
			int sample;
			int signal;
			int prevSignal;

			bool PEAK;
			bool HOLD;

		}; // struct  EMGchannel_t


	private:

	}; // class emg_control


	class CIRCLE_BUFFER {

		const uint16_t C_BUFF_MAX_SIZE =	128

		CIRCLE_BUFFER(uint16_t size)
		{
			// if buffer size is not a power of 2, increase size until it is
			while (!isPowerOfTwo(size))
				size++;

			// limit array size to maximum allocated size
			if (size > C_BUFF_MAX_SIZE)
				size = C_BUFF_MAX_SIZE;

			// set circle buffer size
			buffSize = size;
			buffSizeMask = (buffSize - 1);

			// initialise read/write index
			readIndex = 0;
			writeIndex = 0;

			// clear math variables
			total = 0;
			mean = 0;
		}


	private:
		// buffer metrics
		uint16_t buffSize;
		uint16_t buffSizeMask;
		uint16_t buff[C_BUFF_MAX_SIZE] = { 0 };
		// read and write index
		uint16_t readIndex;
		uint16_t writeIndex;
		// averaging buffers
		uint32_t total = 0;		// running total
		uint32_t mean = 0;		// running mean

		bool isPowerOfTwo(uint16_t x);				// return 1 if 'x' is a power of 2
	}; // class CIRCLE_BUFFER

} // namespace EMG_control
} // namespace prosthetics