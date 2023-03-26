#include <stdio.h>

#define NO_WORDS 2
#define SIZE_WORDS NO_WORDS<<3

typedef struct {
   unsigned long long double_word[NO_WORDS];
} arr_t __attribute__ ((aligned (SIZE_WORDS) ));


arr_t store_byte_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_byte_expected_data[8] =
       {    // double_word0         double_word1
          { 0x00000000000000EF, 0x0000000000000000 },
          { 0x000000000000BE00, 0x0000000000000000 },
          { 0x0000000000AD0000, 0x0000000000000000 },
          { 0x00000000DE000000, 0x0000000000000000 },
          { 0x000000EF00000000, 0x0000000000000000 },
          { 0x0000BE0000000000, 0x0000000000000000 },
          { 0x00AD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x0000000000000000 }
       };


arr_t store_half_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_half_word_expected_data[8] =
       {
          { 0x000000000000BEEF, 0x0000000000000000 },
          { 0x0000000000ADBE00, 0x0000000000000000 },
          { 0x00000000DEAD0000, 0x0000000000000000 },
          { 0x000000EFDE000000, 0x0000000000000000 },
          { 0x0000BEEF00000000, 0x0000000000000000 },
          { 0x00ADBE0000000000, 0x0000000000000000 },
          { 0xDEAD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x00000000000000EF }
       };


arr_t store_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_word_expected_data[8] =
       {
          { 0x00000000DEADBEEF, 0x0000000000000000 },
          { 0x000000DEADBEEF00, 0x0000000000000000 },
          { 0x0000DEADBEEF0000, 0x0000000000000000 },
          { 0x00DEADBEEF000000, 0x0000000000000000 },
          { 0xF00DC0DE00000000, 0x0000000000000000 },
          { 0x0DC0DE0000000000, 0x00000000000000F0 },
          { 0xC0DE000000000000, 0x000000000000F00D },
          { 0xDE00000000000000, 0x0000000000F00DC0 }
       };


arr_t store_double_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_double_word_expected_data[8] =
       {
          { 0xDEADBEEFF00DC0DE, 0x0000000000000000 },
          { 0xADBEEFF00DC0DE00, 0x00000000000000DE },
          { 0xBEEFF00DC0DE0000, 0x000000000000DEAD },
          { 0xEFF00DC0DE000000, 0x0000000000DEADBE },
          { 0xF00DC0DE00000000, 0x00000000DEADBEEF },
          { 0x0DC0DE0000000000, 0x000000DEADBEEFF0 },
          { 0xC0DE000000000000, 0x0000DEADBEEFF00D },
          { 0xDE00000000000000, 0x00DEADBEEFF00DC0 }
       };



int store_byte_test ( ) { // EF, BE, AD, DE, EF, BE, AD, DE
    unsigned char array[] = { 0xEF, 0xBE, 0xAD, 0xDE, 0xEF, 0xBE, 0xAD, 0xDE };
    int word_size = sizeof(unsigned long long int);
    int element_size = sizeof(array[0]);
    int array_size = sizeof(array)/sizeof(array[0]);
    for(int i = 0; i < array_size; ++i) {
	store_byte_data[i].double_word[0] = ((unsigned long long int) array[i]) << (i*8);
	if(word_size - element_size - i >= 0) {
	    store_byte_data[i].double_word[1] = 0;
	}
	else 
	{
	    if(i - word_size < 0) {
	    	store_byte_data[i].double_word[1] = ((unsigned long long int) array[i]) >> (8*(word_size - i));
	    }
	    else
	    {
	    	store_byte_data[i].double_word[1] = ((unsigned long long int) array[i]) << (8*(i - word_size));
	    }
	}
    }
    // Matching with the expected result
    for(int i = 0; i < (sizeof(array)/sizeof(array[0])); ++i) {
	if((store_byte_data[i].double_word[0] != store_byte_expected_data[i].double_word[0])||(store_byte_data[i].double_word[1] != store_byte_expected_data[i].double_word[1])) {
	    return 0;
	}
    }
    return 1;
} // store_byte_test


int store_half_word_test ( ) { // BEEF, ADBE, DEAD, EFDE, BEEF, ADBE, DEAD, EFDE
    unsigned short array[] = { 0xBEEF, 0xADBE, 0xDEAD, 0xEFDE, 0xBEEF, 0xADBE, 0xDEAD, 0xEFDE };
    int word_size = sizeof(unsigned long long int);
    int element_size = sizeof(array[0]);
    int array_size = sizeof(array)/sizeof(array[0]);
    for(int i = 0; i < array_size; ++i) {
	store_half_word_data[i].double_word[0] = ((unsigned long long int) array[i]) << (i*8);
	if(word_size - element_size - i >= 0) {
	    store_half_word_data[i].double_word[1] = 0;
	}
	else 
	{
	    if(i - word_size < 0) {
	    	store_half_word_data[i].double_word[1] = ((unsigned long long int) array[i]) >> (8*(word_size - i));
	    }
	    else
	    {
	    	store_half_word_data[i].double_word[1] = ((unsigned long long int) array[i]) << (8*(i - word_size));
	    }
	} 	
    }
    // Matching with the expected result
    for(int i = 0; i < (sizeof(array)/sizeof(array[0])); ++i) {
	if((store_half_word_data[i].double_word[0] != store_half_word_expected_data[i].double_word[0])||(store_half_word_data[i].double_word[1] != store_half_word_expected_data[i].double_word[1])) {
	    return 0;
	}
    }
    return 1;
} // store_half_word_test


int store_word_test ( ) { // DEADBEEF, F00DC0DE
    unsigned int array[] = { 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xF00DC0DE, 0xF00DC0DE, 0xF00DC0DE, 0xF00DC0DE };
    int word_size = sizeof(unsigned long long int);
    int element_size = sizeof(array[0]);
    int array_size = sizeof(array)/sizeof(array[0]);
    for(int i = 0; i < array_size; ++i) {
	store_word_data[i].double_word[0] = ((unsigned long long int) array[i]) << (i*8);
	if(word_size - element_size - i >= 0) {
	    store_word_data[i].double_word[1] = 0;
	}
	else 
	{
	    if(i - word_size < 0) {
	    	store_word_data[i].double_word[1] = ((unsigned long long int) array[i]) >> (8*(word_size - i));
	    }
	    else
	    {
	    	store_word_data[i].double_word[1] = ((unsigned long long int) array[i]) << (8*(i - word_size));
	    }
	} 	
    }
    // Matching with the expected result
    for(int i = 0; i < (sizeof(array)/sizeof(array[0])); ++i) {
	if((store_word_data[i].double_word[0] != store_word_expected_data[i].double_word[0])||(store_word_data[i].double_word[1] != store_word_expected_data[i].double_word[1])) {
	    return 0;
	}
    }
    return 1;
} // store_word_test


int store_double_word_test ( ) { // DEADBEEFF00DC0DE
    unsigned long long int array[] = { 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE};
    int word_size = sizeof(unsigned long long int);
    int element_size = sizeof(array[0]);
    int array_size = sizeof(array)/sizeof(array[0]);
    for(int i = 0; i < array_size; ++i) {
	store_double_word_data[i].double_word[0] = ((unsigned long long int) array[i]) << (i*8);
	if(word_size - element_size - i >= 0) {
	    store_double_word_data[i].double_word[1] = 0;
	}
	else 
	{
	    if(i - word_size < 0) {
	    	store_double_word_data[i].double_word[1] = ((unsigned long long int) array[i]) >> (8*(word_size - i));
	    }
	    else
	    {
	    	store_double_word_data[i].double_word[1] = ((unsigned long long int) array[i]) << (8*(i - word_size));
	    }
	} 	
    }
    // Matching with the expected result
    for(int i = 0; i < (sizeof(array)/sizeof(array[0])); ++i) {
	if((store_double_word_data[i].double_word[0] != store_double_word_expected_data[i].double_word[0])||(store_double_word_data[i].double_word[1] != store_double_word_expected_data[i].double_word[1])) {
	    return 0;
	}
    }
    return 1;
} // store_double_word_test

int main() {
    int a = store_byte_test();
    if(a == 1) {
    	printf("Bytes stored correctly !!!\n");
    }
    else {
    	printf("Bytes NOT stored correctly !!!\n");
    }
    
    int b = store_half_word_test();
    if(b == 1) {
    	printf("Half word stored correctly !!!\n");
    }
    else {
    	printf("Half word NOT stored correctly !!!\n");
    }
    
    int c = store_word_test();
    if(c == 1) {
    	printf("Word stored correctly !!!\n");
    }
    else {
    	printf("Word NOT stored correctly !!!\n");
    }
    
    int d = store_double_word_test();
    if(d == 1) {
    	printf("Double word stored correctly !!!\n");
    }
    else {
    	printf("Double word NOT stored correctly !!!\n");
    }
    
    printf("\nStore Byte:-\nActual\t\t\t\t\tExpected\n");
    for(int i = 0; i < 8; ++i) {
	printf("%16.16llx %16.16llx,\t%16.16llx %16.16llx\n", store_byte_data[i].double_word[0], store_byte_data[i].double_word[1], store_byte_expected_data[i].double_word[0], store_byte_expected_data[i].double_word[1]);
    }
    
    printf("\nStore Half Word:-\nActual\t\t\t\t\tExpected\n");
    for(int i = 0; i < 8; ++i) {
	printf("%16.16llx %16.16llx,\t%16.16llx %16.16llx\n", store_half_word_data[i].double_word[0], store_half_word_data[i].double_word[1], store_half_word_expected_data[i].double_word[0], store_half_word_expected_data[i].double_word[1]);
    }
    
    printf("\nStore Word:-\nActual\t\t\t\t\tExpected\n");
    for(int i = 0; i < 8; ++i) {
	printf("%16.16llx %16.16llx,\t%16.16llx %16.16llx\n", store_word_data[i].double_word[0], store_word_data[i].double_word[1], store_word_expected_data[i].double_word[0], store_word_expected_data[i].double_word[1]);
    }
    
    printf("\nStore Double Word:-\nActual\t\t\t\t\tExpected\n");
    for(int i = 0; i < 8; ++i) {
	printf("%16.16llx %16.16llx,\t%16.16llx %16.16llx\n", store_double_word_data[i].double_word[0], store_double_word_data[i].double_word[1], store_double_word_expected_data[i].double_word[0], store_double_word_expected_data[i].double_word[1]);
    }
} // main
