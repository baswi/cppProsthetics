#pragma once

namespace prosthetics {
	template<class signalStream>
	class signalStreamWrapper{
        private:

	public:
                signalStreamWrapper(signalStream& sigStream)
                :_sigStream(sigStream)
		{}


	// Operators
	
		constexpr bool operator==(const 

	private:
	        signalStream& _sigStream;
	}
			
} //namespace prosthetics
