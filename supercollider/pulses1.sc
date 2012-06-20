Server.local.makeGui;
Server.internal.makeGui;
Server.local.scope;
Server.local.freqscope;

(
	~numChannels = 2;
	
	//Sound source: simple sin osc for now
	SynthDef(\drones, { |out|
		Out.ar(out, SinOsc.ar!~numChannels);
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
	~dronesSynth = Synth(\drones, [\out, 0]);
)

//Play the drones modulated by \fmEnv
(
	~bus = Bus.audio(s, ~numChannels);
	
	~dronesSynth = Synth(\drones, [\out, ~bus]);
	~fmEnvSynth = Synth.after(x, \fmEnv, [\source, ~bus]);
)

//FM [8..16] and back every 16 secs
{SinOsc.kr(1/16, 0, 4, 12)}.plot(minval:8, maxval:16, duration:8);

//FM [1..2] and back every 4 secs
{SinOsc.kr(1/4, 0, 0.5, 1.5)}.plot(minval:0, maxval:4, duration:8);

//FM [1..17] and back every 32 secs
{SinOsc.kr(1/32, pi*1.5, 8, 9)}.plot(minval:1, maxval:17, duration:32);