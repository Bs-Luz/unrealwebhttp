// Fill out your copyright notice in the Description page of Project Settings.


#include "TestWidget.h"
#include "CreateSignUpWidget.h"
#include "UMG_Login.h"
#include "TestWidgetCPPGameModeBase.h"

void UTestWidget::TestIDLog()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *FID);
}

void UTestWidget::TestPasswordLog()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *FPassword);
}

void UTestWidget::OnLoginButtonClicked(/*const FText& Text, ETextCommit::Type CommitMethod*/)
//{이건 Text값 확인용
//    if (Id && Id->HasKeyboardFocus())
//    {
//        FID = Text.ToString();
//    }
//    else if (Password && Password->HasKeyboardFocus())
//    {
//        FPassword = Text.ToString();
//    }
// 
//    // Check if both FID and FPassword are not empty before converting to JSON
//    if (!FID.IsEmpty() && !FPassword.IsEmpty())
//    {
//        // Create json object
//        TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
//        JsonObject->SetStringField(TEXT("id"), FID);
//        JsonObject->SetStringField(TEXT("password"), FPassword);
//
//        // Convert json to string
//        FString JsonString;
//        TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&JsonString);
//        FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);
//
//        UE_LOG(LogTemp, Warning, TEXT("JSON: %s"), *JsonString);
//    }
//
//}
{
    UE_LOG(LogTemp, Warning, TEXT("로그인 버튼 이벤트야"));

    // Id와 Password 입력값 저장
    if (Id && Id->HasKeyboardFocus())
    {
        FID = Id->GetText().ToString();
    }
    else if (Password && Password->HasKeyboardFocus())
    {
        FPassword = Password->GetText().ToString();
    }

    // JSON 데이터 생성
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
    JsonObject->SetStringField(TEXT("email"), FID);
    JsonObject->SetStringField(TEXT("password"), FPassword);

    // JSON 데이터를 문자열로 변환
    FString JsonString;
    TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&JsonString);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

    // HTTP 요청 생성 및 설정
    TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->SetVerb(TEXT("POST"));
    HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    HttpRequest->SetURL(TEXT("http://192.168.0.117:8080/api/login"));
    HttpRequest->SetContentAsString(JsonString);

    // 요청 완료 시 호출할 함수 설정
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UTestWidget::HandleHttpRequestComplete);

    // 요청 전송
    HttpRequest->ProcessRequest();
}

//EditableText 입력값을 JSON파싱
//void UTestWidget::SignUpButton(const FText& Text/*const FText& Text, ETextCommit::Type CommitMethod*/)
//{텍스트값 확인용
//    // Id와 Password 입력값 저장
//    if (Id && Id->HasKeyboardFocus())
//    {
//        FID = Text.ToString();
//    }
//    else if (Password && Password->HasKeyboardFocus())
//    {
//        FPassword = Text.ToString();
//    }
//
//    // JSON 데이터 생성
//    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
//    JsonObject->SetStringField(TEXT("email"), FID);
//    JsonObject->SetStringField(TEXT("password"), FPassword);
//
//    // JSON 데이터를 문자열로 변환
//    FString JsonString;
//    TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&JsonString);
//    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);
//
//    // HTTP 요청 생성 및 설정
//    TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
//    HttpRequest->SetVerb(TEXT("POST"));
//    HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
//    HttpRequest->SetURL(TEXT("http://192.168.0.117:8080/api/signup"));
//    HttpRequest->SetContentAsString(JsonString);
//
//    // 요청 완료 시 호출할 함수 설정
//    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UTestWidget::HandleHttpRequestComplete);
//
//    // 요청 전송
//    HttpRequest->ProcessRequest();
//}

void UTestWidget::OnSignUpButtonClicked()
{
    UE_LOG(LogTemp, Warning, TEXT("회원가입 하는 버튼 이벤트야"));

    // Id와 Password 입력값 저장
    if (Id && Id->HasKeyboardFocus())
    {
        FID = Id->GetText().ToString();
    }
    else if (Password && Password->HasKeyboardFocus())
    {
        FPassword = Password->GetText().ToString();
    }

    // JSON 데이터 생성
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
    JsonObject->SetStringField(TEXT("email"), FID);
    JsonObject->SetStringField(TEXT("password"), FPassword);

    // JSON 데이터를 문자열로 변환
    FString JsonString;
    TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&JsonString);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

    // HTTP 요청 생성 및 설정
    TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->SetVerb(TEXT("POST"));
    HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    HttpRequest->SetURL(TEXT("http://192.168.0.117:8080/api/signup"));
    HttpRequest->SetContentAsString(JsonString);

    // 요청 완료 시 호출할 함수 설정
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UTestWidget::HandleHttpRequestComplete);

    // 요청 전송
    HttpRequest->ProcessRequest();
}

void UTestWidget::OnCreateSignUpButtonClicked()
{
    // 현재 위젯 제거하기
    RemoveFromParent();

    UE_LOG(LogTemp, Warning, TEXT("회원가입창으로 넘어가는 버튼 이벤트야"));

    /*CraeteSignUpViewPort();*/

    //// UMG_SignUp 위젯 생성하기
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

void UTestWidget::OnBackButtonClicked()
{
    

    // 현재 위젯 제거하기
    RemoveFromParent();

    UE_LOG(LogTemp, Warning, TEXT("뒤로가기 버튼이야"));

    // UMG_Login 위젯 생성하기
    static ConstructorHelpers::FClassFinder<UUMG_Login> LoginWidgetClass(TEXT("/Game/Widget/UMG_Login"));
    if (LoginWidgetClass.Succeeded())
    {
        UUMG_Login* LoginWidget = CreateWidget<UUMG_Login>(GetWorld(), LoginWidgetClass.Class);

        // UMG_Login 위젯 화면에 추가하기
        if (LoginWidget != nullptr)
        {
            LoginWidget->AddToViewport();

            UE_LOG(LogTemp, Warning, TEXT("로그인 위젯 뜸"));
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("로그인 위젯 안뜸"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("그냥 다시 해"));
    }
}

void UTestWidget::HandleHttpRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
    if (bSuccess && Response.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("Response: %s"), *Response->GetContentAsString());

        // Convert response json to object
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
        if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
        {
            // Get response fields
            bool bLoginSuccess = JsonObject->GetBoolField("success");
            FString message = JsonObject->GetStringField("message");

            if (bLoginSuccess)
            {
                UE_LOG(LogTemp, Warning, TEXT("Login success: %s"), *message);
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("Login failed: %s"), *message);
            }
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Http request failed"));
    }
}
