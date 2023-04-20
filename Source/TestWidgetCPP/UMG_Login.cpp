// Fill out your copyright notice in the Description page of Project Settings.


#include "UMG_Login.h"
#include "UMG_SignUp.h"

void UUMG_Login::NativeConstruct()
{
    Super::NativeConstruct();

    UButton* LoginButton = Cast<UButton>(GetWidgetFromName(TEXT("LoginButton")));

    UButton* SignUpButton = Cast<UButton>(GetWidgetFromName(TEXT("CreateSignUpButton")));
    // 버튼 이벤트 핸들러 등록하기
    if (LoginButton)
    {
        LoginButton->OnClicked.AddDynamic(this, &UTestWidget::OnLoginButtonClicked);
    }
    else if (SignUpButton)
    {
        SignUpButton->OnClicked.AddDynamic(this, &UUMG_Login::CreateSignUpViewport);
    }
}

void UUMG_Login::CreateSignUpViewport()
{
    UE_LOG(LogTemp, Warning, TEXT("회원가입창으로 넘어가는 버튼이야"));

    // 현재 위젯 제거하기
    RemoveFromParent();

    // UMG_Login 위젯 생성하기
    static ConstructorHelpers::FClassFinder<UUMG_SignUp> SignUpWidgetClass(TEXT("/Game/Widget/UMG_SignUp"));
    if (SignUpWidgetClass.Succeeded())
    {
        UUMG_SignUp* SignUpWidget = CreateWidget<UUMG_SignUp>(GetWorld(), SignUpWidgetClass.Class);

        // UMG_Login 위젯 화면에 추가하기
        if (SignUpWidget != nullptr)
        {
            SignUpWidget->AddToViewport();

            UE_LOG(LogTemp, Warning, TEXT("회원가입 위젯 뜸"));
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("회원가입 위젯 안뜸"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("그냥 다시 해"));
    }
}