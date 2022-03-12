//
// user_led.h
//
// Author: Bruno Malli
// All rights reserved.
//


#include "user_led.h"


void userLedInit(void)
{
	for(unsigned i = 0; i < userLedModulesCount; i++)
	{
		UserLedContext* ctx = &userLedModules[i];

		if(ctx->init.kind == LED_HEARTBEAT)
			ctx->heartBeatTicks = GetTick();
		else
			GpioWritePin(ctx->init.ledPort, ctx->init.ledPin, (ctx->init.isActiveLow ? GPIO_HIGH : GPIO_LOW));
	}
}

void userLedHeartBeat(void)
{
	for(unsigned i = 0; i < userLedModulesCount; i++)
	{
		UserLedContext* ctx = &userLedModules[i];

		if(ctx->init.kind == LED_HEARTBEAT)
		{
			GpioTogglePin(ctx->init.ledPort, ctx->init.ledPin);
			ctx->heartBeatTicks = GetTick();
		}
	}
}

void userLedSetHeartBeatPeriod(UserLedContext* ctx, unsigned period)
{
	ctx->heartBeatPeriod = period;
}

const unsigned userLedGetHeartBeatPeriod(UserLedContext* ctx)
{
	return ctx->heartBeatPeriod;
}
