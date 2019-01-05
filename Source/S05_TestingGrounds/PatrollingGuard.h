// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class S05_TESTINGGROUNDS_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

public:
	TArray<AActor*> GetPatrolPoints() const { return PatrolPointsCPP; };
	
protected:
	UPROPERTY(EditAnywhere, Category = "Setup")
	TArray<AActor*> PatrolPointsCPP;  //make sure this is not 'PatrolPoints' as it will clash with the existing variables Patrol Points in the ThirdPersonCharacter blueprint
	
};