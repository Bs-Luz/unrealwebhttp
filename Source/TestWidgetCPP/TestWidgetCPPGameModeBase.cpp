// Copyright Epic Games, Inc. All Rights Reserved.


#include "TestWidgetCPPGameModeBase.h"
#include "UMG_Login.h"


ATestWidgetCPPGameModeBase::ATestWidgetCPPGameModeBase()
{		
    Super::BeginPlay();

    // UMG_Login 위젯 생성하기
    static ConstructorHelpers::FClassFinder<UUMG_Login> LoginWidgetClass(TEXT("/Game/Widget/UMG_Login"));
    if (LoginWidgetClass.Succeeded())
    {
        UUMG_Login* LoginWidget = CreateWidget<UUMG_Login>(GetWorld(), LoginWidgetClass.Class);

        // UMG_Login 위젯 화면에 추가하기
        if (LoginWidget != nullptr)
        {
            LoginWidget->AddToViewport();

            UE_LOG(LogTemp, Warning, TEXT("위젯 뜸"));
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("위젯 안뜸"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("그냥 다시 해"));
    }
}

void ATestWidgetCPPGameModeBase::BeginPlay()
{

}