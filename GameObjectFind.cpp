#include "GameObjectFind.h"
#include "EngineUtils.h"

AGameObjectFind::AGameObjectFind()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGameObjectFind::Find(const TCHAR* name)
{
	AActor* floor = FindObject<AActor>(GetWorld()->GetCurrentLevel(), name);
	if (floor)
	{
		FVector location = floor->GetActorLocation();
		UE_LOG(LogTemp, Warning, TEXT("Floor location: X=%f, Y=%f, Z=%f"), location.X, location.Y, location.Z);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Floor object not found in the scene!"));
	}
}

void AGameObjectFind::BeginPlay()
{
	Super::BeginPlay();
	Find(TEXT("Floor"));
}

void AGameObjectFind::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}