// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAM415_LovettPickUpComponent.h"

UGAM415_LovettPickUpComponent::UGAM415_LovettPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UGAM415_LovettPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UGAM415_LovettPickUpComponent::OnSphereBeginOverlap);
}

void UGAM415_LovettPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AGAM415_LovettCharacter* Character = Cast<AGAM415_LovettCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
