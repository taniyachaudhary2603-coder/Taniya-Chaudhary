#include <stdlib.h> 
#define MAX 100 

// VIP Queue
int vipQueue[MAX]; 
int frontVIP = -1, rearVIP = -1; 

// Normal Queue 
int normalQueue[MAX]; 
int frontN = -1, rearN = -1; 

// Generate Ticket 
void generateTicket(int ticket, int type) { 
if (type == 1) { // VIP 
if (rearVIP == MAX - 1) { 
printf("VIP Queue Full!\n"); 
return; 
} 

if (frontVIP == -1) frontVIP = 0; 
vipQueue[++rearVIP] = ticket; 
printf("VIP Ticket %d generated\n", ticket); 
} else { // Normal 
if (rearN == MAX - 1) { 
printf("Normal Queue Full!\n"); 
return; 
} 

if (frontN == -1) frontN = 0; 
normalQueue[++rearN] = ticket; 
printf("Normal Ticket %d generated\n", ticket); 
} 
} 

// Serve Ticket 
void serveTicket() { 
if (frontVIP != -1 && frontVIP <= rearVIP) { 
printf("Serving VIP Ticket %d\n", vipQueue[frontVIP++]); 
} 
else if (frontN != -1 && frontN <= rearN) { 
printf("Serving Normal Ticket %d\n", normalQueue[frontN++]); 
} 
else { 
printf("No tickets to serve!\n"); 
} 
} 

// Display Queues 
void displayQueue() { 
int i; 
printf("\nVIP Queue: "); 
if (frontVIP == -1 || frontVIP > rearVIP) 
printf("Empty"); 
else { 
for (i = frontVIP; i <= rearVIP; i++) 
printf("%d ", vipQueue[i]); 
} 
printf("\nNormal Queue: "); 
if (frontN == -1 || frontN > rearN) 
printf("Empty"); 
else { 
for (i = frontN; i <= rearN; i++) 
printf("%d ", normalQueue[i]); 
} 
printf("\n"); 
} 
void nextTicket() { 
if (frontVIP != -1 && frontVIP <= rearVIP) { 
printf("Next Ticket: VIP %d\n", vipQueue[frontVIP]); 
} 
else if (frontN != -1 && frontN <= rearN) { 
printf("Next Ticket: Normal %d\n", normalQueue[frontN]); 
} 
else { 
printf("No upcoming tickets!\n"); 
} 
} 
int main() { 
int choice, type; 
int ticket = 1; 
while (1) { 
printf("\n--- Ticket System ---\n"); 
printf("1. Generate Ticket\n"); 
printf("2. Serve Ticket\n"); 
printf("3. Display Queue\n"); 
printf("4. Next Ticket\n"); 
printf("5. Exit\n"); 
printf("Enter choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1: 
printf("Enter type (1 = VIP, 2 = Normal): "); 
scanf("%d", &type); 
generateTicket(ticket++, type); 
break; 
case 2: 
serveTicket(); 
break; 
case 3: 
displayQueue(); 
break; 
case 4: 
nextTicket(); 
break; 
case 5: 
exit(0); 
default: 
printf("Invalid choice!\n"); 
} 
} 
return 0; 
} 
