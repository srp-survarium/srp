int __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetArraySize(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata)
{
  Scaleform::GFx::AMP::ViewStats *v2; // eax
  Scaleform::AmpStats *Stats; // esi
  int v4; // edi
  Scaleform::AmpStats_vtbl *v5; // ebx
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetArraySize; // [esp+8h] [ebp-10h] BYREF

  v2 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetArraySize,
    v2,
    "ObjectInterface::GetArraySize",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetArraySize);
  Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetArraySize.Stats;
  v4 = pdata[8];
  if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetArraySize.Stats )
  {
    v5 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetArraySize.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v5->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetArraySize.StartTicks),
      (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetArraySize.StartTicks) >> 32);
  }
  return v4;
}
