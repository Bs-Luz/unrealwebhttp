// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TestWidget.h"
#include "TestWidgetCPPGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TESTWIDGETCPP_API ATestWidgetCPPGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ATestWidgetCPPGameModeBase();

    //void ATestWidgetCPPGameModeBase::BeginPlay();

	UPROPERTY()
		UTestWidget* TestWidget;

	//void BeginPlay();
};
