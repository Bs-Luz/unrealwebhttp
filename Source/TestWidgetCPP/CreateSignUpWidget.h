// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestWIdget.h"
#include "CreateSignUpWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTWIDGETCPP_API UCreateSignUpWidget : public UTestWidget
{
	GENERATED_BODY()
		void NativeConstruct();

	void BackButtonClicked();
};
