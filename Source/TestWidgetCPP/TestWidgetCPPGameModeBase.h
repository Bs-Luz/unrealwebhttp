// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TestWidget.h"
#include "Components/Widget.h"
#include "Blueprint/UserWidget.h"
#include "Engine/GameViewportClient.h"
#include "Engine/StreamableManager.h"
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

	void CraeteSignUpViewPort();

	/*virtual void BeginPlay();*/
};