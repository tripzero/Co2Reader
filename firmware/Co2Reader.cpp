#include "Co2Reader.h"


Co2Reader::Co2Reader(int co2_pin, int co2_calibrate_pin)
:m_co2_pin(co2_pin), m_co2_calibrate_pin(co2_calibrate_pin), m_co2_level(0),
high_mark(0), duration(0)
{
	pinMode(m_co2_pin, INPUT_PULLDOWN);
    pinMode(m_co2_calibrate_pin, OUTPUT);
    digitalWrite(m_co2_calibrate_pin, HIGH);
}

void Co2Reader::begin()
{
	attachInterrupt(m_co2_pin, &Co2Reader::interrupt_handler, this, CHANGE);
}

void Co2Reader::stop()
{
	detatchInterrupt(m_co2_pin);
}

/**
 * calibration is done by pulling down the calibration pin on the S8, waiting
 * for 4 seconds and then setting it high again.  calibrate_end() must be
 * called within a minimum of 4 and a maxiumum of 8 seconds after calling 
 * calibrate_begin()
 * 
**/
void Co2Reader::calibrate_begin()
{
	// pull down the calibration pin:
    digitalWrite(co2CalPin, LOW);
}

void Co2Reader::calibrate_end()
{
	// pull down the calibration pin:
    digitalWrite(co2CalPin, LOW);
}

void Co2Reader::caclulate_co2_concentration()
{
	m_co2_level = (duration / 1000.0) * 1600.0 + 400;
}

int Co2Reader::co2_level()
{
	return m_co2_level;
}

void Co2Reader::interrupt_handler()
{
	if(digitalRead(m_co2_pin) == HIGH)
    {
        high_mark = micros();
    }
    else
    {
        duration = micros() - highMark;
    }
}