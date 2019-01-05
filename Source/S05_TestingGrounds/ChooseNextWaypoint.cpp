// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "AIController.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	//UE_LOG(LogTemp, Warning, TEXT("Waypoint index %i"), Index);

	auto AIController = OwnerComp.GetAIOwner();
	auto PatrollingGuard = Cast<ATP_ThirdPersonCharacter>(AIController->GetPawn());
	auto PatrolRoute = PatrollingGuard->FindComponentByClass<UPatrolRoute>();
	
	if (!PatrolRoute) { return  EBTNodeResult::Failed; }
	
	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() != 0)
	{
		BlackboardComp->SetValueAsObject(Waypoint.SelectedKeyName, PatrolPoints[Index++]);
		BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index % PatrolPoints.Num());
	}

	return EBTNodeResult::Succeeded;
}

