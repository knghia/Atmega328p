
#include "main.h"
#include "use.h"

__fuse_t __fuse __attribute__((section (".fuse"))) = 
{
    .low = LFUSE_DEFAULT,
    .high = (FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_EESAVE & FUSE_SPIEN),
    .extended = EFUSE_DEFAULT,
};


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