#include "wlan.h"

uint8_t wlan_count(FILE* file) {
	/* This function finds the network numbers by scanning and find the first number in the data file
	*/
	char buffer[20];
	uint8_t wlan_num = 0;
	while (wlan_num == 0) {				//The loop breaks as soon as the first number is found, which is network number. 
		fscanf(file, "%s", buffer);		//ultilise the "flaw" of fscanf which breaks at a white space to parse the data.
		wlan_num = atoi(buffer);		//ultilise atoi to conver the network number into integer.
	}
	return wlan_num;
}

enum LINE_TYPE what_line(char* line_str) {
	/*This function is pretty straight forward. It takes input string first. Then find and match the line_type.
	*/
	if (strstr(line_str, "SSID") != NULL && strstr(line_str, "BSSID") == NULL) {	//Be aware checking only "SSID" would mistakely return "BSSID" as "SSID"
		return SSID;
	}
	else if (strstr(line_str, "Network type") != NULL) {
		return NET;
	}
	else if (strstr(line_str, "Authentication") != NULL) {
		return AUTH;
	}
	else if (strstr(line_str, "Encryption") != NULL) {
		return ENCRYP;
	}
	else if (strstr(line_str, "BSSID") != NULL) {
		return BSSID;
	}
	else if (strstr(line_str, "Signal") != NULL) {
		return SIG;
	}
	else if (strstr(line_str, "Radio type") != NULL) {
		return RADIO;
	}
	else if (strstr(line_str, "Channel") != NULL) {
		return CH;
	}
	else return UNKNOWN;
}

void show_wlan(ssid* ssid_list, uint8_t ssid_num) {
	/* This function displays the data stored in ssid_list.
	   Argument ssid_num is needed because the pointer *ssid_list does not carry any information how big it is.
	*/
	printf("Found %hhu WLANs\n\n", ssid_num);

	for (uint8_t i = 0; i < ssid_num; i++) {
		// This loop prints each SSID
		printf("SSID \t%s\n", (ssid_list + i)->ssid);
		
		int bssid_num = (ssid_list + i)->num_ap;

		for (int j = 0; j < bssid_num; j++) {
			//This loop prints each BSSID/APs in each SSID
			printf("AP %hhu\t MAC: %s | Channel: %3d | Signal: %3d%%\n", j + 1, (ssid_list+i)->aplist[j].apmac, (ssid_list + i)->aplist[j].channel, (ssid_list + i)->aplist[j].signal_strength);
		}
		puts("");
	}
}

void wlan_analyse(FILE* fg) {
	uint8_t ssid_num, bssid_num;
	enum LINE_TYPE line_type;
	ssid *ssid_list;	//using a pointer here for DMA

	uint8_t wlan_num = wlan_count(fg);

	ssid_list = (ssid*)calloc(wlan_num, sizeof(ssid));

	while (!feof(fg)) {
		char buffer[55], field[55], value[55];		//55 slots are big enough for buffer, field and value strings. 

		fgets(buffer, 55, fg);						//fgets reads the whole line and store the data in buffer as string.
		line_type = what_line(buffer);				//pass the string to what_line function

		switch (line_type) {
			//Here we do differnt manipulations according to the line_type
		case SSID:
			char ssid_name[21];
			sscanf(buffer, "%s %hhu : %s", field, &ssid_num, ssid_name);		//ultilise sscanf to parse the string 
			strcpy((ssid_list + ssid_num - 1)->ssid, ssid_name);				//copy the the string to desired location
//			uint8_t bssid_counter = 0;		//I don't need bssid_counter in my implementation. I am wondering is there some problem with my code.
			break;
		case NET:
			break;
		case AUTH:
			break;
		case ENCRYP:
			break;
		case BSSID:
//			bssid_counter++;	//I don't need bssid_counter in my implementation. I am wondering is there some problem with my code.
			sscanf(buffer, "%s %hhu : %s", field, &bssid_num, value);
			strcpy((ssid_list + ssid_num - 1)->aplist[bssid_num - 1].apmac, value);
			(ssid_list + ssid_num - 1)->num_ap = bssid_num;
			break;
		case SIG:
			sscanf(buffer, "%s : %s", field, value);
			(ssid_list + ssid_num - 1)->aplist[bssid_num - 1].signal_strength = atoi(value);
			break;
		case RADIO:
			break;
		case CH:
			sscanf(buffer, "%s : %s", field, value);
			(ssid_list + ssid_num - 1)->aplist[bssid_num - 1].channel = atoi(value);
			break;
		case UNKNOWN:
			break;
		default: break;
		}
	}
	
	show_wlan(ssid_list, ssid_num);
	
	free(ssid_list);
}