// Copyright Epic Games, Inc. All Rights Reserved.


#include "TestWidgetCPPGameModeBase.h"
#include "UMG_Login.h"
#include "CreateSignUpWidget.h"


ATestWidgetCPPGameModeBase::ATestWidgetCPPGameModeBase()
{		
    /*Super::BeginPlay();*/

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

    CraeteSignUpViewPort();
}

void ATestWidgetCPPGameModeBase::CraeteSignUpViewPort()
{
    // UMG_SignUp 위젯 생성하기
    static ConstructorHelpers::FClassFinder<UCreateSignUpWidget> SignUpWidgetClass(TEXT("/Game/Widget/CreateSignUpWidget"));
    if (SignUpWidgetClass.Succeeded())
    {
        UCreateSignUpWidget* SignUpWidget = CreateWidget<UCreateSignUpWidget>(GetWorld(), SignUpWidgetClass.Class);
        if (SignUpWidget != nullptr)
        {
            // 생성된 위젯이 화면에 추가될 수 있도록 AddToViewport() 함수를 호출합니다.
            SignUpWidget->AddToViewport();
        }
        else
        {
            // 위젯 생성에 실패한 경우, 에러 메시지를 출력합니다.
            UE_LOG(LogTemp, Error, TEXT("Failed to create UMG_SignUp widget."));
        }
    }
    else
    {
        // UUMG_SignUp 클래스가 로드되지 않았을 경우, 에러 메시지를 출력합니다.
        UE_LOG(LogTemp, Error, TEXT("Failed to find UMG_SignUp class."));
    }    
}

//void ATestWidgetCPPGameModeBase::BeginPlay()
//{
//
//}