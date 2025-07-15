char __thiscall Scaleform::GFx::AS2::Environment::FindOwnerOfMember(
        Scaleform::GFx::AS2::Environment *this,
        const Scaleform::GFx::ASString *varname,
        Scaleform::GFx::AS2::Value *presult,
        const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack)
{
  const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v6; // esi
  signed int i; // edi
  Scaleform::GFx::AS2::Object *pObject; // eax
  Scaleform::GFx::InteractiveObject **v9; // esi
  Scaleform::GFx::AS2::Object_vtbl **v10; // ecx
  int v11; // eax
  Scaleform::GFx::InteractiveObject *Target; // eax
  int v13; // eax
  Scaleform::GFx::InteractiveObject *v14; // ecx
  Scaleform::GFx::CharacterHandle *CharacterHandle; // esi
  Scaleform::GFx::AS2::Object *v16; // edi

  if ( !presult )
    return 0;
  v6 = pwithStack;
  if ( pwithStack )
  {
    for ( i = pwithStack->Data.Size - 1; i >= 0; --i )
    {
      pObject = v6->Data.Data[i].pObject;
      if ( (v6->Data.Data[i].BlockEndPc & 0x80000000) == 0 )
      {
        if ( !pObject )
          continue;
        v10 = &pObject->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable
            + BYTE1(pObject[1].RefCount);
        v11 = ((int (__thiscall *)(Scaleform::GFx::AS2::Object_vtbl **))(*v10)->Finalize_GC)(v10);
        if ( !v11 )
          continue;
        v9 = (Scaleform::GFx::InteractiveObject **)(v11 + 4);
      }
      else
      {
        if ( !pObject )
          continue;
        v9 = (Scaleform::GFx::InteractiveObject **)&pObject->Scaleform::GFx::AS2::ObjectInterface;
      }
      if ( v9
        && ((unsigned __int8 (__thiscall *)(Scaleform::GFx::InteractiveObject **, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, _DWORD))LODWORD((*v9)->LastHitTestX))(
             v9,
             &this->StringContext,
             varname,
             0) )
      {
        if ( (unsigned int)(((int (__thiscall *)(Scaleform::GFx::InteractiveObject **))(*v9)->pWeakProxy)(v9) - 2) > 3 )
        {
          Scaleform::GFx::AS2::Value::SetAsObject(presult, (Scaleform::GFx::AS2::Object *)(v9 - 4));
          return 1;
        }
        else
        {
          if ( (unsigned int)(((int (__thiscall *)(Scaleform::GFx::InteractiveObject **))(*v9)->pWeakProxy)(v9) - 2) > 3 )
            Scaleform::GFx::AS2::Value::SetAsCharacter(presult, 0);
          else
            Scaleform::GFx::AS2::Value::SetAsCharacter(presult, v9[3]);
          return 1;
        }
      }
      v6 = pwithStack;
    }
  }
  Target = this->Target;
  if ( !Target )
    return 0;
  v13 = (*(int (__thiscall **)(int))(*((_DWORD *)&Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                     + Target->AvmObjOffset)
                                   + 4))((int)Target + 4 * Target->AvmObjOffset);
  if ( !(*(unsigned __int8 (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, _DWORD))(*(_DWORD *)(v13 + 4) + 36))(
          v13 + 4,
          &this->StringContext,
          varname,
          0) )
  {
    v16 = this->StringContext.pContext->pGlobal.pObject;
    if ( v16 && v16->HasMember(&v16->Scaleform::GFx::AS2::ObjectInterface, &this->StringContext, varname, 0) )
    {
      Scaleform::GFx::AS2::Value::SetAsObject(presult, v16);
      return 1;
    }
    return 0;
  }
  v14 = this->Target;
  if ( v14 )
  {
    CharacterHandle = v14->pNameHandle.pObject;
    if ( !CharacterHandle )
      CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v14);
  }
  else
  {
    CharacterHandle = 0;
  }
  if ( presult->T.Type != 7 || presult->V.pCharHandle != CharacterHandle )
  {
    Scaleform::GFx::AS2::Value::DropRefs(presult);
    presult->T.Type = 7;
    presult->NV.Int32Value = (int)CharacterHandle;
    if ( CharacterHandle )
      ++CharacterHandle->RefCount;
  }
  return 1;
}
