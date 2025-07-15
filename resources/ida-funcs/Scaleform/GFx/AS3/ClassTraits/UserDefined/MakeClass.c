Scaleform::Pickable<Scaleform::GFx::AS3::Classes::UserDefined> *__thiscall Scaleform::GFx::AS3::ClassTraits::UserDefined::MakeClass(
        Scaleform::GFx::AS3::ClassTraits::UserDefined *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Classes::UserDefined> *result)
{
  Scaleform::GFx::AS3::Classes::UserDefined *v3; // eax
  Scaleform::GFx::AS3::Classes::UserDefined *v4; // eax
  Scaleform::GFx::AS3::Classes::UserDefined *v5; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edi
  Scaleform::GFx::AS3::Classes::UserDefined *v7; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::VM *pVM; // ecx
  unsigned int ScopeStackBaseInd; // eax
  const Scaleform::GFx::AS3::Value *v11; // eax
  Scaleform::GFx::AS3::Value v13; // [esp+10h] [ebp-10h] BYREF

  v3 = (Scaleform::GFx::AS3::Classes::UserDefined *)Scaleform::GFx::AS3::Traits::Alloc(this);
  if ( v3 )
  {
    Scaleform::GFx::AS3::Classes::UserDefined::UserDefined(v3, this);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  pObject = this->ITraits.pObject;
  result->pV = v5;
  if ( v5 )
    v5->RefCount = (v5->RefCount + 1) & 0x8FBFFFFF;
  v7 = (Scaleform::GFx::AS3::Classes::UserDefined *)pObject->pConstructor.pObject;
  if ( v5 != v7 )
  {
    if ( v7 )
    {
      if ( ((unsigned __int8)v7 & 1) != 0 )
      {
        pObject->pConstructor.pObject = (Scaleform::GFx::AS3::Classes::UserDefined *)((char *)v7 - 1);
      }
      else
      {
        RefCount = v7->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v7->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
      }
    }
    pObject->pConstructor.pObject = v5;
  }
  pVM = this->pVM;
  if ( pVM->CallStack.Size )
    ScopeStackBaseInd = pVM->CallStack.Pages[(pVM->CallStack.Size - 1) >> 6][(pVM->CallStack.Size - 1) & 0x3F].ScopeStackBaseInd;
  else
    ScopeStackBaseInd = 0;
  Scaleform::GFx::AS3::Traits::StoreScopeStack(pObject, ScopeStackBaseInd, &pVM->ScopeStack);
  Scaleform::GFx::AS3::Value::Value(&v13, result->pV);
  Scaleform::GFx::AS3::Traits::Add2StoredScopeStack(pObject, v11);
  if ( (v13.Flags & 0x1F) > 9 )
  {
    if ( (v13.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v13);
      Scaleform::GFx::AS3::Classes::UserDefined::CallStaticConstructor(result->pV);
      return result;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v13);
  }
  Scaleform::GFx::AS3::Classes::UserDefined::CallStaticConstructor(result->pV);
  return result;
}
