#pragma once

namespace prosthetics {




	template<class pCtrl> void run(pCtrl p) {
		for(singleProstheticStream : prostheticStreams)
		{
			prosthetics::run(singleProstheticStream);
		}
		// idea: 
		// MOVE << actuator << decomposer/analyser << noiseFilter << signalSources
	}



	// ??  global operator <<  ??
	// idea: the whole processing chain is completely based on the signalType and this signal is passed through every part
	//       so the min every part has to offer is, handing the signal it currently operates on to the next part in the chain
	//   ++  the global << could force (meaning use) some sort of 'run' method in every part of the chain and then return what
	//       this method returns. -> return xxx(...)

	// ?? what if the signalType has to be changed/casted to some sort of operationType? would it be a better idea to not restrict
	//    all parts in the chain to the same signalType?!?

	template <
	   class signalSources
	,  class noiseFilter
//??	,  class decomposer_analyser
//??	,  class actuator
	>
	
	// ?fix # of Streams? -> static mem
	// template<int N=1>
	class prosthetic_control{
	// let user create Streams and pass via constructor
	// ||
	// add Streams to Streampool via MembFunct
		// ?good idea to do it like vector of pointer to ...?
        private:
        using streamPool = std::vector<prosStreams>;

	public:
	//Constructors
        //TODO me: not finished
        prosthetic_control(streamPool& prosStreams)
	: _prosStreams(prosStreams)
	{}


	template<class prostheticSigStream>
	decltype(auto) addStream(prostheticSigStream&& pStream)
	{
		//TODO me: add pStream to _prosStreams -> use STL!
	}

	private:
           streamPool _prosStreams;	
        }

	

} // namespace prosthetics
