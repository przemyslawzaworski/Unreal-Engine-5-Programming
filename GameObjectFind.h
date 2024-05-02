#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameObjectFind.generated.h"

UCLASS()
class BLANK_API AGameObjectFind : public AActor
{
	GENERATED_BODY()
	
public:	
	AGameObjectFind();

private:
	void Find(const TCHAR* name);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};