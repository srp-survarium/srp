char __thiscall Scaleform::GFx::AS2ValueObjectInterface::PopBack(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        Scaleform::GFx::Value *pval)
{
  Scaleform::GFx::AMP::ViewStats *v4; // eax
  Scaleform::GFx::AS2::ArrayObject *v5; // esi
  Scaleform::GFx::AS2::MovieRoot *pObject; // edi
  int v7; // ecx
  Scaleform::GFx::AS2::Environment *v8; // eax
  int Size; // ecx
  Scaleform::AmpStats *v10; // esi
  Scaleform::AmpStats_vtbl *v11; // edi
  unsigned __int64 v12; // rax
  unsigned int v14; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v16; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v18; // [esp+8h] [ebp-10h] BYREF

  v4 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v18,
    v4,
    "ObjectInterface::PopBack",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_PopBack);
  if ( pdata )
    v5 = (Scaleform::GFx::AS2::ArrayObject *)(pdata - 16);
  else
    v5 = 0;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v7 = (int)pObject->pMovieImpl->pMainMovie + 4 * pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  v8 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 124))(v7);
  Size = v5->Elements.Data.Size;
  if ( Size > 0 )
  {
    if ( pval )
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, v8, v5->Elements.Data.Data[Size - 1], pval);
    v14 = v5->Elements.Data.Size;
    if ( v14 )
      Scaleform::GFx::AS2::ArrayObject::Resize(v5, v14 - 1);
    Stats = v18.Stats;
    if ( v18.Stats )
    {
      v16 = v18.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v16->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v18.StartTicks),
        (ProfileTicks - v18.StartTicks) >> 32);
    }
    return 1;
  }
  else
  {
    if ( pval )
    {
      if ( (pval->Type & 0x40) != 0 )
      {
        ((void (__stdcall *)(Scaleform::GFx::Value *, int))pval->pObjectInterface->ObjectRelease)(
          pval,
          pval->mValue.IValue);
        pval->pObjectInterface = 0;
      }
      pval->Type = VT_Undefined;
    }
    v10 = v18.Stats;
    if ( v18.Stats )
    {
      v11 = v18.Stats->__vftable;
      v12 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v11->NativePopCallstack)(
        v10,
        v12 - LODWORD(v18.StartTicks),
        (v12 - v18.StartTicks) >> 32);
    }
    return 0;
  }
}
