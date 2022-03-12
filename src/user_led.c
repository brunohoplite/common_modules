//
// user_led.h
//
// Author: Bruno Malli
// All rights reserved.
//


#include "user_led.h"


void userLedInit(void)
{
	for(unsigned i = 0; i < ledModulesCount; i++)
	{
		UserLedContext* ctx = &ledModules[i];

		if(ctx->init.kind == LED_HEARTBEAT)
			ctx->heartBeatTicks = GetTick();
		else
			GpioWritePin(ctx->init.ledPort, ctx->init.ledPin, (ctx->init.isActiveLow ? GPIO_HIGH : GPIO_LOW));
	}
}

void userLedHeartBeat(void)
{
	for(unsigned i = 0; i < ledModulesCount; i++)
	{
		UserLedContext* ctx = &ledModules[i];

		if(ctx->init.kind == LED_HEARTBEAT)
		{
			GpioTogglePin(ctx.ledPort, ctx.ledPin);
			ctx->heartBeatTicks = HAL_GetTick();
		}
	}
}

void userLedSetHeartBeatPeriod(UserLedContext* ctx, unsigned period)
{
	ctx->heartBeatPeriod = period;
}

unsigned userLedGetHeartBeatPeriod(UserLedContext* ctx)
{
	return const ctx->heartBeatPeriod;
}
