// Fill out your copyright notice in the Description page of Project Settings.


#include "UNewMissionWidget.h"

#include "Engine/Font.h"

void UNewMissionWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (!MessageLabel)
	{
		return;
	}
	
	MessageLabel->SetText(PreviewMessage);
	
	if (!MessageFont)
	{
		return;
	}

	MessageLabel->SetFont(MessageFont->GetLegacySlateFontInfo());
}

void UNewMissionWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (MessageLabel)
	{
		MessageLabel->SetText(FText::FromString(""));
	}
}


void UNewMissionWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UNewMissionWidget::PrintMessage(const FText MessageToPrint)
{
	if (!bCanPrint)
	{
		return;
	}

	bCanPrint = false;

	CurrentMessage = MessageToPrint.ToString();

	CurrentMassageLength = CurrentMessage.Len();
	
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UNewMissionWidget::PrintNextCharacter, NewCharacterDelay, true);
}

void UNewMissionWidget::PrintNextCharacter()
{
	CurrentMassageLength--;

	if (CurrentMassageLength < 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);

		bCanPrint = true;
	}

	const FString ChoppedMessage = CurrentMessage.LeftChop(CurrentMassageLength);

	MessageLabel->SetText(FText::FromString(ChoppedMessage));
}
