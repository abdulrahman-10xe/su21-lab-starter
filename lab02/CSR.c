#include <stdio.h>

#define CSR_VAL 0x8000abcd00001234UL
#define ADDRESS 0x5300f000U

unsigned long int my_csr = CSR_VAL;

int main(void) {
    // (a) here: make the first bit of my_csr equal to 1 (or high)
    my_csr = my_csr | (1<<0); // Setting 1st bit (bit 0) = 1. No shifting is being done.
    
    // (b) here: make the third bit (bit 2) equal to 0
    my_csr = my_csr & (~(1<<2)); // ANDING with 0x1111...1011 to reset the bit 2.
    
    // (c) here: make bits 8 to 15 equal to 0xee
    my_csr = my_csr & (~(0xff<<8)); // Resetting the required bits
    my_csr = my_csr |   (0xee<<8) ; // Setting according to the given bits
    
    // (d) here: extract bits 12 to 27 of the given ADDRESS and store them in bits 16-31 of the my_csr
    unsigned long int my_addr = ADDRESS; // For holding the manipulations done on ADDRESS.
    my_addr = my_addr >> 12; // Dumping the LSB 12 bits
    my_addr = my_addr & 0x0000ffff; // Resetting all other bits except for 16 LSBs.
    my_addr = my_addr << 16; // Aligning the required bits with bit 16-31 of my_csr.
    
    my_csr  = my_csr & (~(0xffff << 16)); // Resetting bits 16-31 of my_csr.
    my_csr  = my_csr | my_addr; // Applying the bits 12-27 of my_addr to bits 16-31 of my_csr.
    printf("%16.16lx\n", my_csr);
    return 0;
}
