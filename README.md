# Mini_Project_TWO
Stop Watch
**Stop Watch System Implementation**

**Specifications:**

1. Utilize ATmega32 Microcontroller with a clock frequency of 1MHz.
2. Configure Timer1 in ATmega32 with CTC mode for measuring Stop Watch time.
3. Incorporate six Common Anode 7-segment displays.
4. Implement multiplexing technique to control the six 7-segment displays:
   - Use one 7447 decoder for all 7-segments.
   - Enable/disable each 7-segment using NPN BJT transistors connected to MCU pins.

5. Multiplexing Method:
   - Drive one 7-segment display at a time while others are off.
   - Switch displays using transistors, creating an illusion of a continuous display.
   - Persistence of vision gives the appearance of a normal display.

6. Connect 7447 decoder's 4 pins to the first 4 pins of PORTC.
7. Use the first 6 pins of PORTA for enable/disable pins of the six 7-segment displays.
8. Stop Watch counting initiates upon connecting power to the MCU.
9. Configure External Interrupt INT0 with a falling edge:
   - Connect a push button with internal pull-up resistor.
   - Upon detecting a falling edge, reset the Stop Watch time.

10. Configure External Interrupt INT1 with a rising edge:
   - Connect a push button with an external pull-down resistor.
   - Detecting a rising edge pauses the Stop Watch time.

11. Configure External Interrupt INT2 with a falling edge:
   - Connect a push button with an internal pull-up resistor.
   - Upon detecting a falling edge, resume the Stop Watch time.
