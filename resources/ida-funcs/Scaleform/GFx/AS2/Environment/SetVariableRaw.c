void __thiscall Scaleform::GFx::AS2::Environment::SetVariableRaw(
        Scaleform::GFx::AS2::Environment *this,
        const Scaleform::GFx::ASString *varname,
        const Scaleform::GFx::AS2::Value *val,
        const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack)
{
  const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v4; // eax
  signed int v6; // edi
  const Scaleform::GFx::ASString *v7; // esi
  Scaleform::GFx::AS2::Value *Local; // eax
  Scaleform::GFx::AS2::WithStackEntry *Data; // eax
  int BlockEndPc; // ecx
  Scaleform::GFx::AS2::Object *pObject; // eax
  int v12; // esi
  int v13; // ecx
  int v14; // eax
  void (__thiscall *v15)(int, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> **); // edx
  Scaleform::GFx::InteractiveObject *Target; // eax
  int v17; // eax
  Scaleform::GFx::InteractiveObject_vtbl **v18; // ecx
  Scaleform::GFx::AS2::Value dummy; // [esp+10h] [ebp-10h] BYREF

  v4 = pwithStack;
  if ( !pwithStack || (v6 = pwithStack->Data.Size - 1, v6 < 0) )
  {
LABEL_3:
    v7 = varname;
    Local = (Scaleform::GFx::AS2::Value *)Scaleform::GFx::AS2::Environment::FindLocal(this, varname);
    if ( Local )
    {
      Scaleform::GFx::AS2::Value::operator=(Local, val);
    }
    else
    {
      Target = this->Target;
      if ( Target )
      {
        v18 = &Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
            + Target->AvmObjOffset;
        v17 = ((int (__thiscall *)(Scaleform::GFx::InteractiveObject_vtbl **))(*v18)->CreateRenderNode)(v18);
      }
      else
      {
        v17 = 0;
      }
      LOBYTE(varname) = 0;
      (*(void (__thiscall **)(int, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::ASString **))(*(_DWORD *)(v17 + 4) + 12))(
        v17 + 4,
        this,
        v7,
        val,
        &varname);
    }
    return;
  }
  while ( 1 )
  {
    Data = v4->Data.Data;
    BlockEndPc = Data[v6].BlockEndPc;
    pObject = Data[v6].pObject;
    if ( BlockEndPc >= 0 )
    {
      if ( pObject )
      {
        v13 = (int)pObject + 4 * BYTE1(pObject[1].RefCount);
        v14 = (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 4))(v13);
        if ( v14 )
        {
          v12 = v14 + 4;
          goto LABEL_13;
        }
      }
    }
    else if ( pObject )
    {
      v12 = (int)&pObject->Scaleform::GFx::AS2::ObjectInterface;
      goto LABEL_13;
    }
    v12 = 0;
LABEL_13:
    dummy.T.Type = 0;
    if ( !v12 )
      goto LABEL_17;
    if ( (*(unsigned __int8 (__thiscall **)(int, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_DWORD *)v12 + 16))(
           v12,
           this,
           varname,
           &dummy) )
    {
      break;
    }
    if ( dummy.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&dummy);
LABEL_17:
    if ( --v6 < 0 )
      goto LABEL_3;
    v4 = pwithStack;
  }
  v15 = *(void (__thiscall **)(int, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> **))(*(_DWORD *)v12 + 12);
  LOBYTE(pwithStack) = 0;
  v15(v12, this, varname, val, &pwithStack);
  if ( dummy.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&dummy);
}
