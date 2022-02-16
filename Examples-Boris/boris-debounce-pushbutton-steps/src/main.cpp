#include <Arduino.h>

#define BUTTON_PIN 33
#define REPS_FOR_STABLE_VALUE 5

void setup()
{
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    Serial.begin(9600);
    delay(2000);
}

void loop_proof_of_bouncing()
{
    static uint8_t counter = 0;
    static uint8_t prev = HIGH;
    uint8_t cur_state = digitalRead(BUTTON_PIN);

    // proof of bouncing
    if(cur_state != prev)
    {
        counter++;
        prev = cur_state;

        if(cur_state==HIGH)
            Serial.printf("%d HIGH\n", counter);
        else
            Serial.printf("%d LOW\n", counter);
    }
}

void loop_debounce_hl()
{
    static uint8_t counter = 0;
    static uint8_t debounce_state = HIGH;
    uint8_t cur_state = digitalRead(BUTTON_PIN);

    //
    // here is the calculation
    // --> deleted code <--
    //

    // just for debug
    static int print_count = 0;
    static int print_prev = HIGH;
    if(print_prev != debounce_state)
    {
        print_prev = debounce_state;
        print_count++;

        if(print_prev==HIGH)
            Serial.printf(". HIGH -> %d\n", print_count);
        else
            Serial.printf(". LOW  -> %d\n", print_count);
    }
}

void loop_debounce_hflr()
{
    static uint8_t counter = 0;
    static uint8_t debounce_state = DEBOUNCE_HIGH;
    uint8_t cur_state = digitalRead(BUTTON_PIN);

    #define DEBOUNCE_HIGH 1
    #define DEBOUNCE_FALLING 2
    #define DEBOUNCE_LOW 3
    #define DEBOUNCE_RISING 4

    //
    // here is the calculation
    // --> deleted code <--
    //

    // just for debug
    static int print_count = 0;
    static int print_prev = DEBOUNCE_HIGH;
    if(print_prev != debounce_state)
    {
        print_prev = debounce_state;

        switch(print_prev)
        {
            default:
            case DEBOUNCE_HIGH:     Serial.printf(". HIGH -> %d\n", print_count++); break;
            case DEBOUNCE_FALLING:  Serial.printf(". FALLING ."); break;
            case DEBOUNCE_LOW:      Serial.printf(". LOW -> %d\n", print_count++); break;
            case DEBOUNCE_RISING:   Serial.printf(". RISING ."); break;
        }
    }
}


void loop()
{
    loop_proof_of_bouncing();
    //loop_debounce_hl();
    //loop_debounce_hflr();
}
