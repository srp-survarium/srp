char __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetElement(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        unsigned int idx,
        Scaleform::GFx::Value *pval)
{
  Scaleform::GFx::AMP::ViewStats *v5; // eax
  Scaleform::AmpStats *v6; // esi
  Scaleform::AmpStats_vtbl *v7; // edi
  unsigned __int64 v8; // rax
  Scaleform::GFx::AS3::MovieRoot *pObject; // edi
  Scaleform::GFx::AS3::Value *v11; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v13; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetElement; // [esp+8h] [ebp-10h] BYREF

  v5 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetElement,
    v5,
    "ObjectInterface::GetElement",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetElement);
  if ( (pval->Type & 0x40) != 0 )
  {
    ((void (__stdcall *)(Scaleform::GFx::Value *, int))pval->pObjectInterface->ObjectRelease)(pval, pval->mValue.IValue);
    pval->pObjectInterface = 0;
  }
  pval->Type = VT_Undefined;
  if ( idx < *((_DWORD *)pdata + 8) )
  {
    pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
    v11 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(
                                          (Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 32),
                                          idx);
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, v11, (Scaleform::GFx::ASStringNode *)pval);
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetElement.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetElement.Stats )
    {
      v13 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetElement.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v13->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetElement.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetElement.StartTicks) >> 32);
    }
    return 1;
  }
  else
  {
    v6 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetElement.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetElement.Stats )
    {
      v7 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetElement.Stats->__vftable;
      v8 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v7->NativePopCallstack)(
        v6,
        v8 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetElement.StartTicks),
        (v8 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetElement.StartTicks) >> 32);
    }
    return 0;
  }
}
