#include <stdio.h>
#include "ip.h"

IP makeIP(char *str_ip) {

	IP ip;
	int octet;
	int count = 0;

	while( (*str_ip) != 0 ) {
		octet = 0;
		while( ((*str_ip ) != '.') && ((*str_ip) != 0) ) {
//			printf("%c\n",*str_ip);
			octet *= 10;
			octet += ( (*str_ip) - ZERO );
			str_ip++;
		}
		ip.octet[count++] = octet;
		octet = 0;

		if( (*str_ip) == 0 )
			break;

		str_ip++;
	}

	if(count!=4) {
		DEBUG("Not a valid IP");
		IP oip;
		return oip;
	}
	return ip;

}

void printIP(IP ip) {
	printf("%d.%d.%d.%d",ip.octet[0],ip.octet[1],ip.octet[2],ip.octet[3]);
}

void setSubnet(IP *src ,char *subnet) {

	src->subnetIP = get_T_IP( makeIP( subnet ) );

	//Initialize Network Address
	DEBUG("Calculating Network Address...");
	T_IP networkAddress;
	networkAddress.octet[0] = src->octet[0] & src->subnetIP.octet[0];
	networkAddress.octet[1] = src->octet[1] & src->subnetIP.octet[1];
	networkAddress.octet[2] = src->octet[2] & src->subnetIP.octet[2];
	networkAddress.octet[3] = src->octet[3] & src->subnetIP.octet[3];
	DEBUG("Calculation Done...");
	src->networkAddress = networkAddress;

	//Initialize Broadcast Address
	DEBUG("Calculating Broadcast Address...");
	T_IP broadcastAddress;
	broadcastAddress.octet[0] = src->octet[0] | (~src->subnetIP.octet[0]);
	broadcastAddress.octet[1] = src->octet[1] | (~src->subnetIP.octet[1]);
	broadcastAddress.octet[2] = src->octet[2] | (~src->subnetIP.octet[2]);
	broadcastAddress.octet[3] = src->octet[3] | (~src->subnetIP.octet[3]);
	DEBUG("Calculation Done...");
	src->broadcastAddress = broadcastAddress;

	return;
}


void getDetails(IP ip) {
	printf("IP Address: ");
	printIP(ip);
	printf("\nSubnet Mask: ");
	printT_IP(ip.subnetIP);
	printf("\nNetwork Address: ");
	printT_IP(ip.networkAddress);
	printf("\nBroadcast Address: ");
	printT_IP(ip.broadcastAddress);
	printf("\n");

	return;
}
