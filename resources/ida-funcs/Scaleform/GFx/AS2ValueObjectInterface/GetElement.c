char __thiscall Scaleform::GFx::AS2ValueObjectInterface::GetElement(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        unsigned int idx,
        Scaleform::GFx::Value *pval)
{
  Scaleform::GFx::AMP::ViewStats *v5; // eax
  char *v6; // esi
  Scaleform::AmpStats *v7; // esi
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 v9; // rax
  Scaleform::GFx::AS2::Value *v11; // ebx
  Scaleform::AmpStats *v12; // esi
  Scaleform::AmpStats_vtbl *v13; // edi
  unsigned __int64 v14; // rax
  Scaleform::GFx::AS2::MovieRoot *pObject; // esi
  int v16; // ecx
  Scaleform::GFx::AS2::Environment *v17; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v19; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v21; // [esp+Ch] [ebp-10h] BYREF

  v5 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v21,
    v5,
    "ObjectInterface::GetElement",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetElement);
  if ( pdata )
    v6 = pdata - 16;
  else
    v6 = 0;
  if ( (pval->Type & 0x40) != 0 )
  {
    ((void (__stdcall *)(Scaleform::GFx::Value *, int))pval->pObjectInterface->ObjectRelease)(pval, pval->mValue.IValue);
    pval->pObjectInterface = 0;
  }
  pval->Type = VT_Undefined;
  if ( idx < *((_DWORD *)v6 + 15) )
  {
    v11 = *(Scaleform::GFx::AS2::Value **)(*((_DWORD *)v6 + 14) + 4 * idx);
    if ( v11 )
    {
      pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
      v16 = (int)pObject->pMovieImpl->pMainMovie + 4 * pObject->pMovieImpl->pMainMovie->AvmObjOffset;
      v17 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v16 + 124))(v16);
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, v17, v11, pval);
      Stats = v21.Stats;
      if ( v21.Stats )
      {
        v19 = v21.Stats->__vftable;
        ProfileTicks = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v19->NativePopCallstack)(
          Stats,
          ProfileTicks - LODWORD(v21.StartTicks),
          (ProfileTicks - v21.StartTicks) >> 32);
      }
      return 1;
    }
    else
    {
      v12 = v21.Stats;
      if ( v21.Stats )
      {
        v13 = v21.Stats->__vftable;
        v14 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v13->NativePopCallstack)(
          v12,
          v14 - LODWORD(v21.StartTicks),
          (v14 - v21.StartTicks) >> 32);
      }
      return 0;
    }
  }
  else
  {
    v7 = v21.Stats;
    if ( v21.Stats )
    {
      v8 = v21.Stats->__vftable;
      v9 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
        v7,
        v9 - LODWORD(v21.StartTicks),
        (v9 - v21.StartTicks) >> 32);
    }
    return 0;
  }
}
