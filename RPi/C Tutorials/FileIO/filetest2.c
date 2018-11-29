#include <time.h>
#include <stdio.h>

FILE *filePointer;

int main()
{
	time_t timeStamp; 	/* create container to hold time value */
	time(&timeStamp); 	/* fill timeStamp container by passing refernet to time() function */
    printf("It is now %d", (int)timeStamp); /* Print it */
 
    //filePointer = fopen(ctime(&timeStamp), "w");		/* Open file. Create it if it does not exist */
    //fprintf(filePointer, "\nThis is a test run at: "); 	/* Write to the file */
    //fprintf(filePointer, ctime(&timeStamp));			/* Write the time Stamp to the file */
    
    //fclose(filePointer); 	/* Close the file */
	return 0;
}

