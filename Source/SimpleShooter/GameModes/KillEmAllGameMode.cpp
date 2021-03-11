// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleShooter/GameModes/KillEmAllGameMode.h"
#include "GameFramework/Controller.h"
#include "EngineUtils.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);
	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	if (PlayerController != nullptr)
	{
		EndGame(false);
	}
}

void AKillEmAllGameMode::EndGame(bool isPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool isWinner = Controller->IsPlayerController() == isPlayerWinner;
		// pass in the pawn of person who did the killing to focus the person who killed you
		Controller->GameHasEnded(Controller->GetPawn(), isWinner);
		/*if (isPlayerWinner)
		{
			Controller->GameHasEnded(nullptr, isWinner);
		}
		else
		{
			Controller->GameHasEnded(nullptr, !isWinner);
		}*/
	}
}
