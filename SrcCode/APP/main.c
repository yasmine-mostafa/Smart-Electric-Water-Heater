
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "temp_elements.h"
#include "temp_sensor.h"
#include "up_down.h"
#include "heating_led.h"
#include "seven_seg.h"
#include "timers.h"
#include "External_EEPROM.h"

uint16 set_temp=60;
uint16* t=& set_temp;
uint8 test = 11;

uint8 ButtonCounter = 0;
uint8 Timer0Counter1 = 0;
uint8 Timer0Counter2 = 0;
uint8 Timer2Counter = 0;

uint8 TempSettingsStatus = 0; // For Temperature Setting Mode
uint8 HeaterStatus = 0;

int status_flag=0;
int *f=&status_flag;
int flag=0;
int c=0;

/*
ISR(TIMER0_OVF_vect) // (1sec) Heating Element LED & Seven Segment Blinking
{
	//led_heatingBlink(&Timer0Counter1, &HeaterStatus);
	//led_heatingBlink(&Timer0Counter1);
	SevenSegBlink(&Timer0Counter2, TempSettingsStatus);
}

ISR(TIMER2_OVF_vect) // (100ms) Sensor Updating
{

}

ISR(TIMER1_OVF_vect)
{

}

*/

int main(void)
{
	SetPinDir(Group_B,PIN1,PIN_OUTPUT);
	SetPinVal(Group_B,PIN1,PIN_LOW);
	button_init();
	sensor_Init();
	led_init();
	button_init();
	SevenSegInit();
	//EEPROM_Init();
	//Timer0Init();
	//Timer2Init();
	flag=1;
	sei();

	int temperature;

	DisplayTemp(set_temp);

	while (1)
	{
		if((PINB>>2)&0x01)
		{
			_delay_ms(100);
			if((PINB>>2)&0x01)
			{
		      status_flag=!status_flag;
			}
		}


		while(status_flag==1)
		{
			//SevenSegInit();

			temperature=temp_calc();
			DisplayTemp(temperature);
			temp_regulation(temperature,set_temp);
		}

		    heating_element_disable();
		    cooling_element_disable();
		    led_disable();
		    //ClearSevenSeg();
		   // button_disable();
		    EEPROM_Write_Byte(0x00,set_temp);
		}



	}

ISR(INT0_vect)
{
	if(flag==1)
	{
		button_up(t, &ButtonCounter, &TempSettingsStatus);
     DisplayTemp(set_temp);

	}

}

ISR(INT1_vect)
{
		button_down(t, &ButtonCounter, &TempSettingsStatus);
		DisplayTemp(set_temp);
}

ISR(INT2_vect)
{
	SetPinVal(Group_B,PIN2,PIN_HIGH);

		change_status(f);
		//EEPROM_Read_Byte(0x00,set_temp);


}
