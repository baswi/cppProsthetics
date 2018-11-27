

int main() {

	//new idea: pCtrl has the pool of signalStreams
	
	//old idea: pCtrl for a specific type of signalSource, filter, ... so this way one ctrl can't handle diff. types of Sources or even
	//          filter at the same time
	//prosthetics::prosthetic_control prosthesis(signalSources, noiseFilter /*, analyser, actuator */);
	

// run the prosthesis
	prosthetics::run(prosthesis);

}
