#define LEDPORT1 PORTE
#define LEDPORT2 PORTG
#define BUTTONPORT PORTB
#define BUTTONPORT_DIR DDRB
#define LEDPORT_DIR1 DDRE
#define LEDPORT_DIR2 DDRG
#define BUTTONPIN PINB

void setup()   {

  asm volatile (

    "  sbi   %[portdir1],0  \n"
    "  sbi   %[portdir1],1  \n"
    "  sbi   %[portdir1],4  \n"
    "  sbi   %[portdir1],5 \n"
    "  sbi   %[portdir2],5  \n"
    "  sbi   %[portdir1],3  \n"

    "  CBI %[buttondir], 4   \n"
    "  SBI %[port], 4  \n"

     :
     : [portdir1] "I" (_SFR_IO_ADDR(LEDPORT_DIR1)),
       [portdir2] "I" (_SFR_IO_ADDR(LEDPORT_DIR2)),
       [buttondir] "I" (_SFR_IO_ADDR(BUTTONPORT_DIR)),
       [port] "I" (_SFR_IO_ADDR(BUTTONPORT))
      );
}


void loop()                    
{
  asm volatile(
    " L1: SBIS %[pin], 4  \n"
    "     RJMP L2       \n"
    "     RJMP L1       \n"

    " L2: sbi   %[port1],3  \n"
    "     call  delay_n_ms  \n"
    "     sbi   %[port2],5  \n"
    "     call  delay_n_ms  \n"
    "     sbi   %[port1],5  \n"
    "     call  delay_n_ms  \n"
    "     sbi   %[port1],4  \n"
    "     call  delay_n_ms  \n"
    "     sbi   %[port1],1  \n"
    "     call  delay_n_ms  \n"
    "     sbi   %[port1],0  \n"
    "     ret  \n"

    " delay_n_ms:  \n"
    "   ldi   31, 3000>>8  \n"
    "   ldi   30, 3000&255   \n"
  
    " delaylp:   \n"
    "   sbiw    r30, 1 \n"
    "   brne    delaylp \n"
    "   subi    r20, 1 \n"
    "   brne    delay_n_ms \n"
    "   ret  \n"
    
    :
    : [pin] "I" (_SFR_IO_ADDR(BUTTONPIN)),
      [port1] "I" (_SFR_IO_ADDR(LEDPORT1)),
      [port2] "I" (_SFR_IO_ADDR(LEDPORT2)) 
    );
}
