#ifndef ROTARYENCODER_H
# define ROTARYENCODER_H

//17 pins / 2 pins per encoder = 8 maximum encoders
#define max_encoders 8

struct encoder
{
    int pin_a;
    int pin_b;
    volatile long value;
    volatile long last_value;
    volatile int lastEncoded;
};

//Pre-allocate encoder objects on the stack so we don't have to 
//worry about freeing them
struct encoder encoders[max_encoders];

/*
  Should be run for every rotary encoder you want to control
  Returns a pointer to the new rotary encoder structer
  The pointer will be NULL is the function failed for any reason
*/
struct encoder *setupencoder(int pin_a, int pin_b); 


#endif
