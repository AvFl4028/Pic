#include <placa de prueba.h>

#byte TRISB = 0x86
#byte PORTB = 0x06

#define CAMBIO PORTB, 0

#define led1 PORTB, 1
#define led2 PORTB, 2
#define led3 PORTB, 3
#define led4 PORTB, 4

#define CAMBIO_BTN PORTB, 5

boolean cambio_bool;

void initPins()
{
   bit_clear(TRISB, 0);
   bit_clear(TRISB, 1);
   bit_clear(TRISB, 2);
   bit_clear(TRISB, 3);
   bit_clear(TRISB, 4);
   
   bit_set(TRISB, 5);
   
   bit_clear(led1);
   bit_clear(led2);
   bit_clear(led3);
   bit_clear(led4);
   
   bit_clear(CAMBIO);
}

void contador(int i) 
{
    switch (i) {
    case 0:
        bit_clear(PORTB, 1);
        bit_clear(PORTB, 2);
        bit_clear(PORTB, 3);
        bit_clear(PORTB, 4);
        break;

    case 1:
        bit_set(PORTB, 1);
        bit_clear(PORTB, 2);
        bit_clear(PORTB, 3);
        bit_clear(PORTB, 4);
        break;

    case 2:
        bit_clear(PORTB, 1);
        bit_set(PORTB, 2);
        bit_clear(PORTB, 3);
        bit_clear(PORTB, 4);
        break;

    case 3:
        bit_set(PORTB, 1);
        bit_set(PORTB, 2);
        bit_clear(PORTB, 3);
        bit_clear(PORTB, 4);
        break;

    case 4:
        bit_clear(PORTB, 1);
        bit_clear(PORTB, 2);
        bit_set(PORTB, 3);
        bit_clear(PORTB, 4);
        break;

    case 5:
        bit_set(PORTB, 1);
        bit_clear(PORTB, 2);
        bit_set(PORTB, 3);
        bit_clear(PORTB, 4);
        break;

    case 6:
        bit_clear(PORTB, 1);
        bit_set(PORTB, 2);
        bit_set(PORTB, 3);
        bit_clear(PORTB, 4);
        break;

    case 7:
        bit_set(PORTB, 1);
        bit_set(PORTB, 2);
        bit_set(PORTB, 3);
        bit_clear(PORTB, 4);
        break;

    case 8:
        bit_clear(PORTB, 1);
        bit_clear(PORTB, 2);
        bit_clear(PORTB, 3);
        bit_set(PORTB, 4);
        break;

    case 9:
        bit_set(PORTB, 1);
        bit_clear(PORTB, 2);
        bit_clear(PORTB, 3);
        bit_set(PORTB, 4);
        break;

    case 10:
        bit_clear(PORTB, 1);
        bit_set(PORTB, 2);
        bit_clear(PORTB, 3);
        bit_set(PORTB, 4);
        break;

    case 11:
        bit_set(PORTB, 1);
        bit_set(PORTB, 2);
        bit_clear(PORTB, 3);
        bit_set(PORTB, 4);
        break;

    case 12:
        bit_clear(PORTB, 1);
        bit_clear(PORTB, 2);
        bit_set(PORTB, 3);
        bit_set(PORTB, 4);
        break;

    case 13:
        bit_set(PORTB, 1);
        bit_clear(PORTB, 2);
        bit_set(PORTB, 3);
        bit_set(PORTB, 4);
        break;

    case 14:
        bit_clear(PORTB, 1);
        bit_set(PORTB, 2);
        bit_set(PORTB, 3);
        bit_set(PORTB, 4);
        break;

    case 15:
        bit_set(PORTB, 1);
        bit_set(PORTB, 2);
        bit_set(PORTB, 3);
        bit_set(PORTB, 4);
        break;
    default:
        break;
    }
}

void main()
{
   initPins();
   while(TRUE)
   {
      for(int i = 0; i < 16; i++){
         if(bit_test(CAMBIO_BTN) == 1){
            if(cambio_bool){
            bit_set(CAMBIO);
            cambio_bool = 0;
            }else if(!cambio_bool){
            bit_clear(CAMBIO);
            cambio_bool = 1;
            }
         }
         contador(i);
         delay_ms(50);
      }
   }
}
