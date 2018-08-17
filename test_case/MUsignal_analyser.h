#pragma once

#include "config.h"

namespace prosthetics {
	namespace MU {

		class peakAnalyser {

			// TODO(me): build own ring-buffer using vector!
			using analyseWindow_t = std::deque<int>;

		public:

			peakAnalyser(int peak, size_t framesToAnalyse)
				: _peak(peak)
				, _framesToAnalyse(framesToAnalyse)
				, _means(framesToAnalyse)
			{ }

			template <class T>
			auto testAnalyse(const T & values) {
				// idea is that the int could be used to specify force in some way. the bool tells if the MU is active continually 
				std::pair<int, bool> result{ 0 , false };
				int force = 0;
				int newMean = 0, size = std::size(values);
				if (size > 0) {
					newMean = (std::accumulate(std::begin(values), std::end(values), 0)) / size;
				}
				_means.pop_back();
				_means.push_front(newMean);
				if ((std::accumulate(std::begin(_means), std::end(_means), 0)) >= _peak) {
					if (!_holding) {
						// for now just turn true
						_holding = true;
					}
					force = 1;
					result = { force , _holding };
				}
				else {
					_holding = false;
				}
				return result;
			}

		private:
			int          _peak;
			size_t          _framesToAnalyse;
			bool            _holding{ false };
			analyseWindow_t _means;


		}; // class analyser

	} // namespace MU
} // namespace prosthetics