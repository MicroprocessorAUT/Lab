#define __SFR_OFFSET 0
 
#include "avr/io.h"

.global start
.global led

start:

  sbi   DDRE,0  ; Set PE0 as output (port num: 0)
  sbi   DDRE,1  ; Set PE1 as output (port num: 1)
  sbi   DDRE,4  ; Set PE4 as output (port num: 2)
  sbi   DDRE,5  ; Set PE5 as output (port num: 3)
  sbi   DDRG,5  ; Set PG5 as output (port num: 4)
  sbi   DDRE,3  ; Set PE3 as output (port num: 5)

  CBI DDRB, 4    ; Set PB4 as Input
  SBI PORTB, 4   ; Enable pull-up resistor

  CBI DDRB, 5    ; Set PB5 as Input
  SBI PORTB, 5   ; Enable pull-up resistor

  CBI DDRB, 6    ; Set PB6 as Input
  SBI PORTB, 6   ; Enable pull-up resistor
  
  ret

led:

  L1: SBIS PINB, 4    ; Skips below statement if Push-button 1 is not pressed
      RJMP L2
      SBIS PINB, 5    ; Skips below statement if Push-button 2 is not pressed
      RJMP L3
      SBIS PINB, 6    ; Skips below statement if Push-button 3 is not pressed
      RJMP L4
      RJMP L1
   
  L2: ldi   r20,250  ; Set the delay duration in ms
      call  delay_n_ms
      sbi   PORTE,3  ; Turning on LED (PE3)
      sbi   PORTG,5  ; Turning on LED (PG5) 
      sbi   PORTE,5  ; Turning on LED (PE5)
      sbi   PORTE,4  ; Turning on LED (PE4) 
      sbi   PORTE,1  ; Turning on LED (PE1) 
      sbi   PORTE,0  ; Turning on LED (PE0) 

      ldi   r20,250      
      call  delay_n_ms  
      
      cbi   PORTE,3  ; Turning off LED (PE3)
      cbi   PORTG,5  ; Turning off LED (PG5)
      cbi   PORTE,5  ; Turning off LED (PE5)
      cbi   PORTE,4  ; Turning off LED (PE4)
      cbi   PORTE,1  ; Turning off LED (PE1)
      cbi   PORTE,0  ; Turning off LED (PE0)
      ret

   L3: sbi   PORTE,3    ; Turning on LED (PE3)
      call  delay_n_ms  
      sbi   PORTG,5     ; Turning on LED (PG5)
      call  delay_n_ms  
      sbi   PORTE,5     ; Turning on LED (PE5)
      call  delay_n_ms  
      sbi   PORTE,4     ; Turning on LED (PE4)
      call  delay_n_ms
      sbi   PORTE,1     ; Turning on LED (PE1)
      call  delay_n_ms
      sbi   PORTE,0     ; Turning on LED (PE0)
      ret

   L4: cbi   PORTE,3  
      cbi   PORTG,5  
      cbi   PORTE,5  
      cbi   PORTE,4  
      cbi   PORTE,1  
      cbi   PORTE,0  
      ret

delay_n_ms:
  ; Delay about r20*1ms. Destroys r20, r30, and r31.
  ; One millisecond is about 16000 cycles at 16MHz.
  ; The basic loop takes about 5 cycles, so we need about 3000 loops.
  ldi   31, 3000>>8 ; high(3000)
  ldi   30, 3000&255  ; low(3000)
  
delaylp:
  sbiw    r30, 1
  brne    delaylp
  subi    r20, 1
  brne    delay_n_ms
  ret
