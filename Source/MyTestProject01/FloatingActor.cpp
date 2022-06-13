// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FloatingSpeed = FVector(1.0f, 1.0f, 1.0f);

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();	// 액터의 현재 위치 값을 FVector 타입의 NewLocation라는 지역번수를 만들어 저장
	// FVector = 언리얼엔진에서 위치와 속도 등을 다루기 위한 타입

	float DeltaX = (FMath::Sin(RunningTime.X + DeltaTime * FloatingSpeed.X) - FMath::Sin(RunningTime.X));
	float DeltaY = (FMath::Sin(RunningTime.Y + DeltaTime * FloatingSpeed.Y) - FMath::Sin(RunningTime.Y));
	float DeltaZ = (FMath::Sin(RunningTime.Z + DeltaTime * FloatingSpeed.Z) - FMath::Sin(RunningTime.Z));
	// Sin 그래프를 따라서 오브젝트가 동작하는 시간동안 DeltaTime이 더해져서 앞서나가는 값과 원본 값의 차를 구해서 액터가 얼마나 위 아래로 움직여야 하는지 값을 구할 수 있음
	// Floating Speed = 위에 액터의 속도값을 임의로 변경하기 위해 추가
	
	NewLocation += FVector(DeltaX, DeltaY, DeltaZ) * 20.0f;

	RunningTime += DeltaTime * FloatingSpeed;
	// DeltaTime 변수는 Tick 함수가 시스템에서 매개변수로 가져오는 변수로써 매 프레임 호출되는 Tick 함수가 이전 프레임에서 호출되고 나서 얼마의 시간이 흐른 뒤에 다시 Tick 함수가 호출되었는지에 대한 변수
	// : Tick 함수가 지난 번 호출 시점으로부터 새로 호출된 시점까지 걸린 시간
	// Floating Speed = 위에 액터의 속도값을 임의로 변경하기 위해 추가

	SetActorLocation(NewLocation);
	// SetActorLocation : 액터를 원하는 좌표 값으로 이동시키기 위한 함수;

}

