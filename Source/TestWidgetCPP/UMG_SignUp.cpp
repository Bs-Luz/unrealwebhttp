// Fill out your copyright notice in the Description page of Project Settings.


#include "UMG_SignUp.h"
#include "UMG_Login.h"

void UUMG_SignUp::NativeConstruct()
{
    //Super::NativeConstruct();

    //// 버튼 위젯 생성하기
    //UButton* CreateSignUpButton = Cast<UButton>(GetWidgetFromName(TEXT("CreateSignUpButton")));

    //UButton* BackButton = Cast<UButton>(GetWidgetFromName(TEXT("BackButton")));
    //// 버튼 이벤트 핸들러 등록하기
    //if (CreateSignUpButton)
    //{
    //    CreateSignUpButton->OnClicked.AddDynamic(this, &UTestWidget::OnSignUpButtonClicked);
    //}
    //else if (BackButton)
    //{
    //    BackButton->OnClicked.AddDynamic(this, &UUMG_SignUp::OnBackButtonClicked);
    //}
}

//void UUMG_SignUp::BackButtonClicked()
//{
//    UE_LOG(LogTemp, Warning, TEXT("뒤로가기 버튼이야"));
//
//    // 현재 위젯 제거하기
//    RemoveFromParent();
//
//    // UMG_Login 위젯 생성하기
//    static ConstructorHelpers::FClassFinder<UUMG_Login> LoginWidgetClass(TEXT("/Game/Widget/UMG_Login"));
//    if (LoginWidgetClass.Succeeded())
//    {
//        UUMG_Login* LoginWidget = CreateWidget<UUMG_Login>(GetWorld(), LoginWidgetClass.Class);
//
//        // UMG_Login 위젯 화면에 추가하기
//        if (LoginWidget != nullptr)
//        {
//            LoginWidget->AddToViewport();
//
//            UE_LOG(LogTemp, Warning, TEXT("로그인 위젯 뜸"));
//        }
//        else
//        {
//            UE_LOG(LogTemp, Warning, TEXT("로그인 위젯 안뜸"));
//        }
//    }
//    else
//    {
//        UE_LOG(LogTemp, Warning, TEXT("그냥 다시 해"));
//    }
//}