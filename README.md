# Final-Project-for-SE-Embedded-Systems
STM32F746xx server - client.


Project Summary:

The goal of this project is to verify the hardware of the STM32F746ZG card by testing its peripherals: TIMER, UART, SPI, I2C, ADC, and Eth (MAC & PHY). The testing procedure will be conducted through a client-server program, where the testing program on the P.C. will send commands to the UUT (Unit Under Test) using a proprietary protocol over UDP/IP. The UUT will receive the command and initiate the appropriate tests for each peripheral, and the results will be sent back to the P.C. testing program.

Proprietary Protocols:

The command sent from the P.C. will include a Test-ID, the peripheral being tested, number of iterations, bit pattern length, and the bit pattern. The result sent from the UUT back to the P.C. will contain the Test-ID and the result (1 for success, 0xff for failure).

P.C. Testing Program:

The P.C. testing program will be implemented using CLI (Command Line Interface) in C/C++ on a Linux machine. It will have persistent testing records saved on the file system, including the Test-ID, date/time, test length, and result.

UUT Testing Program:

The UUT testing program will receive the test command from the P.C., acquire the necessary parameters, and initiate the appropriate tests for each peripheral. The tests for UART, I2C, and SPI will use DMA mode if possible, with parameters chosen at the discretion of the implementation. The testing program will send the received bit pattern to the UART0, which will then be passed to the UART1 on the UUT. The UUT will send the received string back to UART0, and the UUT testing program will compare the incoming data to the sent data. A success result will be sent to the P.C. if all iterations are successful, otherwise a failure result will be sent.
