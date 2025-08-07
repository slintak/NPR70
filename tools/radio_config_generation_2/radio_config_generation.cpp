
//
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include "stdafx.h"

#include "SI4463_which_config.h"
//#define which_modulation 13
//#include "./SI4463/radio_config_Si4463_13.h"

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned char radio_config_data[1500] = RADIO_CONFIGURATION_DATA_ARRAY;
	FILE* fid_out;
	char filename_out[30];
	int i = 0;
	int j;
	int current_command_length;
	sprintf(filename_out, "SI4463_config_%i%s.h", which_modulation, which_band);
	fid_out = fopen(filename_out, "w+");
	fprintf(fid_out,"#define RADIO_CONFIGURATION_DATA_ARRAY_%i { \\\n", which_modulation);
	current_command_length = radio_config_data[i];
	while (current_command_length > 0) {
		current_command_length = radio_config_data[i];
		fprintf(fid_out,"\t");
		for (j = 0; j <= current_command_length; j++) {
			fprintf(fid_out,"0x%02X, ", radio_config_data[i + j]);
		}
		fprintf(fid_out,"\\\n");
		i = i + current_command_length+1;
		current_command_length = radio_config_data[i];
		
	}

	fprintf(fid_out,"\t0x00 \\\n} \n");
	printf("total size:%i\r\n", i);
	return 0;

}

