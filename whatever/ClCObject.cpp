#pragma once
#include "ClCObject.h"
#include "Functions.h"



FunctionsGame func;
bool CObject::IsAlive() {
	return func.IsAlive(this) && this->GetHealth() > 0.0f;
}

bool CObject::IsMinion() {
	return func.IsMinion(this);
}

bool CObject::IsTurret() {
	return func.IsTurret(this);
}



bool CObject::IsMissile() {
	return func.IsMissile(this);
}

bool CObject::IsTargetable() {
	return func.IsTargetable(this);
}

bool CObject::IsNexus() {
	return func.IsNexus(this);
}

bool CObject::IsInhibitor() {
	return func.IsInhibitor(this);
}

bool CObject::IsTroyEnt() {
	return func.IsTroyEnt(this);
}