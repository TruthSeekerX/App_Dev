#include "wlan.h"


int wlan_count(FILE* file) {
	char buffer[20];
	int wlan_num = 0;
	while (wlan_num == 0) {
		fscanf(file, "%s", buffer);
		wlan_num = atoi(buffer);
	}
	return wlan_num;
}

int bssid_count(FILE* file) {
	char buffer[20];
	int bssid_num = 0, distance = 0;
	while (1) {
//		distance += fscanf();
	}
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

void wlan_analyse(FILE* fg) {
	char buffer[55], field[55], value[55], ssid_name[21];
	ssid* ssid_list;
	enum LINE_TYPE line_type;
	int i = 0, ssid_num;

	int wlan_num = wlan_count(fg);

	ssid_list = (ssid*)calloc(wlan_num, sizeof(ssid));

	for (i = 0; i < wlan_num; i++) {
		while (!feof(fg)) {
			fgets(buffer, 55, fg);
			line_type = what_line(buffer);
			// UNKNOWN = -1, SSID, NET, AUTH, ENCRYP, BSSID, SIG = 10, RADIO, CH
			switch (line_type) {
			case SSID:
				sscanf(buffer, "%s %d : %s",field, &ssid_num, ssid_name);
				strcpy(ssid_list[ssid_num - 1].ssid, ssid_name);
				//bssid_counter();
				break;
			case NET:
				break;
			case AUTH:
				break;
			case ENCRYP:
				break;
			case BSSID:
				fscanf(fg, "%s : %s", field, &ssid_list[i].aplist->apmac);
			case SIG:
				fscanf(fg, "%s : %s", field, value);
				ssid_list[i].aplist->signal_strength = atoi(value);
				break;
			case RADIO:
				break;
			case CH:
				fscanf(fg, "%s : %s", field, value);
				ssid_list[i].aplist->channel = atoi(value);
			case UNKNOWN:
				break;
			default: break;
			}
		}
	}
	free(ssid_list);
}