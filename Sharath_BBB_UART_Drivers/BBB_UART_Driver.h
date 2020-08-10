/*
 * BBB_UART_Driver.h
 *
 *  Created on: Aug 7, 2020
 *      Author: sharath
 */

#ifndef BBB_UART_DRIVER_H_
#define BBB_UART_DRIVER_H_

#include <termios.h>
#include <stdio.h>
#include <string.h>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

#define UART_PATH "/dev/"

void configure_UART(char* ttyOx, struct termios *termios_p,speed_t baud_rate);

void UART_send(char* ttyOx,unsigned char* msg,size_t size);

int UART_Recieve(char* ttyOx,char* read_buf,size_t size);

#endif /* BBB_UART_DRIVER_H_ */
