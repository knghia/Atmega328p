
#include "main.h"
#include "use.h"

int main(void) 
{
    CLKPR = (1<<CLKPCE);
    CLKPR = (0<<CLKPCE) | (0<<CLKPS3) | (0<<CLKPS2) | (0<<CLKPS1) | (0<<CLKPS0);

    setup();
    while (1)
    {
        loop();
    }
    return 1;
}