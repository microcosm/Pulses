//Boot the server
(
	s = Server.local.makeGui;
	Server.default = s;
	Server.local.options.device = "Soundflower (16ch)";
	s.boot;
	s.scope;
	s.freqscope;
)

//Load all SynthDefs
(
	~numChannels = 2;
	
	//Sound source: bassy FM drone
	SynthDef(\drones1, { |out|
		var signal;
		var modulator;

		modulator = SinOsc.ar(1/16, 0, 40, 120);
		signal = (LFTri.ar(modulator/2) * 0.2) + (SinOsc.ar(modulator) * 0.2);
		
		Out.ar(out, signal!2);
	}).send(s);
	
	//Sound source: bassy FM drone with more character on the triangle
	SynthDef(\drones2, { |out|
		var signal, numVoices = 8;
		var modulator;

		modulator = SinOsc.ar(1/16, 0, 40, 120);
		signal = (LFTri.ar(modulator/2*{1.rand+2}.dup(numVoices)) * 0.2) + (SinOsc.ar(modulator) * 0.2);
		signal = Pan2.ar(signal, {1.0.rand2}.dup(numVoices));
		signal = Mix.new(signal);
		
		Out.ar(out, signal/numVoices);
	}).send(s);

	//Envelope: reveal at FM'd intervals
	SynthDef(\fmEnv, { |source|
		var trig, env;
	
 		trig = SinOsc.kr(SinOsc.kr(1/32, pi*1.5, 8, 9)); //FM
		env = EnvGen.ar(Env.adsr(0.005, 0.8, 0.01, 0.1, curve:-3), trig);

		Out.ar(0, env*In.ar(source, ~numChannels));
	}).send(s);
)

//Play the drones unmodulated
(
	//~drones1Synth = Synth(\drones1, [\out, 0]);
	~drones2Synth = Synth(\drones2, [\out, 0]);
)

//Play the drones modulated by \fmEnv
(
	~bus = Bus.audio(s, ~numChannels);
	
	//~drones1Synth = Synth(\drones1, [\out, ~bus]);
	~drones2Synth = Synth(\drones2, [\out, ~bus]);
	~fmEnvSynth = Synth.after(~dronesSynth, \fmEnv, [\source, ~bus]);
)

~drones1Synth.free;
~drones2Synth.free;
~fmEnvSynth.free;

/* FM plotters for \fmEnv */

//FM [8..16] and back every 16 secs
{SinOsc.kr(1/16, 0, 4, 12)}.plot(minval:8, maxval:16, duration:8);

//FM [1..2] and back every 4 secs
{SinOsc.kr(1/4, 0, 0.5, 1.5)}.plot(minval:0, maxval:4, duration:8);

//FM [1..17] and back every 32 secs
{SinOsc.kr(1/32, pi*1.5, 8, 9)}.plot(minval:1, maxval:17, duration:32);