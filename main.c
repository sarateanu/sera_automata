/*
 * sera.c
 *
 * Created: 6/15/2018 8:50:46 AM
 * Author : Mircea.Sarateanu
 */ 
#define F_CPU 2000000UL
#include <avr/io.h>
#include <avr/interrupt.h>


unsigned int temperatura;
unsigned int umiditate;
unsigned int lumina;

unsigned int temperatura_setata;
unsigned int umiditate_setata;
unsigned int lumina_setata;

static unsigned int dijit = 0;

void initializare_ADC()
{
	ADMUX = 0;
	ADMUX |= (1<<REFS0);//Vezi pagina 211 din datasheet Atmega16
	ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);//Enable ADC si stabilire factor divizare frecventa core cu 128
	
	
}

void afisare_LCD(unsigned int numar1, unsigned int numar2, unsigned int digit)
{
	unsigned int separat[3];
	unsigned int unitati, zeci, sute;
	unsigned int valoare, count, aux;
	valoare = numar1;
	count = 0;
	aux = 0;
	separat[0] = separat[1] = separat[2] = 0;
	while(valoare!=0)
	{
		aux = valoare % 10;
		valoare = valoare / 10;
		separat[count] = aux;
		count ++;
		
	}//END WHILE
	
	sute = separat[2];
	zeci = separat[1];
	unitati = separat[0];//Separa numarul in componente numar1
	
	
	
	
	
	
	
	
	
	
	if(digit == 0){
		PORTB |= (1<<PB3);//B4,B5,B6,B7
		PORTB &= ~((1<<PB4)|(1<<PB5)|(1<<PB6)|(1<<PB7));
		switch(unitati){
			
			case 0 : PORTC = 0b00111111;  break;
			case 1 : PORTC = 0b00000110;  break;
			case 2 : PORTC = 0b01011011;  break;
			case 3 : PORTC = 0b01001111;  break;
			case 4 : PORTC = 0b01100110;  break;
			case 5 : PORTC = 0b01101101;  break;
			case 6 : PORTC = 0b01111101;  break;
			case 7 : PORTC = 0b00000111;  break;
			case 8 : PORTC = 0b01111111;  break;
			case 9 : PORTC = 0b01101111;  break;
			
			
			
		}
		
	}//END IF
	if(digit == 1){
		PORTB |=(1<<PB4);
		PORTB &= ~((1<<PB3)|(1<<PB5)|(1<<PB6)|(1<<PB7));
		switch(zeci){
			
			case 0 : PORTC = 0b00111111;  break;
			case 1 : PORTC = 0b00000110;  break;
			case 2 : PORTC = 0b01011011;  break;
			case 3 : PORTC = 0b01001111;  break;
			case 4 : PORTC = 0b01100110;  break;
			case 5 : PORTC = 0b01101101;  break;
			case 6 : PORTC = 0b01111101;  break;
			case 7 : PORTC = 0b00000111;  break;
			case 8 : PORTC = 0b01111111;  break;
			case 9 : PORTC = 0b01101111;  break;
			
			
			
		}
		
		
		
	}
	
	if(digit == 2){
		PORTB |=(1<<PB5);
		PORTB &= ~((1<<PB3)|(1<<PB4)|(1<<PB6)|(1<<PB7));
		switch(sute){
			
			case 0 : PORTC = 0b00111111;  break;
			case 1 : PORTC = 0b00000110;  break;
			case 2 : PORTC = 0b01011011;  break;
			case 3 : PORTC = 0b01001111;  break;
			case 4 : PORTC = 0b01100110;  break;
			case 5 : PORTC = 0b01101101;  break;
			case 6 : PORTC = 0b01111101;  break;
			case 7 : PORTC = 0b00000111;  break;
			case 8 : PORTC = 0b01111111;  break;
			case 9 : PORTC = 0b01101111;  break;
			
			
			
		}
		
		
		
	}
	
	unsigned int separat1[3];
	unsigned int unitati1, zeci1, sute1;
	unsigned int valoare1, count1, aux1;
	valoare1 = numar2;
	count1 = 0;
	aux1 = 0;
	separat1[0] = separat1[1] = separat1[2] = 0;
	while(valoare1!=0)
	{
		aux1 = valoare1 % 10;
		valoare1 = valoare1 / 10;
		separat1[count1] = aux1;
		count1 ++;
		
	}//END WHILE
	
	sute1 = separat1[2];
	zeci1 = separat1[1];
	unitati1 = separat1[0];//Separa numarul in componente numar1
	
	if(digit == 3){
		PORTB |= (1<<PB6);
		PORTB &= ~((1<<PB3)|(1<<PB4)|(1<<PB5)|(1<<PB7));
		switch(unitati1){
			
			case 0 : PORTC = 0b00111111;  break;
			case 1 : PORTC = 0b00000110;  break;
			case 2 : PORTC = 0b01011011;  break;
			case 3 : PORTC = 0b01001111;  break;
			case 4 : PORTC = 0b01100110;  break;
			case 5 : PORTC = 0b01101101;  break;
			case 6 : PORTC = 0b01111101;  break;
			case 7 : PORTC = 0b00000111;  break;
			case 8 : PORTC = 0b01111111;  break;
			case 9 : PORTC = 0b01101111;  break;
			
			
			
		}
		
	}//END IF
	if(digit == 4){
		PORTB |=(1<<PB7);
		PORTB &= ~((1<<PB3)|(1<<PB4)|(1<<PB5)|(1<<PB6));
		switch(zeci1){
			
			case 0 : PORTC = 0b00111111;  break;
			case 1 : PORTC = 0b00000110;  break;
			case 2 : PORTC = 0b01011011;  break;
			case 3 : PORTC = 0b01001111;  break;
			case 4 : PORTC = 0b01100110;  break;
			case 5 : PORTC = 0b01101101;  break;
			case 6 : PORTC = 0b01111101;  break;
			case 7 : PORTC = 0b00000111;  break;
			case 8 : PORTC = 0b01111111;  break;
			case 9 : PORTC = 0b01101111;  break;
			
			
			
		}
		
		
		
	}
	
	
		
		
		
	}
	
	
	
//END FUNCTION


unsigned int citeste_ADC(int intrare)
{
	
	
	unsigned int rezultat;
	ADMUX = 0;
	ADMUX = (1<<REFS0);
	
	if(intrare == 0)
	{
		ADMUX |=(1<<REFS0);
		ADCSRA |= (1<<ADSC);
		while((ADCSRA & (1<<ADIF))==0)
		{
			//Asteapta sfarsitul conversiei
			
		}
		
		rezultat = ADCL + (ADCH*256);
	}
	
	
	if(intrare == 1)
	{
		ADMUX |=(1<<REFS0)|(1<<MUX0);
		ADCSRA |= (1<<ADSC);
		while((ADCSRA & (1<<ADIF))==0)
		{
			//Asteapta sfarsitul conversiei
			
		}
		
		rezultat = ADCL + (ADCH*256);
		
	}
	
	if(intrare == 2)
	{
		ADMUX |=(1<<REFS0)|(1<<MUX1);
		ADCSRA |= (1<<ADSC);
		while((ADCSRA & (1<<ADIF))==0)
		{
			//Asteapta sfarsitul conversiei
			
		}
		
		rezultat = ADCL + (ADCH*256);
		
	}
	
	if(intrare == 3)
	{
		ADMUX |=(1<<REFS0)|(1<<MUX0)|(1<<MUX1);
		ADCSRA |= (1<<ADSC);
		while((ADCSRA & (1<<ADIF))==0)
		{
			//Asteapta sfarsitul conversiei
			
		}
		
		rezultat = ADCL + (ADCH*256);
		
	}
	
	if(intrare == 4)
	{
		ADMUX |=(1<<REFS0)|(1<<MUX2);
		ADCSRA |= (1<<ADSC);
		while((ADCSRA & (1<<ADIF))==0)
		{
			//Asteapta sfarsitul conversiei
			
		}
		
		rezultat = ADCL + (ADCH*256);
		
	}
	
	if(intrare == 5)
	{
		ADMUX |=(1<<REFS0)|(1<<MUX2)|(1<<MUX0);
		ADCSRA |= (1<<ADSC);
		while((ADCSRA & (1<<ADIF))==0)
		{
			//Asteapta sfarsitul conversiei
			
		}
		
		rezultat = ADCL + (ADCH*256);
		
	}
	
	
	return rezultat;
}


void compute_data(unsigned int data){
	
	switch(data){
		
		case 0 : {PORTD = 0b00000001;break;}
		case 1 : {PORTD = 0b00000011;break;}
		case 2 : {PORTD = 0b00000111;break;}
		case 3 : {PORTD = 0b00001111;break;}
		case 4 : {PORTD = 0b00011111;break;}
		case 5 : {PORTD = 0b00111111;break;}
		case 6 : {PORTD = 0b01111111;break;}
		case 7 : {PORTD = 0b11111111;break;}							
		
		
		
		
		
	}	
	
	
	
	
}



ISR(TIMER0_OVF_vect, ISR_BLOCK){
	
	if((PINA&(1<<PA7))==0){
	bargraph(umiditate_setata, 0);
	afisare_LCD(lumina_setata, temperatura_setata, dijit);
	}
	
		else{
	bargraph(umiditate, 0);
	afisare_LCD(lumina, temperatura, dijit);
	
	}
	dijit ++;
	
	if(dijit>4){dijit = 0;}
	
	
}


ISR(TIMER1_OVF_vect){
	
	
	temperatura = citeste_ADC(0)/6.82;
	umiditate= citeste_ADC(1)/100;
	lumina = citeste_ADC(2)/3;
	
	temperatura_setata = citeste_ADC(3)/10.33;
	umiditate_setata = citeste_ADC(4)/146.16;
	lumina_setata = citeste_ADC(5)/5.11;
	
	
	
	
	
}

void bargraph(unsigned int valoare, unsigned int id)
{
	
	//Pentru bargraph avem portc pentru multiplexare PC0 - bar1, PC1 - bar 2, PC3 - bar 3
	//Datele se trimit pe portd
	
	switch(id){
		
	case 0 : {if(valoare<=7){compute_data(valoare);}else{compute_data(7);};break;}
	case 1 : {if(valoare<=7){compute_data(valoare);}else{compute_data(7);};break;}
	case 2 : {if(valoare<=7){compute_data(valoare);}else{compute_data(7);};break;}			
		
			
		
	}

	
}





int main(void)
{
	
	DDRA = 0x00;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	
	sei();
	initializare_ADC();
	
	TIMSK |= (1<<TOIE0)|(1<<TOIE2)|(1<<TOIE1);
	
	TCCR0 = 0;
	TCCR0 |= (1<<CS01);//Timer0 pe 8b biti pentru afisare pe bargraph CLK/8
	
	
	TCCR1A = 0;
	TCCR1B |= (1<<CS10);//timer1 pe 16 biti pentru achizitie de date
	
    /* Replace with your application code */
    while (1) 
    {
		
		if(temperatura > temperatura_setata){PORTB |=(1<<PB0);}
			else{PORTB &=~(1<<PB0);}
				
				if(umiditate > umiditate_setata){PORTB &=~(1<<PB1);}
					else {PORTB |=(1<<PB1);}
						
						if(lumina > lumina_setata){PORTB |=(1<<PB2);}
							else {PORTB &=~(1<<PB2);}
    }
}

