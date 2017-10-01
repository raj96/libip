#include <stdio.h>
#include "ip.h"

T_IP get_T_IP(IP ip) {
	T_IP tip;
	tip.octet[0] = ip.octet[0];
	tip.octet[1] = ip.octet[1];
	tip.octet[2] = ip.octet[2];
	tip.octet[3] = ip.octet[3];

	return tip;
}

void printT_IP(T_IP ip) {
	printf("%d.%d.%d.%d",ip.octet[0],ip.octet[1],ip.octet[2],ip.octet[3]);
}
