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
	/*******************************************************************
	 * The folowing section is pulled from the bcm2835_init() function 
	 * for troubleshooting.
	 * ****************************************************************/
	volatile uint32_t* paddr;
	/* Set the SPI0 pins to the Alt 0 function to enable SPI0 access on them */
	printf("Setting CE1 pin function.\n");
    //bcm2835_gpio_fsel(RPI_GPIO_P1_26, BCM2835_GPIO_FSEL_ALT0); /* CE1 */
    /** Entering into bcm2835_gpio_fsel() **/
    /* Function selects are 10 pins per 32 bit word, 3 bits per pin */
    paddr = bcm2835_gpio + BCM2835_GPFSEL0/4 + (RPI_GPIO_P1_26/10);
    printf("Register value = %p\n", paddr);
    uint8_t   shift = (RPI_GPIO_P1_26 % 10) * 3;
    printf("shift = %u\n", shift);
    uint32_t  mask = BCM2835_GPIO_FSEL_MASK << shift;
    printf("mask = %u\n", mask);
    uint32_t  value = BCM2835_GPIO_FSEL_ALT0 << shift;
    printf("value = %u\n", value);
    bcm2835_peri_set_bits(paddr, value, mask);
    /** End bcm2835_gpio_fsel() **/
    
    printf("Setting CE0 pin function.\n");
    bcm2835_gpio_fsel(RPI_GPIO_P1_24, BCM2835_GPIO_FSEL_ALT0); /* CE0 */
    printf("Setting MISO pin function.\n");
    bcm2835_gpio_fsel(RPI_GPIO_P1_21, BCM2835_GPIO_FSEL_ALT0); /* MISO */
    printf("Setting MOSI pin function.\n");
    bcm2835_gpio_fsel(RPI_GPIO_P1_19, BCM2835_GPIO_FSEL_ALT0); /* MOSI */
    printf("Setting CLK pin function.\n");
    bcm2835_gpio_fsel(RPI_GPIO_P1_23, BCM2835_GPIO_FSEL_ALT0); /* CLK */
    
    /* Set the SPI CS register to the some sensible defaults */
    paddr = bcm2835_spi0 + BCM2835_SPI0_CS/4;
    bcm2835_peri_write(paddr, 0); /* All 0s */
    
    /* Clear TX and RX fifos */
    bcm2835_peri_write_nb(paddr, BCM2835_SPI0_CS_CLEAR);
	/**********End pull from bcm2835_init()*****************/
	
	///* Set up the SPI module */
	//printf("Initializing SPI.\n");
	//bcm2835_spi_begin();
	//printf("Initialize SPI successful.\n");
	
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

 
