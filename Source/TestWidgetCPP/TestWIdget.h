// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/EditableText.h"
#include "Components/Button.h"
#include "UObject/ConstructorHelpers.h"
#include "Json.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "TestWidget.generated.h"

/**
 * 
 */

UCLASS()
class TESTWIDGETCPP_API UTestWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, Category = Test)
        UEditableText* Id;

    UPROPERTY(BlueprintReadWrite, Category = Test)
        UEditableText* Password;

    UPROPERTY(BlueprintReadWrite, Category = Test)
        FString FID;

    UPROPERTY(BlueprintReadWrite, Category = Test)
        FString FPassword;

    /*UPROPERTY(BlueprintReadWrite, Category = Test)
        UButton* LoginButton;

    UPROPERTY(BlueprintReadWrite, Category = Test)
        UButton* SignUpButton;*/

    UFUNCTION(BlueprintCallable, meta = (keywords = "Test"))
        void TestIDLog();

    UFUNCTION(BlueprintCallable, meta = (keywords = "Test"))
        void TestPasswordLog();

        /*void OnTextCommitted(const FText& NewText, ETextCommit::Type CommitInfo);*/

    UFUNCTION(BlueprintCallable, meta = (keywords = "Test"))
        void OnLoginButtonClicked(/*, ETextCommit::Type CommitMethod*/ );

    //UFUNCTION(BlueprintCallable, meta = (keywords = "Test"))
    //    void SignUpButton(const FText& Text/*, ETextCommit::Type CommitMethod*/ );

    UFUNCTION(BlueprintCallable, meta = (keywords = "Test"))
        void OnSignUpButtonClicked();

    UFUNCTION(BlueprintCallable, meta = (keywords = "Test"))
        void OnCreateSignUpButtonClicked();

    UFUNCTION(BlueprintCallable, meta = (keywords = "Test"))
        void OnBackButtonClicked();

        void HandleHttpRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

        bool ConnectToDedicatedServer();

//private:

    const FString SERVER_IP_ADDRESS = TEXT("127.0.0.1");

    const int32 SERVER_PORT_NUMBER = 8080;

    const FString CLIENT_INFO = TEXT("haha");
};