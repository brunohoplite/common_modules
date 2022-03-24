//
// user_led.c
//
// Author: Bruno Malli
// All rights reserved.
//

#pragma once

#include "common.h"


// Constants
#define DEFAULT_USER_LED_PERIOD    1000
#define ALTERNATE_LED_PERIOD    250

// Macros
#define USER_LEDS_START UserLedContext userLedModules[] = {
#define USER_LED( ... ) { { __VA_ARGS__ } }
#define USER_LEDS_END }; const unsigned userLedModulesCount = ARRAY_SIZE(userLedModules);

// Types
typedef enum {
	LED_HEARTBEAT,
	LED_SOLID
}LedKind;

typedef struct{
	GpioPort* ledPort;
	uint16_t ledPin;
	LedKind kind;
	bool isActiveLow;
}UserLedInit;

typedef struct{
	const UserLedInit init;
	uint32_t heartBeatTicks;
	unsigned heartBeatPeriod;
}UserLedContext;


// API
void userLedInit(void);
void userLedHeartBeat(void);
void userLedSetHeartBeatPeriod(UserLedContext* ctx, unsigned period);
const unsigned userLedGetHeartBeatPeriod(UserLedContext* ctx);

extern UserLedContext userLedModules[];
extern const unsigned userLedModulesCount;
