(
s.boot;
s.meter;
s.plotTree;
s.scope;
)

b = Buffer.readChannel(s, "in.wav".resolveRelative, channels: 1);

b.play;
b.release;

(
{
	var sig;
	sig = GrainBuf.ar(
		2,
		Dust.ar(MouseY.kr * 40),
		0.2,
		b,
		1,
		MouseX.kr
	);
	sig = GVerb.ar(sig);
}.play
)

