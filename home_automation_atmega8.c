#include<avr/io.h>
/*Includes io.h header file where all the Input/Output Registers and its Bits are defined for all AVR microcontrollers*/

#define	F_CPU	8000000
/*Defines a macro for the delay.h header file. F_CPU is the microcontroller frequency value for the delay.h header file. Default value of F_CPU in delay.h header file is 1000000(1MHz)*/

#include<util/delay.h>
/*Includes delay.h header file which defines two functions, _delay_ms (millisecond delay) and _delay_us (microsecond delay)*/

/*USART Function Declarations*/
void usart_init();
void usart_data_transmit(unsigned char data );
unsigned char usart_data_receive( void );
void usart_string_transmit(char *string);

int main(void)
{
	DDRB=0x0f; 
	/*PB0,PB1,PB2 and PB3 pins of PortB are declared output (4 Relays are connected)*/
	
	char usart_received_data;
	/*Variable declaration*/

	usart_init();
	/*USART initialization*/

	usart_string_transmit("Rajesh Ku Mandal");
	/*Transmits string to PC*/

	usart_data_transmit(0x0d);
	/*Transmits Carriage return to PC for new line*/

	usart_string_transmit("Data Scientist");
	/*Transmits string to PC*/

	usart_data_transmit(0x0d);
	/*Transmits Carriage return to PC for new line*/

	usart_string_transmit("Control Keys for Appliances:");
	/*Transmits string to PC*/

	usart_data_transmit(0x0d);
	/*Transmits Carriage return to PC for new line*/

	usart_string_transmit("1=Appliance 1 ON");
	/*Transmits string to PC*/

	usart_data_transmit(0x0d);
	/*Transmits Carriage return to PC for new line*/

	usart_string_transmit("2=Appliance 1 OFF");
	/*Transmits string to PC*/

	usart_data_transmit(0x0d);
	/*Transmits Carriage return to PC for new line*/

	usart_string_transmit("3=Appliance 2 ON");
	/*Transmits string to PC*/

	usart_data_transmit(0x0d);
	/*Transmits Carriage return to PC for new line*/

	usart_string_transmit("4=Appliance 2 OFF");
	/*Transmits string to PC*/

	usart_data_transmit(0x0d);
	/*Transmits Carriage return to PC for new line*/
	
	usart_string_transmit("5=Appliance 3 ON");
	/*Transmits string to PC*/

	usart_data_transmit(0x0d);
	/*Transmits Carriage return to PC for new line*/

	usart_string_transmit("6=Appliance 3 OFF");
	/*Transmits string to PC*/

	usart_data_transmit(0x0d);
	/*Transmits Carriage return to PC for new line*/
	
	usart_string_transmit("7=Appliance 4 ON");
	/*Transmits string to PC*/

	usart_data_transmit(0x0d);
	/*Transmits Carriage return to PC for new line*/

	usart_string_transmit("8=Appliance 4 OFF");
	/*Transmits string to PC*/

	usart_data_transmit(0x0d);
	/*Transmits Carriage return to PC for new line*/
	
	usart_string_transmit("9=All Appliances ON");
	/*Transmits string to PC*/

	usart_data_transmit(0x0d);
	/*Transmits Carriage return to PC for new line*/

	usart_string_transmit("0=All Appliances OFF");
	/*Transmits string to PC*/

	usart_data_transmit(0x0d);
	/*Transmits Carriage return to PC for new line*/

	/*Start of infinite loop*/
	while(1)
	{
		usart_received_data=usart_data_receive();
		/*Microcontroller receives data from PC */
		
		/*Checking the pressed key to Turn ON and OFF appliances*/
		if(usart_received_data == '1')
		{
			PORTB|=0x01;
			/*Appliance 1 is ON*/

			usart_string_transmit("Appliance 1 is ON");
			/*Transmits string to PC*/
		}
		else if(usart_received_data == '2')
		{
			PORTB&=~(0x01);
			/*Appliance 1 is OFF*/

			usart_string_transmit("Appliance 1 is OFF");
			/*Transmits string to PC*/
		}
		else if(usart_received_data == '3')
		{
			PORTB|=0x02;
			/*Appliance 2 is ON*/

			usart_string_transmit("Appliance 2 is ON");
			/*Transmits string to PC*/
		}
		else if(usart_received_data == '4')
		{
			PORTB&=~(0x02);
			/*Appliance 2 is OFF*/

			usart_string_transmit("Appliance 2 is OFF");
			/*Transmits string to PC*/
		}
		else if(usart_received_data == '5')
		{
			PORTB|=0x04;
			/*Appliance 3 is ON*/

			usart_string_transmit("Appliance 3 is ON");
			/*Transmits string to PC*/
		}
		else if(usart_received_data == '6')
		{
			PORTB&=~(0x04);
			/*Appliance 3 is OFF*/

			usart_string_transmit("Appliance 3 is OFF");
			/*Transmits string to PC*/
		}
		else if(usart_received_data == '7')
		{
			PORTB|=0x08;
			/*Appliance 4 is ON*/

			usart_string_transmit("Appliance 4 is ON");
			/*Transmits string to PC*/
		}
		else if(usart_received_data == '8')
		{
			PORTB&=~(0x08);
			/*Appliance 4 is OFF*/

			usart_string_transmit("Appliance 4 is OFF");
			/*Transmits string to PC*/
		}
		else if(usart_received_data == '9')
		{
			PORTB=0x0f;
			/*All Appliances are ON*/

			usart_string_transmit("All Appliances are ON");
			/*Transmits string to PC*/
		}
		else if(usart_received_data == '0')
		{
			PORTB=0x00;
			/*All Appliances are OFF*/

			usart_string_transmit("All Appliances are OFF");
			/*Transmits string to PC*/
		}
		else
		{
			;
			/*Null statement*/
		}

		usart_data_transmit(0x0d);
		/*Transmitting Carriage return to PC for new line*/
	}
}
/*End of program*/

/*USART Function Definitions*/
void usart_init()
{
	UBRRH = 0;
	UBRRL =51;
	UCSRB|= (1<<RXEN)|(1<<TXEN);
	UCSRC |= (1 << URSEL)|(3<<UCSZ0);
}


void usart_data_transmit(unsigned char data )
{
	while ( !( UCSRA & (1<<UDRE)) )
	;
	UDR = data;
	_delay_ms(1);
}

unsigned char usart_data_receive( void )
{
	while ( !(UCSRA & (1<<RXC)) )
	;
	return UDR;
}

void usart_string_transmit(char *string)
{
	while(*string)
	{
		usart_data_transmit(*string++);
	}
}

