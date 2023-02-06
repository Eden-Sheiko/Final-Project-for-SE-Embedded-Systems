# Final-Project-for-SE-Embedded-Systems

## Project Summary
This project aims to verify the hardware of the STM32F746ZG board by testing its peripherals: TIMER, UART, SPI, I2C, ADC, and Eth (MAC & PHY) through a client-server program. The testing program on a Linux machine will send commands to the UUT (Unit Under Test) using a proprietary protocol over UDP/IP. The UUT will receive the command and initiate the appropriate tests for each peripheral and send back the results to the testing program on the Linux machine.

## Proprietary Protocols
The command sent from the Linux machine will include a Test-ID, peripheral being tested, number of iterations, bit pattern length, and the bit pattern. The result sent from the UUT back to the Linux machine will contain the Test-ID and the result (1 for success, 0xff for failure).

## P.C. Testing Program
The testing program on the Linux machine will be implemented using CLI (Command Line Interface) in C/C++ and will have persistent testing records saved on the file system, including the Test-ID, date/time, test length, and result.

## UUT Testing Program
The UUT testing program will receive the test command from the Linux machine, acquire the necessary parameters, and initiate the appropriate tests for each peripheral. The tests for UART, I2C, and SPI will use DMA mode if possible. The testing program will compare the incoming data with the sent data, and a success result will be sent to the Linux machine if all iterations are successful, otherwise, a failure result will be sent.
