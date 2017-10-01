# libip

### IP makeIP(char* ip)
makeIP function takes in a character array and gives out an IP struct,this function is used to initialize an IP variable.
Example: `IP ip = makeIP("192.168.14.210")``


### void printIP(IP ip)
As the name suggests printIP function prints the ip stored in the IP struct passed to it

### void setSubnet(IP \*ip,char \*subnet)

The above function sets the subnet for the IP struct passed to it and also calculates the network and broadcast address for the given IP address and subnet.

### void getDetails(IP ip);

The above function prints the IP address, subnet mask, network address and broadcast address stored in the IP struct passed to it. This method should always be called after calling setSubnet with a valid subnet address.

#### Check the example.c file for more
