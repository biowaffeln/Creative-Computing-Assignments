import processing.serial.*;

Serial myPort;

void setup()
{
	background(50);
	textSize(72);
	String portName = Serial.list()[0];
	myPort = new Serial(this, portName, 9600);
	size(1300, 1300);
}

void draw() {
	if ( myPort.available() > 0) {

		String stringVal = myPort.readStringUntil('\n');
		int val = 0;

		try {
			val = Integer.parseInt(stringVal.trim());
		} catch (Exception e) {}

		println(val);

		// I originally drew the faces on a larger sketch
		// and was too lazy to recompute all the values ¯\_(ツ)_/¯
		translate(-300, -100);

		if (val >= 0) {
			happyFace();
			text("yay!", 1250, 1250);
		} else {
			sadFace();
			text("please don't touch me!", 550, 350);
		}
	}
}


void sadFace() {
	noFill();
	stroke(230);
	strokeWeight(10);
	background(50);

	// eyes
	beginShape();
	vertex(650, 550);
	vertex(750, 600);
	vertex(650, 650);
	endShape();

	beginShape();
	vertex(650 + 600, 550);
	vertex(550 + 600, 600);
	vertex(650 + 600, 650);
	endShape();

	// mouth
	beginShape();
	vertex(700 + 62.5 * 0, 1050);
	vertex(700 + 62.5 * 1, 1000);
	vertex(700 + 62.5 * 2, 1050);
	vertex(700 + 62.5 * 3, 1000);
	vertex(700 + 62.5 * 4, 1050);
	vertex(700 + 62.5 * 5, 1000);
	vertex(700 + 62.5 * 6, 1050);
	vertex(700 + 62.5 * 7, 1000);
	vertex(700 + 62.5 * 8, 1050);
	endShape();
}

void happyFace() {
	noFill();
	stroke(230);
	strokeWeight(10);
	background(50);

	// eyes
	beginShape();
	vertex(600, 650);
	vertex(650, 550);
	vertex(700, 650);
	endShape();

	beginShape();
	vertex(600 + 600, 650);
	vertex(650 + 600, 550);
	vertex(700 + 600, 650);
	endShape();

	// mouth
	arc(950, 790, 500, 500, 0.6, PI-0.6);

}