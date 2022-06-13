// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class MYTESTPROJECT01_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector RunningTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// 언리얼 에디터에서 공개하기 위한 UPROPERTY 매크로 선언

	FVector FloatingSpeed;
	// 액터의 움직임 속도를 결정할 변수로 float 타입의 FloatingSpeed 변수 선언
};
