// Fill out your copyright notice in the Description page of Project Settings.


#include "TestWIdget.h"

void UTestWIdget::TestIDLog()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *FID);
}

void UTestWIdget::TestPasswordLog()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *FPassword);
}

void UTestWIdget::Login(const FText& Text, ETextCommit::Type CommitMethod)
//{
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
    if (Id && Id->HasKeyboardFocus())
    {
        FID = Text.ToString();
    }
    else if (Password && Password->HasKeyboardFocus())
    {
        FPassword = Text.ToString();
    }

    // Create json object
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
    JsonObject->SetStringField(TEXT("email"), FID);
    JsonObject->SetStringField(TEXT("password"), FPassword);

    // Convert json to string
    FString JsonString;
    TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&JsonString);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

    UE_LOG(LogTemp, Warning, TEXT("JSON: %s"), *JsonString);

    // Create http request
    TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->SetVerb("POST");
    HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    HttpRequest->SetURL(TEXT("http://192.168.0.117:8080/api/login"));
    HttpRequest->SetContentAsString(JsonString);

    // Bind response function
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UTestWIdget::HandleHttpRequestComplete);

    // Send request
    HttpRequest->ProcessRequest();
}

void UTestWIdget::HandleHttpRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
    if (bSuccess && Response.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("Response: %s"), *Response->GetContentAsString());

        //// Convert response json to object
        //TSharedPtr<FJsonObject> JsonObject;
        //TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
        //if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
        //{
        //    // Get response fields
        //    bool bLoginSuccess = JsonObject->GetBoolField("success");
        //    FString message = JsonObject->GetStringField("message");

        //    if (bLoginSuccess)
        //    {
        //        UE_LOG(LogTemp, Warning, TEXT("Login success: %s"), *message);
        //    }
        //    else
        //    {
        //        UE_LOG(LogTemp, Warning, TEXT("Login failed: %s"), *message);
        //    }
        //}
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Http request failed"));
    }
}