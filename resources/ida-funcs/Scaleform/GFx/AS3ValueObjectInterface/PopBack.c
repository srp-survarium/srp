char __thiscall Scaleform::GFx::AS3ValueObjectInterface::PopBack(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        Scaleform::GFx::Value *pval)
{
  Scaleform::GFx::AMP::ViewStats *v4; // eax
  int v5; // edi
  Scaleform::GFx::AS3::MovieRoot *pObject; // ebx
  Scaleform::AmpStats *v7; // esi
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 v9; // rax
  Scaleform::GFx::AS3::Value *v11; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v13; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_PopBack; // [esp+Ch] [ebp-10h] BYREF

  v4 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_PopBack,
    v4,
    "ObjectInterface::PopBack",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_PopBack);
  v5 = *((_DWORD *)pdata + 8);
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  if ( v5 > 0 )
  {
    if ( pval )
    {
      v11 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(
                                            (Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 32),
                                            v5 - 1);
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, v11, (Scaleform::GFx::ASStringNode *)pval);
    }
    Scaleform::GFx::AS3::Impl::SparseArray::Resize((Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 32), v5 - 1);
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_PopBack.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_PopBack.Stats )
    {
      v13 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_PopBack.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v13->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_PopBack.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_PopBack.StartTicks) >> 32);
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
    v7 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_PopBack.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_PopBack.Stats )
    {
      v8 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_PopBack.Stats->__vftable;
      v9 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
        v7,
        v9 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_PopBack.StartTicks),
        (v9 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_PopBack.StartTicks) >> 32);
    }
    return 0;
  }
}
