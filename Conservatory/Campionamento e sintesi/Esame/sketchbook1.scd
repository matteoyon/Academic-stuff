(
s.boot;
s.meter;
s.plotTree;
s.scope;
)

b = Buffer.readChannel(s, "/Volumes/GoogleDrive/Il mio Drive/Cloud Conservatorio/BIENNIO/Campionamento e sintesi/2/Progetto Esame/potatoHead/versione1/in.wav", channels: 1);

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

