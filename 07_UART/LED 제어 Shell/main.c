#include "STM32FDiscovery.h"
unsigned char rec;
unsigned int count = 0;
unsigned int init[60] = {64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 10, 76, 69, 68, 32, 67, 79, 78, 84, 82, 79, 76, 76, 32, 83, 72, 69, 76, 76, 32, 10, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 10 }; //LED CONTROLL SHELL ASCII ver.

// state
int rotate = 2;
int on = 1;
int off = 0;

// char macro
char help[13] = "Command List\r";
char LEDON[30] = " - LEDON + argument [1,2,3,4]\r";
char LEDOFF[31] = " - LEDOFF + argument [1,2,3,4]\r";
char ROTATE[10] = " - ROTATE\r";

char ON1[9] = "Green ON\r";
char OFF1[10] = "Green OFF\r";
char ON2[10] = "Orange ON\r";
char OFF2[11] = "Orange OFF\r";
char ON3[7] = "Red ON\r";
char OFF3[8] = "Red OFF\r";
char ON4[8] = "Blue ON\r";
char OFF4[9] = "Blue OFF\r";
char ROT[10] = "Rotate!!!\r";

char command[20];
int cmd_count = 0;
int cmd_flag = 0;

int strcmp(char*str1, char*str2){
    int strcmp_flag = 0;
    for(int i=0; str2[i] != '\0';i++){
        if(str1[i] != str2[i])
            strcmp_flag = 1;
        else
            strcmp_flag = 0;
    }
    return strcmp_flag;
}
void EXTI0_IRQHandler() { 
        GPIOD_ODR ^= 1 << 13;	
        GPIOD_ODR ^= 1 << 14;
        GPIOD_ODR ^= 1 << 15;

	EXTI_PR |= 1<<0;	
}
void clk(void)
{
	RCC_CR = 0;
	RCC_PLLCFGR = 0;
	RCC_CFGR = 0;
		
	RCC_CR |= (1<<16); 
	while( (RCC_CR & ( 1<<17) ) == 0 ); 
	
	RCC_PLLCFGR |= 8;
	RCC_PLLCFGR |= (336<<6);
	RCC_PLLCFGR |= (0<<16); 
	RCC_PLLCFGR |= (7<<24);

	RCC_PLLCFGR |= (1<<22); 
	

	RCC_CR |= (1<<24); 
	while( (RCC_CR & (1<<25)) == 0);
	
	FLASH_ACR |= 5;
	RCC_CFGR |= 2; 
	
		
	while( (RCC_CFGR & (12) ) != 8); 
	
	RCC_CFGR |= (1<<12) | (1<<10); 
	RCC_CFGR |= (1<<15); 
}

void set_uart2(){
	//USART PA2, PA3
	RCC_AHB1ENR	|= 1<<0;
	GPIOA_MODER	|= (1<<5) | (1<<7);
	GPIOA_AFRL	|= (7<<8) | (7<<12);

	//set USART2
	RCC_APB1ENR	|= (1<<17); //usart2 clk enable
	USART2_CR1	|= (0<<12);
	USART2_CR2	|= (0<<13) | (0<<12);

	USART2_BRR	|= (unsigned int)(42000000/115200);
	USART2_CR1	|= (1<<3) | (1<<2);
	USART2_CR1	|= (1<<5);
	USART2_CR1	|= (1<<13);

	// USART interrupt enable
	NVIC_ISER1	|= 1<<6;
}


void USART2_IRQHandler(){
	if(USART2_SR & (1<<5)){        
		rec = USART2_DR;        
		
		if(rec == '\r'){
		    command[cmd_count] = '\0';
		    cmd_flag = 1;
		}
		else command[cmd_count++] = rec;

        }
	USART2_DR = rec;
	while(!(USART2_SR & (1<<7)) );
	while(!(USART2_SR & (1<<6)) );  
 	USART2_CR1 |= (1<<5); 
		
}


int strtok(char * command, int index)
{
    char argv[10]; 
    int k=0;
    command[index] = '\0';
    for(int i=index+1;command[i] != '\0';i++)
        argv[k++] = command[i]; 

    if(k == 1)
        return argv[0]-48;
    else if(k == 2 )
        return 10*(argv[0]-48) + (argv[1] - 48);
    else if(k == 3)
        return 100*(argv[0] - 48) + 10*(argv[1]-48) + (argv[2] - 48);
    else return -1;
    
}
        
void CommandList(){
	for(int i=0;i<13;i++){
		USART2_DR = help[i];
		while(!(USART2_SR & (1<<7)) );
		while(!(USART2_SR & (1<<6)) );  
   	}
	for(int i=0;i<30 ;i++){
		USART2_DR = LEDON[i];
		while(!(USART2_SR & (1<<7)) );
		while(!(USART2_SR & (1<<6)) );  
   	}
	for(int i=0;i<31 ;i++){
		USART2_DR = LEDOFF[i];
		while(!(USART2_SR & (1<<7)) );
		while(!(USART2_SR & (1<<6)) );  
  	}
	for(int i=0;i<10 ;i++){
		USART2_DR = ROTATE[i];
		while(!(USART2_SR & (1<<7)) );
		while(!(USART2_SR & (1<<6)) );  
  	 }

}
void led_control(char state, int led_num){

    if(state == on){
        switch(led_num){
            case 1: 
                GPIOD_ODR |= 1 << 12;
	for(int i=0;i<9;i++){
		USART2_DR = ON1[i];
		while(!(USART2_SR & (1<<7)) );
		while(!(USART2_SR & (1<<6)) );  
   	}
                break;
            case 2: 
                GPIOD_ODR |= 1 << 13;
 	for(int i=0;i<10;i++){
		USART2_DR = ON2[i];
		while(!(USART2_SR & (1<<7)) );
		while(!(USART2_SR & (1<<6)) );  
   	}	
                break;
            case 3: 
                GPIOD_ODR |= 1 << 14;
	 for(int i=0;i<7;i++){
		USART2_DR = ON3[i];
		while(!(USART2_SR & (1<<7)) );
		while(!(USART2_SR & (1<<6)) );  
   	}	
                break;
            case 4: 
                GPIOD_ODR |= 1 << 15;	
	 for(int i=0;i<8;i++){
		USART2_DR = ON4[i];
		while(!(USART2_SR & (1<<7)) );
		while(!(USART2_SR & (1<<6)) );  
   	}
                break;
        }   
       
    }else if(state == off){
        switch(led_num){
            case 1: 
                GPIOD_ODR &= ~(1 << 12);
	for(int i=0;i<10;i++){
		USART2_DR = OFF1[i];
		while(!(USART2_SR & (1<<7)) );
		while(!(USART2_SR & (1<<6)) );  
   	}
                break;
            case 2: 	
                GPIOD_ODR &= ~(1 << 13);
	for(int i=0;i<11;i++){
		USART2_DR = OFF2[i];
		while(!(USART2_SR & (1<<7)) );
		while(!(USART2_SR & (1<<6)) );  
   	}
                break;
            case 3:  
                GPIOD_ODR &= ~(1 << 14);
	for(int i=0;i<8;i++){
		USART2_DR = OFF3[i];
		while(!(USART2_SR & (1<<7)) );
		while(!(USART2_SR & (1<<6)) );  
   	}
                break;
            case 4: 
                GPIOD_ODR &= ~(1 << 15);	
	for(int i=0;i<9;i++){
		USART2_DR = OFF4[i];
		while(!(USART2_SR & (1<<7)) );
		while(!(USART2_SR & (1<<6)) );  
   	}
                break;
        }   
    }else if(state == rotate){
                // LED OFF
	for(int i=0;i<10;i++){
		USART2_DR = ROT[i];
		while(!(USART2_SR & (1<<7)) );
		while(!(USART2_SR & (1<<6)) );  
   	}
                GPIOD_ODR &= ~(1 << 12);
                GPIOD_ODR &= ~(1 << 13);
                GPIOD_ODR &= ~(1 << 14);
                GPIOD_ODR &= ~(1 << 15);


        for(int i=0;i<10;i++){
                GPIOD_ODR ^= 1 << 12;
                GPIOD_ODR &= ~(1 << 13);
                GPIOD_ODR &= ~(1 << 14);
                GPIOD_ODR &= ~(1 << 15);
                for(int i=0;i<500000;i++){
                }
                GPIOD_ODR &= ~(1 << 12);
	  GPIOD_ODR ^= 1 << 13;
                GPIOD_ODR &= ~(1 << 14);
                GPIOD_ODR &= ~(1 << 15);
                for(int i=0;i<500000;i++){
                }
                GPIOD_ODR &= ~(1 << 12);
                GPIOD_ODR &= ~(1 << 13);
	  GPIOD_ODR ^= 1 << 14;
                GPIOD_ODR &= ~(1 << 15);
                for(int i=0;i<500000;i++){
                }
                GPIOD_ODR &= ~(1 << 12);
                GPIOD_ODR &= ~(1 << 13);
                GPIOD_ODR &= ~(1 << 14);
	  GPIOD_ODR ^= 1 << 15;
                for(int i=0;i<500000;i++){
                }
                GPIOD_ODR &= ~(1 << 12);
                GPIOD_ODR &= ~(1 << 13);
                GPIOD_ODR &= ~(1 << 14);
                GPIOD_ODR &= ~(1 << 15);
        }
    }
}

int main(){
	
	clk();
	RCC_CFGR |= 0x04600000;

    /* PORT A */
	RCC_AHB1ENR  |= 1<<0; //RCC clock enable register	
   	GPIOA_MODER  |= 0<<0; // input mode   // page 281
   	GPIOA_OTYPER |= 0<<0; // output push-pull
   	GPIOA_PUPDR  |= 0<<0; // no pull-up, pull-down
	
	/* button intr set */
    	SYSCFG_EXTICR1	|= 0<<0;	// EXTI0 connect to PA0
	EXTI_IMR |= 1<<0;	// MASK EXTI0
	EXTI_RTSR |=1<<0;	// rising edge trigger enable
	EXTI_FTSR |=0<<0;	// falling edge trigger disable
	NVIC_ISER0 |=1<<6;	// enable EXTI0 interrupt


	/* PORT D */
	RCC_AHB1ENR  |= 1<<3;		// PORTD enable
	GPIOD_MODER  |= 1<<24;		// PORTD 12 general output mode
	GPIOD_MODER  |= 1<<26;		// PORTD 13 general output mode
	GPIOD_MODER  |= 1<<28;		// PORTD 14 general output mode
	GPIOD_MODER  |= 1<<30;		// PORTD 15 general output mode
	GPIOD_OTYPER |= 0x00000000;
	GPIOD_PUPDR	 |= 0x00000000;	
	
	set_uart2();
   	while(count < 60) {
        	USART2_DR = init[count++]; // data into DR Register
        	while( !(USART2_SR & (1<<7)) ); // usart2_sr resigter 6,7 bit is 
        	while( !(USART2_SR & (1<<6)) ); // checking process
   	 }
	USART2_DR = '>';
			while(!(USART2_SR & (1<<7)) );
			while(!(USART2_SR & (1<<6)) ); 

	while(1) {
		int led_num=0;
		if(cmd_flag){
			for(int i=0;i<cmd_count;i++){
				if(command[i] ==' '){
					led_num = strtok(command, i);                 
				}
			}


			if(strcmp(command, "HELP") == 0){
				CommandList();                    
			}
			else if(strcmp(command,"LEDON")==0){                    
				led_control(on,led_num);  
			}else if(strcmp(command,"LEDOFF")==0){
				led_control(off, led_num);
			}else if(strcmp(command, "ROTATE") ==0){
				led_control(rotate,led_num);
			}

			cmd_count = 0;
			cmd_flag = 0;
			USART2_DR = '>';
			while(!(USART2_SR & (1<<7)) );
			while(!(USART2_SR & (1<<6)) ); 
		}
	}

	

}
