// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestWIdget.h"
#include "UMG_Login.generated.h"

/**
 * 
 */
UCLASS()
class TESTWIDGETCPP_API UUMG_Login : public UTestWidget
{
	GENERATED_BODY()

public:
	void NativeConstruct();

	void CreateSignUpViewport();
};
