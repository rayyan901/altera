//#define switches (volatile char*) 0x00002010
//#define se7seg (char*) 0x00002000

#define switches_add 0x00002010
#define se7seg_add 0x00002000

int delay(int i){

volatile int dly=0;

while(dly<i){
    dly++;
}
return 0;
}


int main(void)
{

int * se7seg = (int *) se7seg_add; /* red_leds is a pointer to the LEDRs */
volatile int * switches = (int *) switches_add;

char segment[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};

int suis=1;
int i;

while(1){

suis=*switches;
suis=suis&3;

if(suis==1){

for(i=0;i<10;i++){
*se7seg=segment[i];
delay(500000);

}
}
else if(suis==2){
for(i=9;i>=0;i--){
*se7seg=segment[i];
delay(500000);

}
}

else {
*se7seg=0x00;
}
    }

    return 0;
}
