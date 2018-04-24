/**
 * @file       main.cpp
 * @author     Volodymyr Shymanskyy
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2015 Volodymyr Shymanskyy
 * @date       Mar 2015
 * @brief
 */

//#define BLYNK_DEBUG
#define BLYNK_PRINT stdout
#ifdef RASPBERRY
  #include <BlynkApiWiringPi.h>
#else
  #include <BlynkApiLinux.h>
#endif
#include <BlynkSocket.h>
#include <BlynkOptionsParser.h>

static BlynkTransportSocket _blynkTransport;
BlynkSocket Blynk(_blynkTransport);

static const char *auth, *serv;
static uint16_t port;

#include <BlynkWidgets.h>

BLYNK_WRITE(V1)
{
    printf("Got a value: %s\n", param[0].asStr());
}
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable

}

void RED(){
  digitalWrite(14, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
}

void setup()
{
    pinMode(14, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);

    Blynk.begin(auth, serv, port);
}

void loop()
{
    Blynk.run();
    if(pinValue == 1){
      RED();
    }
}


int main(int argc, char* argv[])
{
    parse_options(argc, argv, auth, serv, port);

    setup();
    while(true) {
        loop();
    }

    return 0;
}
