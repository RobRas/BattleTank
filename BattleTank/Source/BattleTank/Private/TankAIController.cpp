// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	ATank* ControlledTank = GetPlayerTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController found: %s"), *ControlledTank->GetName());
	}
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}