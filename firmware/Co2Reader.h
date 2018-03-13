#ifndef _CO2READER_H_
#define _CO2READER_H_

class Co2Reader {
public:
	Co2Reader(int co2_pin, int co2_calibrate_pin);

	void begin();
	void stop();
	void calibrate_begin();
	void calibrate_end();
	void caclulate_co2_concentration();
	int co2_level();

private: //methods
	void interrupt_handler();

private:
	int m_co2_pin;
	int m_co2_calibrate_pin;
	int m_co2_level;

	volatile unsigned long high_mark;
	volatile unsigned long duration;
};

#endif