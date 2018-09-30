

int main() {

	prosthetics::prosthetic_control prosthesis(signalSources, noiseFilter /*, analyser, actuator */);
	prosthetics::run(prosthesis);

}