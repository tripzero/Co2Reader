#include <Co2Reader.h>

Co2Reader co2Reader(D2, D3);

void setup()
{
	/// Calibrate the sensor.  Air should be 400ppm
	/// Do this periodically for best results.
	/// The s8 can automatically correct for drift
	/// so this is not always necessary.

	co2Reader.calibrate_begin();

	delay(4500); //wait 4.5 seconds
	
	co2Reader.calibrate_end();

	/// Start reading data
	co2Reader.begin();
}

void loop()
{
	co2Reader.caclulate_co2_concentration();
	delay(10000);
}
