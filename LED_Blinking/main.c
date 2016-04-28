    /***************************************************************************************************
                                   ExploreEmbedded    
 ****************************************************************************************************
 * File:   gpio.h
 * Version: 15.0
 * Author: ExploreEmbedded
 * Website: http://www.exploreembedded.com/wiki
 * Description: File contains the Program to demonstrate Led_Blinging using ARM Gcc for lpc1768

The libraries have been tested on ExploreEmbedded development boards. We strongly believe that the 
library works on any of development boards for respective controllers. However, ExploreEmbedded 
disclaims any kind of hardware failure resulting out of usage of libraries, directly or indirectly.
Files may be subject to change without prior notice. The revision history contains the information 
related to updates. 


GNU GENERAL PUBLIC LICENSE: 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>. 

Errors and omissions should be reported to codelibraries@exploreembedded.com
 **************************************************************************************************/
 
/*-----------------------------------------------------------------------------
                 Program to demonstrate Led_Blinging
  -----------------------------------------------------------------------------
 
note: Leds can be connected to any of the ports as all the ports are blinked

------------------------------------------------------------------------------*/

#include "lpc17xx.h"    
#include "delay.h"     //User defined library which conatins the delay routines
              
/* start the main program */
void main() 
{
    SystemInit();                    //Clock and PLL configuration 
    LPC_PINCON->PINSEL4 = 0x000000; //Configure the Pins for GPIO;
    LPC_GPIO2->FIODIR = 0xffffffff; //Configure the PORT pins as OUTPUT;

  while(1)
    {

     /* Turn On all the leds and wait for one second */ 
       LPC_GPIO2->FIOSET = 0xffffffff;     // Make all the Port pins as high  
       DELAY_sec(1);


       LPC_GPIO2->FIOCLR = 0xffffffff;     // Make all the Port pins as low  
       DELAY_sec(1);
    }
}
