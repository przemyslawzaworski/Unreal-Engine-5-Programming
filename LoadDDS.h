#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMeshActor.h"
#include "LoadDDS.generated.h"

UCLASS()
class ALoadDDS : public AActor
{
	GENERATED_BODY()
	
	public:	
		ALoadDDS();
		UTexture2D* LoadTexture(const TCHAR* filepath);
		UMaterialInstanceDynamic* SetMaterial(AStaticMeshActor* staticMeshActor, UMaterial* material, UTexture2D* texture);
		UPROPERTY(EditAnywhere, Category = "Materials") UMaterial* StoredMaterial;
		UPROPERTY(EditAnywhere, Category = "Objects") AStaticMeshActor* PlaneActor;

	protected: 
		virtual void BeginPlay() override;
};