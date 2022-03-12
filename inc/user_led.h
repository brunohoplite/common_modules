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

// Macros
#define USER_LEDS_START UserLedContext ledModules[] = {
#define USER_LED( ... ) { __VA_ARGS__ }
#define USER_LEDS_END }; const unsigned ledModulesCount = ARRAY_SIZE(ledModules);

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
unsigned userLedGetHeartBeatPeriod(UserLedContext* ctx);

extern UserLedContext ledModules[];
extern const unsigned ledModulesCount;
