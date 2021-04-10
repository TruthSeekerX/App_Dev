/********************************************************************************************************************************************
* This is the main file of the WiFi_Scanner project. It is meant for first year Application Development course lectured by DR. Gao Chao.
* Language: C
* Author:Siyuan e2002077
* Version: v0.1
*	   In this version:
*		The prototype is ready for scan and display WiFi network informations. 
*      Possible further improvements:
*		1. Add signal strength by dBm. DONE!
*		2. Add "network type", "authentication" and "encryption" for each SSID. DONE!
*		3. Add "radio type" to each BSSID/AP. DONE!
*		4. Add algorithm and UI for sorting BSSIDs by channel or signal strength.
* 09.04.2021
********************************************************************************************************************************************/
#include "wlan.h"

int main(void) {
//	system(CMD);	//The wlan.txt generated already, CMD get temporarily commented out for a more consistant testing/debugging process.
	FILE* fp = fopen("wlan.txt", "r");
	if (fp == NULL) {
		printf("Error: can't open file.\n");
	}
	else {
		printf("File opened successfully. Now analysing wlan data...\n\n");
		wlan_analyse(fp);
		printf("Closing the file.\n");
		fclose(fp);
		printf("File closed successfully.\n");
	}
	return 0;
}
