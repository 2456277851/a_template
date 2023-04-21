#include "delay.h"
void Delay_Us(u16 us)
{
	while(us--)
	{
		_nop_();
		_nop_();
	}
}