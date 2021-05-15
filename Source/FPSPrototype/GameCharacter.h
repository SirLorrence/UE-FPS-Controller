// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameCharacter.generated.h"

class UInputComponent;

UCLASS()
class FPSPROTOTYPE_API AGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGameCharacter();

	//Add Camera
	UPROPERTY(VisibleAnywhere, Category = Camera)
	class UCameraComponent* CameraComponent;

	//Add Capsule Component
	
	class UCapsuleComponent* Capsule;
	float playerRadius = 55.f;
	float playerHeight = 96.f;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	void MoveForward(float val);
	void MoveRight(float val);

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION()
	void SimpleAction();
	void ToggleCrouch();
};
