// Copyright Epic Games, Inc. All Rights Reserved.


#include "TestWidgetCPPGameModeBase.h"

ATestWidgetCPPGameModeBase::ATestWidgetCPPGameModeBase()
{		
    // UTestWidget 객체 생성
    TestWidget = CreateDefaultSubobject<UTestWidget>(TEXT("UMG_Login"));

    // UTestWidget을 뷰포트에 추가
    if (TestWidget)
    {
        TestWidget->AddToViewport();
    }
}

//void ATestWidgetCPPGameModeBase::BeginPlay()
//{
//    Super::BeginPlay();
//
//    if (TestWidget)
//    {
//        TestWidget->LoginButton->OnClicked.AddDynamic(TestWidget, &UTestWidget::Login);
//        TestWidget->SignUpButton->OnClicked.AddDynamic(TestWidget, &UTestWidget::SignUp);
//    }
//}

