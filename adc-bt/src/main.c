/*
 * Copyright (c) 2020 Libre Solar Technologies GmbH
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/logging/log.h>
#include <dk_buttons_and_leds.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/util.h>
#include "adc.h"
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
//#include "neuroluokittelija.c"
#include "confusion.h"



#define USER_LED1         	 	DK_LED1
#define USER_LED2          		DK_LED2
#define USER_LED3               DK_LED3
#define USER_LED4               DK_LED4

#define USER_BUTTON_1           DK_BTN1_MSK
#define USER_BUTTON_2           DK_BTN2_MSK
#define USER_BUTTON_3           DK_BTN3_MSK
#define USER_BUTTON_4           DK_BTN4_MSK

#define DEBUG 0  // 0 = changes direction when button 3 is pressed
                 // 1 = fake 100 measurements done to each 6 directions when 3 pressed.
static int direction = -1;	// 0 = x direction high
							// 1 = x directon low	
							// 2 = y direction high
							// 3 = y direction low
							// 4 = z direction high
							// 5 = z direction low
int dir = -1, prev_dir = -1;
bool btn_4_state = false;
                				 

LOG_MODULE_REGISTER(MAIN, LOG_LEVEL_INF);

static void button_changed(uint32_t button_state, uint32_t has_changed)
{
	//printk("button_state = %d\n",button_state);
	//printk("has_changed = %d\n",has_changed);
	if ((has_changed & USER_BUTTON_1) && (button_state & USER_BUTTON_1)) 
	{
		printk("\nButton 1 down, printing current Confusion Matrix\n");
		struct Measurement m = readADCValue();
		calculateDistanceToAllCentrePointsAndSelectWinner(m.x,m.y,m.z);
		printConfusionMatrix();
		btn_4_state = false;
	}

	if ((has_changed & USER_BUTTON_2) && (button_state & USER_BUTTON_2)) 
	{
		printk("\nButton 2 down, resetting confusion matrix\n");
		
		resetConfusionMatrix();
		printConfusionMatrix();
		btn_4_state = false;
	}		
	
	if ((has_changed & USER_BUTTON_3) && (button_state & USER_BUTTON_3)) 
	{
		printk("\nButton 3 down, making fake 100 meas or one real meas depending on DEBUG state\n");
		btn_4_state = false;
		#if DEBUG
		direction = 0;
		makeHundredFakeClassifications();
		printConfusionMatrix();
		#else
        direction = (direction +1)%6;
		switch (direction)
		{
		case 0:
			printk("Direction is now set x = low\n");
			break;
		case 1:
			printk("Direction is now set y = low\n");
			break;
		case 2:
			printk("Direction is now set x = high\n");
			break;
		case 3:
			printk("Direction is now set y = high\n");
			break;
		case 4:
			printk("Direction is now set z = high\n");
			break;
		case 5:
			printk("Direction is now set z = low\n");
			break;
		
		default:
		    printk("Wrong direction set!!!\n");
			break;
		}

		//struct Measurement m = readADCValue();
		//printk("x = %d,  y = %d,  z = %d\n",m.x,m.y,m.z);
		#endif
	}		

	if ((has_changed & USER_BUTTON_4) && (button_state & USER_BUTTON_4)) 
	{
		#if DEBUG
		printk("button 4 down, one meas and classification with current direction =%d\n",direction);
		btn_4_state = true;
		#else
		struct Measurement m = readADCValue();
		double data[3] = {m.x,m.y,m.z};
		int data_size = sizeof(data) / sizeof(data[0]);
		int suunta = oma_aktivointi(data, data_size);
		printk("\nButton 4 down, one meas and classification with neuralnetwork = %d\n",suunta);
    	printk("x = %d,  y = %d,  z = %d\n\n",m.x,m.y,m.z);
		printConfusionMatrix();
		//makeOneClassificationAndUpdateConfusionMatrix(direction);
		//printConfusionMatrix();
		#endif
	}		
}


void main(void)
{
	int err;
	err = dk_leds_init();
	if (err) {
		LOG_ERR("LEDs init failed (err %d)\n", err);
		return;
	}

	err = dk_buttons_init(button_changed);
	if (err) {
		printk("Cannot init buttons (err: %d)\n", err);
		return;
	}
	
	
	if(initializeADC() != 0)
	{
	printk("ADC initialization failed!");
	return;
	}

	while (1) 
	{
		struct Measurement m = readADCValue();
		//printk("x = %d,  y = %d,  z = %d\n",m.x,m.y,m.z);
		 if (btn_4_state == true){
			dir = makeOneClassificationAndUpdateConfusionMatrix(m.x,m.y,m.z);
			if(dir != prev_dir){
				prev_dir = dir;
				printk("Suunta = %d\n",dir);
			}
		} 
		
		k_sleep(K_MSEC(500));
		
		dk_set_led_on(USER_LED1);
		dk_set_led_on(USER_LED2);
		dk_set_led_on(USER_LED3);
		dk_set_led_on(USER_LED4);
		 
		k_sleep(K_MSEC(500));
		
		dk_set_led_off(USER_LED1);
		dk_set_led_off(USER_LED2);
		dk_set_led_off(USER_LED3);
		dk_set_led_off(USER_LED4);
		 
	}
}


