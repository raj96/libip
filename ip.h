#define ZERO 48

#ifndef DEBUG_FLAG
	#define DEBUG_FLAG 0
	#define DEBUG(X) NULL
#endif

#if(DEBUG_FLAG==1)
#define DEBUG(X) printf("%s\n",X)
#endif

typedef unsigned char uint_8;

typedef struct t_ip {
	uint_8 octet[4];
}T_IP;

typedef struct ip {
	uint_8 octet[4];
	uint_8 subnet : 5;
	T_IP subnetIP;
	T_IP networkAddress;
	T_IP broadcastAddress;
}IP;

extern IP makeIP(char*);
extern T_IP get_T_IP(IP);
extern void printIP(IP);
extern void printT_IP(T_IP);
extern void setSubnet(IP*,char*);
extern void getDetails(IP);
