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

	FVector NewLocation = GetActorLocation();	// ������ ���� ��ġ ���� FVector Ÿ���� NewLocation��� ���������� ����� ����
	// FVector = �𸮾������� ��ġ�� �ӵ� ���� �ٷ�� ���� Ÿ��

	float DeltaX = (FMath::Sin(RunningTime.X + DeltaTime * FloatingSpeed.X) - FMath::Sin(RunningTime.X));
	float DeltaY = (FMath::Sin(RunningTime.Y + DeltaTime * FloatingSpeed.Y) - FMath::Sin(RunningTime.Y));
	float DeltaZ = (FMath::Sin(RunningTime.Z + DeltaTime * FloatingSpeed.Z) - FMath::Sin(RunningTime.Z));
	// Sin �׷����� ���� ������Ʈ�� �����ϴ� �ð����� DeltaTime�� �������� �ռ������� ���� ���� ���� ���� ���ؼ� ���Ͱ� �󸶳� �� �Ʒ��� �������� �ϴ��� ���� ���� �� ����
	// Floating Speed = ���� ������ �ӵ����� ���Ƿ� �����ϱ� ���� �߰�
	
	NewLocation += FVector(DeltaX, DeltaY, DeltaZ) * 20.0f;

	RunningTime += DeltaTime * FloatingSpeed;
	// DeltaTime ������ Tick �Լ��� �ý��ۿ��� �Ű������� �������� �����ν� �� ������ ȣ��Ǵ� Tick �Լ��� ���� �����ӿ��� ȣ��ǰ� ���� ���� �ð��� �帥 �ڿ� �ٽ� Tick �Լ��� ȣ��Ǿ������� ���� ����
	// : Tick �Լ��� ���� �� ȣ�� �������κ��� ���� ȣ��� �������� �ɸ� �ð�
	// Floating Speed = ���� ������ �ӵ����� ���Ƿ� �����ϱ� ���� �߰�

	SetActorLocation(NewLocation);
	// SetActorLocation : ���͸� ���ϴ� ��ǥ ������ �̵���Ű�� ���� �Լ�;

}

