/*
 * BBB_UART_Driver.c
 *
 *  Created on: Aug 7, 2020
 *      Author: sharath
 */

//Local Libs
#include"BBB_UART_Driver.h"

// C library headers
#include <stdio.h>
#include <string.h>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()



void configure_UART(char* ttyOx, struct termios *termios_p,speed_t baud_rate)
{
	char buf[50];

	sprintf(buf,UART_PATH"%s",ttyOx);
	// Open the serial port. Change device path as needed (currently set to an standard FTDI USB-UART cable type device)
	int serial_port = open(buf, O_RDWR);

	// Set in/out baud rate
	cfsetispeed(termios_p, baud_rate);
	cfsetospeed(termios_p, baud_rate);

	// Save tty settings, also checking for error
	if (tcsetattr(serial_port, TCSANOW, termios_p) != 0) {
	    printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
	}

	close(serial_port);
}

void UART_send(char* ttyOx,unsigned char* msg,size_t size)
{
	char buf[50];

	sprintf(buf,UART_PATH"%s",ttyOx);
	// Open the serial port. Change device path as needed (currently set to an standard FTDI USB-UART cable type device)
	int serial_port = open(buf, O_RDWR);

	write(serial_port, msg, size);

	close(serial_port);
}

// Read bytes. The behaviour of read() (e.g. does it block?,
// how long does it block for?) depends on the configuration
// settings above, specifically VMIN and VTIME

int UART_Recieve(char* ttyOx,char* read_buf,size_t size)
{
	char buf[50];

	sprintf(buf,UART_PATH"%s",ttyOx);
	// Open the serial port. Change device path as needed (currently set to an standard FTDI USB-UART cable type device)
	int serial_port = open(buf, O_RDWR);

	int num_bytes = read(serial_port, read_buf, size);

	// n is the number of bytes read. n may be 0 if no bytes were received, and can also be -1 to signal an error.
	if (num_bytes < 0) {
	    printf("Error reading: %s", strerror(errno));
	}

	close(serial_port);
	return num_bytes;
}
