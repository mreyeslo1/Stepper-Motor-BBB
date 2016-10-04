#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
#include <unistd.h>     //close()  
#include <fcntl.h>     //define O_WONLY and O_RDONLY  


#define MAX_BUF 64     //This is plenty large  
/*
L	L	Full Step (2 Phase)
H	L	Half Step
L	H	Quarter Step
H	H	Eigth Step
*/
void led_out(int adc_in){
	printf("led out = %d \n", adc_in);
	
	if (adc_in >1400 ) { 
		system("echo 1 > /sys/class/gpio/gpio67/value");
		system("echo 1 > /sys/class/gpio/gpio68/value");
		system("echo 1 > /sys/class/gpio/gpio44/value");
		system("echo 1 > /sys/class/gpio/gpio26/value");
	}
	else if (adc_in >1000 ) {
		system("echo 1 > /sys/class/gpio/gpio67/value");
		system("echo 1 > /sys/class/gpio/gpio68/value");
		system("echo 1 > /sys/class/gpio/gpio44/value");
		system("echo 0 > /sys/class/gpio/gpio26/value");
	}
	else if (adc_in >600 ) {
		system("echo 1 > /sys/class/gpio/gpio67/value");
		system("echo 1 > /sys/class/gpio/gpio68/value");
		system("echo 0 > /sys/class/gpio/gpio44/value");
		system("echo 0 > /sys/class/gpio/gpio26/value");
	}
	
	else if (adc_in >200 ) {
		system("echo 1 > /sys/class/gpio/gpio67/value");
		system("echo 0 > /sys/class/gpio/gpio68/value");
		system("echo 0 > /sys/class/gpio/gpio44/value");
		system("echo 0 > /sys/class/gpio/gpio26/value");
	}
	
	 else if (adc_in >0 ) {
		system("echo 0 > /sys/class/gpio/gpio67/value");
		system("echo 0 > /sys/class/gpio/gpio68/value");
		system("echo 0 > /sys/class/gpio/gpio44/value");
		system("echo 0 > /sys/class/gpio/gpio26/value");
	}
		
	}

 
//button for manual mode 
int readBTN()  
 {  
      int fd;          //file pointer  
      char buf[MAX_BUF];     //file buffer  
      char val[1];     //holds up to1 in put
      

      snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio65/value");     //open value file 
      
      fd = open(buf, O_RDONLY);
      
      read(fd, &val, 1);     //readbtn in 
	  usleep(50000);
      close(fd);     //close file and stop reading  
      return atoi(val);     //returns an integer value (rather than ascii)  
 }

void mode1(){
	
	printf("mode 1 \n" );
	////led bar out
	
	system("echo 1 > /sys/class/gpio/gpio67/value");
	system("echo 0 > /sys/class/gpio/gpio68/value");
	system("echo 0 > /sys/class/gpio/gpio44/value");
	system("echo 0 > /sys/class/gpio/gpio26/value");
	
	//MS1
    system("echo 0 > /sys/class/gpio/gpio66/value");
    //MS2
	system("echo 0 > /sys/class/gpio/gpio69/value");
	
	
	int ITER;
	while( readBTN() != 1){
	system("echo 0 > /sys/class/gpio/gpio27/value");
	for(ITER= 0; ITER<210; ITER++)  
	  {	
	  	system("echo 1 > /sys/class/gpio/gpio47/value");
	  	usleep(1);
		system("echo 0 > /sys/class/gpio/gpio47/value");
		usleep(1);

	  }
	system("echo 1 > /sys/class/gpio/gpio27/value");
	for(ITER= 0; ITER<210; ITER++)  
	  {	
	  	system("echo 1 > /sys/class/gpio/gpio47/value");
	  	usleep(1);
		system("echo 0 > /sys/class/gpio/gpio47/value");
		usleep(1);
	  }
	}
}

void mode2(){
	
	printf("mode 2 \n" );
	//MS1
    system("echo 1 > /sys/class/gpio/gpio66/value");
    //MS2
	system("echo 0 > /sys/class/gpio/gpio69/value");
	
	////led bar out
	system("echo 1 > /sys/class/gpio/gpio67/value");
	system("echo 1 > /sys/class/gpio/gpio68/value");
	system("echo 0 > /sys/class/gpio/gpio44/value");
	system("echo 0 > /sys/class/gpio/gpio26/value");
	
	int ITER;
	while( readBTN() != 1){
	system("echo 0 > /sys/class/gpio/gpio27/value");
	for(ITER= 0; ITER<420; ITER++)  
	  {	
	  	system("echo 1 > /sys/class/gpio/gpio47/value");
	  	usleep(1);
		system("echo 0 > /sys/class/gpio/gpio47/value");

	  }
	system("echo 1 > /sys/class/gpio/gpio27/value");
	for(ITER= 0; ITER<420; ITER++)  
	  {	
	  	system("echo 1 > /sys/class/gpio/gpio47/value");
	  	usleep(1);
		system("echo 0 > /sys/class/gpio/gpio47/value");

	  }
	}
}

void mode3(){
	
	printf("mode 3 \n" );
	
	//MS1
    system("echo 0 > /sys/class/gpio/gpio66/value");
    //MS2
	system("echo 1 > /sys/class/gpio/gpio69/value");
	
	////led bar out
	system("echo 1 > /sys/class/gpio/gpio67/value");
	system("echo 1 > /sys/class/gpio/gpio68/value");
	system("echo 1 > /sys/class/gpio/gpio44/value");	
	system("echo 0 > /sys/class/gpio/gpio26/value");
	int ITER;
	while( readBTN() != 1){
	system("echo 0 > /sys/class/gpio/gpio27/value");
	for(ITER= 0; ITER<1000; ITER++)  
	  {	
	  	system("echo 0 > /sys/class/gpio/gpio47/value");
	  	usleep(1);
		system("echo 1 > /sys/class/gpio/gpio47/value");

	  }
	system("echo 1 > /sys/class/gpio/gpio27/value");
	for(ITER= 0; ITER<1000; ITER++)  
	  {	
	  	system("echo 0 > /sys/class/gpio/gpio47/value");
	  	usleep(1);
		system("echo 1 > /sys/class/gpio/gpio47/value");

	  }
	}

}

void mode4(){
	
	printf("mode 4 \n" );
	
	//MS1
    system("echo 1 > /sys/class/gpio/gpio66/value");
    //MS2
	system("echo 1 > /sys/class/gpio/gpio69/value");
	
	////led bar out
	system("echo 1 > /sys/class/gpio/gpio67/value");
	system("echo 1 > /sys/class/gpio/gpio68/value");
	system("echo 1 > /sys/class/gpio/gpio44/value");
	system("echo 1 > /sys/class/gpio/gpio26/value");
	int ITER;
	while( readBTN() != 1){
	system("echo 0 > /sys/class/gpio/gpio27/value");
	for(ITER= 0; ITER<1680; ITER++)  
	  {	
	  	system("echo 1 > /sys/class/gpio/gpio47/value");
	  	usleep(1);
		system("echo 0 > /sys/class/gpio/gpio47/value");

	  }
	system("echo 1 > /sys/class/gpio/gpio27/value");
	for(ITER= 0; ITER<1680; ITER++)  
	  {	
	  	system("echo 1 > /sys/class/gpio/gpio47/value");
	  	usleep(1);
		system("echo 0 > /sys/class/gpio/gpio47/value");

	  }
	}
}


int main(){
/////////////////////led bar init    
	system("echo 67 > /sys/class/gpio/export");
	system("echo 68 > /sys/class/gpio/export");
	system("echo 44 > /sys/class/gpio/export");
	system("echo 26 > /sys/class/gpio/export");
	//cat direction
	system("echo out > /sys/class/gpio/gpio67/direction");
	system("echo out > /sys/class/gpio/gpio68/direction");
	system("echo out > /sys/class/gpio/gpio44/direction");
	system("echo out > /sys/class/gpio/gpio26/direction");
/////////////////////btn init
    system("echo 65 > /sys/class/gpio/export");
	//btn
	system("echo in > /sys/class/gpio/gpio65/direction");   
	
/////////////////////easy driver innit    

    //step init
    system("echo 47 > /sys/class/gpio/export");
    system("echo out > /sys/class/gpio/gpio47/direction");
    //dir init
    system("echo 27 > /sys/class/gpio/export");
	system("echo out > /sys/class/gpio/gpio27/direction");
	//MS1
    system("echo 66 > /sys/class/gpio/export");
    system("echo out > /sys/class/gpio/gpio66/direction");
    //MS2
    system("echo 69 > /sys/class/gpio/export");
	system("echo out > /sys/class/gpio/gpio69/direction");
    //EN
    system("echo 45 > /sys/class/gpio/export");
	system("echo out > /sys/class/gpio/gpio45/direction");
	system("echo 0 > /sys/class/gpio/gpio45/value");


	

	while(1){

		mode1();
		printf("BTN pressed mode 2 \n" );
		sleep(1);
		mode2();
		printf("BTN pressed mode 3 \n" );
		sleep(1);
		mode3();
		printf("BTN pressed mode 4 \n" );
		sleep(1);
		mode4();
		printf("BTN pressed mode 1 \n" );
		sleep(1);
        

	}
}

//http://beagleboard.org/static/images/cape-headers.png
//https://learn.sparkfun.com/tutorials/easy-driver-hook-up-guide?_ga=1.249057991.1371357388.1456166063#arduino-code
