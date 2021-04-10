#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define CMD "netsh wlan show networks mode=bssid > wlan.txt"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

enum LINE_TYPE { UNKNOWN = -1, SSID, NET, AUTH, ENCRYP, BSSID, SIG = 10, RADIO, CH };

typedef struct{
	char apmac[30];			// mac-address of AP
	char radio_type[30];
	int signal_strength;	// a percentage value
	int channel;			// between 1-13 in EU
}ap;

typedef struct{
	char ssid[30];			// name of WLAN (SSID)
	char network[30];
	char authentication[30];
	char encryption[30];
	int num_ap;				// number of APs
	ap aplist[20];			// a list of APs (dynamic)
}ssid;

uint8_t wlan_count(FILE*);
void wlan_analyse(FILE *fg);
enum LINE_TYPE what_line(char*);
void show_wlan(struct ssid*, uint8_t);

// int wlan_number(char*);		//Not implemented
// char *read_value(char*);		//Not implemented
// void takeawaynewline(char*);	//Not implemented
