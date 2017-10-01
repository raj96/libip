#define DEBUG_FLAG 1

#include <stdio.h>
#include <ip/ip.h>

int main(int argc,char **argv) {
	IP ip;
	if(argc==1)
		ip = makeIP("130.45.34.36");
	else
		ip = makeIP(argv[1]);

	setSubnet(&ip,"255.255.240.0");
	getDetails(ip);
	return 0;
}
