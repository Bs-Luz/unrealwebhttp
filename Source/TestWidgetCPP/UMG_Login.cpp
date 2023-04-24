// Fill out your copyright notice in the Description page of Project Settings.


#include "UMG_Login.h"
//#include "UMG_SignUp.h"
#include "CreateSignUpWidget.h"

void UUMG_Login::NativeConstruct()
{
    Super::NativeConstruct();

    UButton* LoginButton = Cast<UButton>(GetWidgetFromName(TEXT("LoginButton")));

    UButton* SignUpButton = Cast<UButton>(GetWidgetFromName(TEXT("SignUpButton")));
    // 버튼 이벤트 핸들러 등록하기
    if (LoginButton)
    {
        LoginButton->OnClicked.AddDynamic(this, &UTestWidget::OnLoginButtonClicked);

        UE_LOG(LogTemp, Warning, TEXT("로그인 버튼 이벤트야!!"));

    }
    if (SignUpButton)
    {
        SignUpButton->OnClicked.AddDynamic(this, &UUMG_Login::OnCreateSignUpButtonClicked);

        UE_LOG(LogTemp, Warning, TEXT("회원가입창으로 넘어가는 버튼 이벤트야!!"));

    }
}

//void UUMG_Login::OnCreateSignUpButtonClicked()
//{
//    // 현재 위젯 제거하기
//    RemoveFromParent();
//
//    UE_LOG(LogTemp, Warning, TEXT("회원가입창으로 넘어가는 버튼 이벤트야"));
//
//    // UMG_SignUp 위젯 생성하기
//    static ConstructorHelpers::FClassFinder<UCreateSignUpWidget> SignUpWidgetClass(TEXT("/Game/Widget/CreateSignUpWidget"));
//    if (SignUpWidgetClass.Succeeded())
//    {
//        UCreateSignUpWidget* SignUpWidget = CreateWidget<UCreateSignUpWidget>(GetWorld(), SignUpWidgetClass.Class);
//        if (SignUpWidget != nullptr)
//        {
//            // 생성된 위젯이 화면에 추가될 수 있도록 AddToViewport() 함수를 호출합니다.
//            SignUpWidget->AddToViewport();
//        }
//        else
//        {
//            // 위젯 생성에 실패한 경우, 에러 메시지를 출력합니다.
//            UE_LOG(LogTemp, Error, TEXT("Failed to create UMG_SignUp widget."));
//        }
//    }
//    else
//    {
//        // UUMG_SignUp 클래스가 로드되지 않았을 경우, 에러 메시지를 출력합니다.
//        UE_LOG(LogTemp, Error, TEXT("Failed to find UMG_SignUp class."));
//    }
//}

//void UUMG_Login::CreateSignUpViewport()
//{
//    /*UE_LOG(LogTemp, Warning, TEXT("회원가입창으로 넘어가는 버튼 이벤트야"));*/
//
//    // 현재 위젯 제거하기
//    RemoveFromParent();
//
//    // UMG_SignUp 위젯 생성하기
//    static ConstructorHelpers::FClassFinder<UCreateSignUpWidget> SignUpWidgetClass(TEXT("/Game/Widget/CreateSignUpWidget"));
//    if (SignUpWidgetClass.Succeeded())
//    {
//        UCreateSignUpWidget* SignUpWidget = CreateWidget<UCreateSignUpWidget>(GetWorld(), SignUpWidgetClass.Class);
//        if (SignUpWidget != nullptr)
//        {
//            // 생성된 위젯이 화면에 추가될 수 있도록 AddToViewport() 함수를 호출합니다.
//            SignUpWidget->AddToViewport();
//        }
//        else
//        {
//            // 위젯 생성에 실패한 경우, 에러 메시지를 출력합니다.
//            UE_LOG(LogTemp, Error, TEXT("Failed to create UMG_SignUp widget."));
//        }
//    }
//    else
//    {
//        // UUMG_SignUp 클래스가 로드되지 않았을 경우, 에러 메시지를 출력합니다.
//        UE_LOG(LogTemp, Error, TEXT("Failed to find UMG_SignUp class."));
//    }
//}