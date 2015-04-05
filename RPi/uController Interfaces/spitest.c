/***********************************************************************
* Title:      SPI Test
* File Name:  spittest.c
* Author:     Tom Olenik
* Revision:   1.0
* 
* Description:
* This a test source to demonstrate using the serial peripheral
* interface (SPI) of the Raspberry Pi
***********************************************************************/
#include <stdio.h>
#include <bcm2835.h>

/* Declare functions */
void initialize();
void close();

/* Declare global variables */
char txBuffer[] = "This is a loop test";
char rxBuffer[sizeof(txBuffer)];  // Make rxBuffer same size as txBuffer

int main(int argc, char **argv)
{
	/* Do some stuff to figure out what version of RPi we are running
	 * on and set up to use the GPIO.*/
	printf("Initializing bcm2835.\n");
	if(!bcm2835_init())return 1;
	printf("Initialize bcm2835 successful.\n");
	
	/* Set up the SPI module */
	printf("Initializing SPI.\n");
	bcm2835_spi_begin();
	printf("Initialize SPI successful.\n");
	
	/* Call initialize() function */
	initialize();
	
	/* Print contents of txBuffer one char at a time */
	printf("Printing txBuffer:\n");
	for(int i = 0 ; i < sizeof(txBuffer) ; i++)
	{
		printf("%c", txBuffer[i]);
	}
	
	/* Send data from txBuffer and recieve data from rxBuffer */
	bcm2835_spi_transfernb(txBuffer, rxBuffer, sizeof(txBuffer));
	
	/* Print contents of rxBuffer one char at a time */
	for(int i = 0 ; i < sizeof(txBuffer) ; i++)
	{
		printf("%c", rxBuffer[i]);
	}
	
	return 0;
}

/***********************************************************************
 * Set up the GPIO and SPI module
 * ********************************************************************/
void initialize()
{
	
	
	/* Set the SPI endianness */
	bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST); 
	
	/* Set the SPI mode */
	bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);
	
	/* Set up the SPI clock or speed */
	bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_65536);
	
	/* Set chip select */
	bcm2835_spi_chipSelect(BCM2835_SPI_CS0);
	
	/* Set chip select polarity */
	bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);
}

/***********************************************************************
 * Deallocate SPI and GPIO resources before ending the program.
 * ********************************************************************/
void close()
{
	bcm2835_spi_end();
	bcm2835_close();
}

 
