char __userpurge Scaleform::GFx::AS2::Environment::FindAndGetVariableRaw@<al>(
        Scaleform::GFx::AS2::Environment *this@<ecx>,
        int a2@<ebp>,
        Scaleform::GFx::AS2::Object *params)
{
  Scaleform::GFx::AS2::Value *pRCC; // ecx
  const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *RootIndex; // edx
  Scaleform::GFx::InteractiveObject **RefCount; // eax
  unsigned int pUserDataHolder; // edx
  char Variable; // bl
  Scaleform::GFx::AS2::Value *v9; // ecx
  int v11; // [esp+0h] [ebp-30h]
  int v12; // [esp+4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Value owner; // [esp+8h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::Environment::GetVarParams v14; // [esp+18h] [ebp-18h] BYREF

  if ( (*((_DWORD *)params->ExecuteForEachChild_GC + 4) & 0x2000000) != 0
    || !Scaleform::GFx::AS2::Environment::IsPath((const Scaleform::GFx::ASString *)params->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable) )
  {
    return Scaleform::GFx::AS2::Environment::GetVariableRaw(this, a2, (int)this, params, v11, v12);
  }
  pRCC = (Scaleform::GFx::AS2::Value *)params->pRCC;
  RootIndex = (const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *)params->RootIndex;
  v14.VarName = (const Scaleform::GFx::ASString *)params->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
  RefCount = (Scaleform::GFx::InteractiveObject **)params->RefCount;
  v14.pResult = pRCC;
  v14.ppNewTarget = RefCount;
  v14.pWithStack = RootIndex;
  pUserDataHolder = (unsigned int)params->pUserDataHolder;
  v14.pOwner = &owner;
  owner.T.Type = 0;
  v14.ExcludeFlags = pUserDataHolder;
  Variable = Scaleform::GFx::AS2::Environment::FindVariable(this, a2, (int)params, &v14, 0, 0);
  if ( owner.T.Type && owner.T.Type != 10 )
  {
    v9 = (Scaleform::GFx::AS2::Value *)params->Scaleform::GFx::AS2::ObjectInterface::__vftable;
    if ( v9 )
      Scaleform::GFx::AS2::Value::operator=(v9, &owner);
  }
  else
  {
    if ( ((int)params->pUserDataHolder & 4) == 0 )
      Scaleform::GFx::AS2::Environment::LogScriptError(
        this,
        " GetVariable failed: can't resolve the path \"%s\"",
        *(_DWORD *)params->ExecuteForEachChild_GC);
    Variable = 0;
  }
  if ( owner.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&owner);
  return Variable;
}
