#include "wlan.h"

uint8_t wlan_count(FILE* file) {
	char buffer[20];
	uint8_t wlan_num = 0;
	while (wlan_num == 0) {
		fscanf(file, "%s", buffer);
		wlan_num = atoi(buffer);
	}
	return wlan_num;
}

enum LINE_TYPE what_line(char* line_str) {
	if (strstr(line_str, "SSID") != NULL && strstr(line_str, "BSSID") == NULL) {
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
	printf("Found %hhu WLANs\n\n", ssid_num);
	for (uint8_t i = 0; i < ssid_num; i++) {
		printf("SSID \t%s\n", (ssid_list + i)->ssid);
		
		int bssid_num = (ssid_list + i)->num_ap;

		for (int j = 0; j < bssid_num; j++) {
			printf("AP %hhu\t MAC: %s | Channel: %3d | Signal: %3d%%\n", j + 1, (ssid_list+i)->aplist[j].apmac, (ssid_list + i)->aplist[j].channel, (ssid_list + i)->aplist[j].signal_strength);
		}
		puts("");
	}
}

void wlan_analyse(FILE* fg) {
	uint8_t ssid_num, bssid_num;
	enum LINE_TYPE line_type;
	ssid *ssid_list;

	uint8_t wlan_num = wlan_count(fg);

	ssid_list = (ssid*)calloc(wlan_num, sizeof(ssid));

	while (!feof(fg)) {
		char buffer[55], field[55], value[55];


		fgets(buffer, 55, fg);
		line_type = what_line(buffer);

		switch (line_type) {
		case SSID:
			char ssid_name[21];
			sscanf(buffer, "%s %hhu : %s", field, &ssid_num, ssid_name);
			strcpy((ssid_list + ssid_num - 1)->ssid, ssid_name);
			uint8_t bssid_counter = 0;
			break;
		case NET:
			break;
		case AUTH:
			break;
		case ENCRYP:
			break;
		case BSSID:
			bssid_counter++;	//Do I need this?
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