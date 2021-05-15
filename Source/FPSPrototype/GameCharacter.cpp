// Fill out your copyright notice in the Description page of Project Settings.


#include "GameCharacter.h"

// Sets default values
AGameCharacter::AGameCharacter() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = GetCapsuleComponent();
	Capsule->InitCapsuleSize(playerRadius, playerHeight);
	SetRootComponent(Capsule);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("First Person Camera");
	CameraComponent->SetupAttachment(Capsule);
	CameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f));
	CameraComponent->bUsePawnControlRotation = true;

	bIsCrouched = false;
}

// Called when the game starts or when spawned
void AGameCharacter::BeginPlay() {
	Super::BeginPlay();

}

void AGameCharacter::MoveForward(float val) {
	if (val != 0) AddMovementInput(GetActorForwardVector(), val);
}

void AGameCharacter::MoveRight(float val) {
	if (val != 0) AddMovementInput(GetActorRightVector(), val);
}

void AGameCharacter::SimpleAction() {
	UE_LOG(LogTemp, Warning, TEXT("Press"));
}

void AGameCharacter::ToggleCrouch() {
	if (bIsCrouched) {
		Capsule->SetCapsuleHalfHeight(playerHeight);
		AGameCharacter::UnCrouch();
	}
	else {
		Capsule->SetCapsuleHalfHeight(75.f);
		AGameCharacter::Crouch();
	}
}


void AGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	//if its valid, if not it will stop being executed 
	check(PlayerInputComponent);

	//interaction press
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AGameCharacter::SimpleAction);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AGameCharacter::Jump);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AGameCharacter::ToggleCrouch);


	//Movement
	PlayerInputComponent->BindAxis("Forward", this, &AGameCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &AGameCharacter::MoveRight);

	//mouse
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}

// Called every frame
void AGameCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}
