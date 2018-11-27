#pragma once

namespace prosthetics {
	template <
	   class signalSource
	,  class noiseFilter
        ,  class decomposer
//      ,  class analyser
	>
	class signalStream{
        private:

	public:
           signalStream(const signalSource& sigS, const noiseFilter& nFil, const decomposer& decomp)
	   : _sigSource(sigS)
	   , _noiseFilter(nFil)
	   , _decomposer(decomp)
	   {}

	private:
	   const signalSource& _sigSource;
	         noiseFilter&  _noiseFilter;
	         decomposer&   _decomposer;
	}
			
} //namespace prosthetics
