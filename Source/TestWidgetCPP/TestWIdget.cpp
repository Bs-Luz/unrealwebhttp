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

//void UTestWidget::HandleLoginHttpRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
//{
//    
//        UE_LOG(LogTemp, Warning, TEXT("HandleLoginHttpRequestComplete called"));
//
//        if (!bSuccess || !Response.IsValid())
//        {
//            UE_LOG(LogTemp, Error, TEXT("HTTP Request failed: %s"), *Request->GetURL());
//            return;
//        }
//
//        int32 ResponseCode = Response->GetResponseCode();
//        UE_LOG(LogTemp, Warning, TEXT("HTTP Response Code: %d"), ResponseCode);
//
//        // 서버 응답 문자열 파싱
//        FString ResponseString = Response->GetContentAsString();
//        TSharedPtr<FJsonObject> JsonObject;
//        TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(ResponseString);
//
//        if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
//        {
//            // 로그인 성공 여부 확인
//            bool bLoginSuccess = JsonObject->GetBoolField(TEXT("success"));
//            if (bLoginSuccess)
//            {
//                // 데디케이티드 서버 정보 파싱
//                FString DedicatedServerIP = JsonObject->GetStringField(TEXT("ip"));
//                int32 DedicatedServerPort = JsonObject->GetNumberField(TEXT("port"));
//
//                // 데디케이티드 서버 상태 확인
//                FString DedicatedServerStatus = JsonObject->GetStringField(TEXT("status"));
//
//                if (DedicatedServerStatus.Equals(TEXT("available"), ESearchCase::IgnoreCase))
//                {
//                    UE_LOG(LogTemp, Warning, TEXT("데디케이티드 서버 이용 가능"));
//                    // 데디케이티드 서버 정보 가져오기
//                    TSharedPtr<FJsonObject> DedicatedServerInfoObject = JsonObject->GetObjectField(TEXT("dedicatedServerInfo"));
//
//                    FString DedicatedServerInfoIP = DedicatedServerInfoObject->GetStringField(TEXT("ip"));
//                    int32 DedicatedServerInfoPort = DedicatedServerInfoObject->GetNumberField(TEXT("port"));
//
//                    UE_LOG(LogTemp, Warning, TEXT("데디케이티드 서버 IP: %s"), *DedicatedServerInfoIP);
//                    UE_LOG(LogTemp, Warning, TEXT("데디케이티드 서버 Port: %d"), DedicatedServerInfoPort);
//
//                    // 데디케이티드 서버에 접속하는 함수 호출
//                    ConnectToDedicatedServer(DedicatedServerInfoIP, DedicatedServerInfoPort);
//                }
//                else if (DedicatedServerStatus.Equals(TEXT("unavailable"), ESearchCase::IgnoreCase))
//                {
//                    UE_LOG(LogTemp, Warning, TEXT("데디케이티드 서버 이용 불가"));
//                    // TODO: 데디케이티드 서버 이용 불가 처리
//                }
//            }
//        }
//    
//}

//void UTestWidget::ConnectToDedicatedServer(const FString& ServerIP, int32 ServerPort)
//{
//    // 접속할 서버 주소
//    TSharedPtr<FInternetAddr> RemoteAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
//
//    bool bIsValid;
//    RemoteAddr->SetIp(*IPAddress, bIsValid);
//    RemoteAddr->SetPort(PortNumber);
//
//    if (!bIsValid)
//    {
//        UE_LOG(LogTemp, Error, TEXT("Invalid IP Address: %s"), *IPAddress);
//        return;
//    }
//
//    // 소켓 생성
//    FSocket* Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), true);
//
//    // 비동기 접속 시도
//    if (Socket->Connect(*RemoteAddr))
//    {
//        UE_LOG(LogTemp, Warning, TEXT("서버 접속 성공!"));
//        // TODO: 서버와 통신하는 로직 작성
//    }
//    else
//    {
//        UE_LOG(LogTemp, Error, TEXT("서버 접속 실패: %s:%d"), *IPAddress, PortNumber);
//    }
//}

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

    //    static ConstructorHelpers::FClassFinder<UCreateSignUpWidget> SignUpWidgetClass(TEXT("/Game/Widget/CreateSignUpWidget"));
    //    UCreateSignUpWidget* SignUpWidget = CreateWidget<UCreateSignUpWidget>(GetWorld(), SignUpWidgetClass.Class);
    //    if (SignUpWidget != nullptr)
    //    {
    //        // 생성된 위젯이 화면에 추가될 수 있도록 AddToViewport() 함수를 호출합니다.
    //        SignUpWidget->AddToViewport();
    //    }
    //    else
    //    {
    //        // 위젯 생성에 실패한 경우, 에러 메시지를 출력합니다.
    //        UE_LOG(LogTemp, Error, TEXT("Failed to create UMG_SignUp widget."));
    //    }
    

    /*CraeteSignUpViewPort();*/

    ////// UMG_SignUp 위젯 생성하기
    //static ConstructorHelpers::FClassFinder<UCreateSignUpWidget> SignUpWidgetClass(TEXT("/Game/Widget/CreateSignUpWidget"));
    //if (SignUpWidgetClass.Succeeded())
    //{
    //    UCreateSignUpWidget* SignUpWidget = CreateWidget<UCreateSignUpWidget>(GetWorld(), SignUpWidgetClass.Class);
    //    if (SignUpWidget != nullptr)
    //    {
    //        // 생성된 위젯이 화면에 추가될 수 있도록 AddToViewport() 함수를 호출합니다.
    //        SignUpWidget->AddToViewport();
    //    }
    //    else
    //    {
    //        // 위젯 생성에 실패한 경우, 에러 메시지를 출력합니다.
    //        UE_LOG(LogTemp, Error, TEXT("Failed to create UMG_SignUp widget."));
    //    }
    //}
    //else
    //{
    //    // UUMG_SignUp 클래스가 로드되지 않았을 경우, 에러 메시지를 출력합니다.
    //    UE_LOG(LogTemp, Error, TEXT("Failed to find UMG_SignUp class."));
    //}
}

void UTestWidget::OnBackButtonClicked()
{
    

    // 현재 위젯 제거하기
    RemoveFromParent();

    UE_LOG(LogTemp, Warning, TEXT("뒤로가기 버튼이야"));

    
    //// UMG_Login 위젯 생성하기
    //static ConstructorHelpers::FClassFinder<UUMG_Login> LoginWidgetClass(TEXT("/Game/Widget/UMG_Login"));
    //if (LoginWidgetClass.Succeeded())
    //{
    //    UUMG_Login* LoginWidget = CreateWidget<UUMG_Login>(GetWorld(), LoginWidgetClass.Class);

    //    // UMG_Login 위젯 화면에 추가하기
    //    if (LoginWidget != nullptr)
    //    {
    //        LoginWidget->AddToViewport();

    //        UE_LOG(LogTemp, Warning, TEXT("로그인 위젯 뜸"));
    //    }
    //    else
    //    {
    //        UE_LOG(LogTemp, Warning, TEXT("로그인 위젯 안뜸"));
    //    }
    //}
    //else
    //{
    //    UE_LOG(LogTemp, Warning, TEXT("그냥 다시 해"));
    //}
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
