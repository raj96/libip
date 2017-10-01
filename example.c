#define DEBUG_FLAG 1

#include <stdio.h>
#include <ip/ip.h>

int main(int argc,char **argv) {
	//Getting an IP struct from makeIP and assigning it to the variable ip
	IP ip = makeIP("192.168.14.213");

	//Printing the address stored in variable ip
	printf("Entered IP address is: ");
	printIP(ip);	//Note that the printIP function prints the I.P. address without a new line
	printf("\n");

	//Passing the address of the ip variable and a string that contains the subnet,to set the subnet and calculate the network and broadcast address
	setSubnet(&ip,"255.255.240.0");

	//Printing I.P. address. subnet address, network address and broadcast address
	getDetails(ip);

	return 0;
}
