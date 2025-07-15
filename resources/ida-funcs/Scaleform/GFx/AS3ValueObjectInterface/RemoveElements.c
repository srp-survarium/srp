char __thiscall Scaleform::GFx::AS3ValueObjectInterface::RemoveElements(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        unsigned int idx,
        int count)
{
  Scaleform::GFx::AMP::ViewStats *v4; // eax
  unsigned int v5; // eax
  Scaleform::AmpStats *v6; // esi
  Scaleform::AmpStats_vtbl *v7; // edi
  unsigned __int64 v8; // rax
  unsigned int v10; // edx
  unsigned int v11; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v13; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_RemoveElements; // [esp+8h] [ebp-10h] BYREF

  v4 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_RemoveElements,
    v4,
    "ObjectInterface::RemoveElements",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_RemoveElements);
  v5 = *((_DWORD *)pdata + 8);
  if ( idx < v5 )
  {
    v10 = count;
    if ( count < 0 )
      v10 = v5 - idx;
    v11 = v5 - idx;
    if ( v11 >= v10 )
      v11 = v10;
    Scaleform::GFx::AS3::Impl::SparseArray::CutMultipleAt(
      (Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 32),
      idx,
      v11,
      0);
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_RemoveElements.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_RemoveElements.Stats )
    {
      v13 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_RemoveElements.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v13->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_RemoveElements.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_RemoveElements.StartTicks) >> 32);
    }
    return 1;
  }
  else
  {
    v6 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_RemoveElements.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_RemoveElements.Stats )
    {
      v7 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_RemoveElements.Stats->__vftable;
      v8 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v7->NativePopCallstack)(
        v6,
        v8 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_RemoveElements.StartTicks),
        (v8 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_RemoveElements.StartTicks) >> 32);
    }
    return 0;
  }
}
