#include <contador binario.h>

void initPins(){
   bit_set(TRISB, 0);
   bit_clear(TRISB, 1);
   bit_clear(TRISB, 2);
   bit_clear(TRISB, 3);
   bit_clear(TRISB, 4);
   
   bit_clear(PORTB, 1);
   bit_clear(PORTB, 2);
   bit_clear(PORTB, 3);
   bit_clear(PORTB, 4);
}

void contador(int i) {
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
          if (bit_test(PORTB, 0) == 1) {
              i = 0;
          }
          contador(i);
         delay_ms(250);
      }
   }
}