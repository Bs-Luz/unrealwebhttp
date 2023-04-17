// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/EditableText.h"
#include "Json.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "TestWIdget.generated.h"

/**
 * 
 */

//class UEditableText;

UCLASS()
class TESTWIDGETCPP_API UTestWIdget : public UUserWidget
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Test)
        UEditableText* Id;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Test)
        UEditableText* Password;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Test)
        FString FID;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Test)
        FString FPassword;

    UFUNCTION(BlueprintCallable, meta = (keywords = "Test"))
        void TestIDLog();

    UFUNCTION(BlueprintCallable, meta = (keywords = "Test"))
        void TestPasswordLog();

    UFUNCTION(BlueprintCallable, meta = (keywords = "Test"))
        void Login(const FText& Text, ETextCommit::Type CommitMethod);

        void HandleHttpRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);
};
