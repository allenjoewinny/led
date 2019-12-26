#include<stdint.h>
void delay();
uint32_t *pclk=(uint32_t*)0X40021014;
uint32_t *pmode=(uint32_t*)0X48001000;
uint32_t *pout=(uint32_t*)0X48001014;
uint32_t *userclk=(uint32_t*)0X40021014;
uint32_t *user=(uint32_t*)0X48000010;

void r1();
void r2();
void b1();
void b2();
void g1();
void g2();
void o1();
void o2();
void clear();



int main()
{
	*pclk|= (1<<21);
    *userclk |=(1<<17);

while(1)
{
	 *pclk|= (1<<21);
     *userclk |=(1<<17);
while(!(*user&0X01))//1
     {
     r1();
     delay();
     o1();
     delay();
     g1();
     delay();
     b1();
     delay();
     r2();
     delay();
     o2();
     delay();
     g2();
     delay();
     b2();
     delay();
clear();
     }
while(!(*user&0X01))//2
     {
     r2();
     delay();
     o2();
     delay();
     g2();
     delay();
     b2();
     delay();
     r1();
     delay();
     o1();
     delay();
     g1();
     delay();
     b1();
     delay();
     clear();

     }

}


	return 0;

}

void delay()
{
	for(int i=0;i<=500000;i++);
}

void r1()
{
	*pmode &=~(3<<26);
	*pmode|=(1<<26);
	*pout |=(1<<13);

}
void r2()
{
	*pmode &=~(3<<18);
	*pmode|=(1<<18);
	*pout |=(1<<9);
}

void b1()
{
	*pmode &=~(3<<16);
	*pmode|=(1<<16);
	*pout |=(1<<8);
}

void b2()
{

	*pmode &=~(3<<24);
	*pmode|=(1<<24);
	*pout |=(1<<12);
}

void g1()
{
	*pmode &=~(3<<30);
	*pmode|=(1<<30);
	*pout |=(1<<15);
}

void g2()
{
	*pmode &=~(3<<22);
	*pmode|=(1<<22);
	*pout |=(1<<11);

}

void o1()
{

	*pmode &=~(3<<20);
	*pmode|=(1<<20);
	*pout |=(1<<10);
}

void o2()
{
	*pmode &=~(3<<28);
	*pmode|=(1<<28);
	*pout |=(1<<14);

}

void clear()
{
	*pmode&= 0X00000000;
	*pout&= 0X00000000;
}
