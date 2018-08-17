#pragma once

#include "config.h"

#include "noiseFilter.h"
#include "get_data.h"
#include "MUsignal_analyser.h"

namespace prosthetics {
	namespace CandC {


		class signalControl {

			using inputSigSource_t = prosthetics::get_signal::emg_signal;
			//	using outputSigRecipient_t  = prosthetics:: ???
			//	using noiseFilter_t         = prosthetics::noiseFilter::noFilter;
			using analyser = prosthetics::MU::peakAnalyser;


		public:

			signalControl(inputSigSource_t & inputSigS/*, noiseFilter_t & nFilter*/)
				: _inputSigS(inputSigS)
				//		, _nFilter(nFilter)
			{}

			// frameSize in microseconds (0,000001 s)
			void testRun(size_t frameSize, size_t maxTime, int threshold, size_t numOfFramesToAnalyse) {

				size_t end = (maxTime / frameSize);
				for (size_t round = 0; round < end; ++round) {
					auto values = _inputSigS.signalFrame(frameSize, maxTime);
					// make the analyser a member?
					analyser analyse{ threshold , numOfFramesToAnalyse };
					auto analysisResults = analyse.testAnalyse(values);
					// build own class for movement commands
					if (analysisResults.first > 0) {
						std::cout << "MOVE\n";
					}
				}
				std::cout << "\n*** END OF TEST-RUN ***\n";
			}



		private:
			inputSigSource_t &       _inputSigS;
			//		outputSigRecipient_t &   _outputSigR;
			//		noiseFilter_t &          _nFilter;


		}; // class signalControl

	} // namespace CandC
} // namespace prosthetics