// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "UNewMissionWidget.generated.h"
   
/**
 * 
 */
UCLASS()
class NEWMISSIONWIDGET_API UNewMissionWidget final : public UUserWidget
{
	GENERATED_BODY()

	FText PreviewMessage = FText::FromString("Preview Phrase");

	FString CurrentMessage;
	
	FTimerHandle TimerHandle;

	bool bCanPrint = true;
	
	int32 CurrentMassageLength = 0;

	const float NewCharacterDelay = 0.1f;
protected:
	UPROPERTY(BlueprintReadWrite, Meta = (BindWidget))
	UTextBlock* MessageLabel;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true), Category = "New Mission Settings")
	UFont* MessageFont;
	
	UFUNCTION(BlueprintCallable)
	void PrintMessage(FText MessageToPrint);
	
	void PrintNextCharacter();
	
	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;
	
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};
