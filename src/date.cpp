#include <time.h>

char DecToC(int a){
	static const char dec[]="0123456789";
	return dec[a%10];
}

void getNowDate(char* buffer){
	if(buffer == 0){
		return;
	}
	time_t czas;
  time(&czas);
	tm local_tm = *localtime(&czas);
	//days
	buffer[0] = DecToC(local_tm.tm_mday/10);
	buffer[1] = DecToC(local_tm.tm_mday);
	//dot
	buffer[2] = '.';
	//months
	
	local_tm.tm_mon += 1;
	buffer[3] = DecToC(local_tm.tm_mon/10);
	buffer[4] = DecToC(local_tm.tm_mon);
	//dot
	buffer[5] = '.';
	
	//years
	local_tm.tm_year += 1900;
	buffer[6] = DecToC(local_tm.tm_year/1000);
	buffer[7] = DecToC(local_tm.tm_year/100);
	buffer[8] = DecToC(local_tm.tm_year/10);
	buffer[9] = DecToC(local_tm.tm_year);
	buffer[10] = '\0';
}
