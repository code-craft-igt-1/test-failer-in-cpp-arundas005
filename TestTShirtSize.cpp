#include"tshirts.h"
#include <assert.h>

void testTshirtSizeFromSholderWidthInCMS() {
    assert(tshirtSizeFromSholderWidthInCMS(37) == 'S');
    assert(tshirtSizeFromSholderWidthInCMS(38) == 'M');
    assert(tshirtSizeFromSholderWidthInCMS(42) == 'M');
    assert(tshirtSizeFromSholderWidthInCMS(43) == 'L');
    assert(tshirtSizeFromSholderWidthInCMS(100) == 'L');
}  
