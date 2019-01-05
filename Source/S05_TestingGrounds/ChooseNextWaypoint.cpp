// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrollingGuard.h"
#include "AIController.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	//UE_LOG(LogTemp, Warning, TEXT("Waypoint index %i"), Index);

	auto AIController = OwnerComp.GetAIOwner();
	auto PatrollingGuard = Cast<APatrollingGuard>(AIController->GetPawn());
	auto PatrolPoints = PatrollingGuard->GetPatrolPoints();

	BlackboardComp->SetValueAsObject(Waypoint.SelectedKeyName, PatrolPoints[Index++]);

	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index % PatrolPoints.Num());

	return EBTNodeResult::Succeeded;
}

