#include "LoadDDS.h"

UTexture2D* _Texture;
UMaterialInstanceDynamic* _MaterialInstanceDynamic;

ALoadDDS::ALoadDDS()
{

}

void ALoadDDS::BeginPlay()
{
    Super::BeginPlay();
    _Texture = LoadTexture(TEXT("D:/plasma.dds"));
    _MaterialInstanceDynamic = SetMaterial(PlaneActor, StoredMaterial, _Texture);
}

UTexture2D* ALoadDDS::LoadTexture(const TCHAR* filepath)
{
    TArray<uint8> bytes;
    if (!FFileHelper::LoadFileToArray(bytes, filepath)) return nullptr;
    if (bytes.Num() < 128) return nullptr;
    int32 Width = (bytes[17] << 8) | bytes[16];
    int32 Height = (bytes[13] << 8) | bytes[12];
    bool bMipmaps = bytes[28] > 0;
    EPixelFormat format = (bytes[87] == 49) ? PF_DXT1 : PF_DXT5;
    UTexture2D* texture = UTexture2D::CreateTransient(Width, Height, format);
    void* textureData = texture->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
    FMemory::Memcpy(textureData, bytes.GetData() + 128, bytes.Num() - 128);
    texture->PlatformData->Mips[0].BulkData.Unlock();
    texture->PlatformData->PixelFormat = format;
    texture->AddressX = TA_Clamp;
    texture->AddressY = TA_Clamp;
    texture->UpdateResource();
    return texture;
}

UMaterialInstanceDynamic* ALoadDDS::SetMaterial(AStaticMeshActor* staticMeshActor, UMaterial* material, UTexture2D* texture)
{
    UMaterialInstanceDynamic* materialInstance = UMaterialInstanceDynamic::Create(material, nullptr);
    materialInstance->SetTextureParameterValue(FName("Param"), texture);
    UStaticMeshComponent* meshComponent = staticMeshActor->GetStaticMeshComponent();
    meshComponent->SetMaterial(0, materialInstance);
    return materialInstance;
}