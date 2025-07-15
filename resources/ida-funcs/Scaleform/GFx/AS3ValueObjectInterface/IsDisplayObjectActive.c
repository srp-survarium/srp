bool __thiscall Scaleform::GFx::AS3ValueObjectInterface::IsDisplayObjectActive(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata)
{
  Scaleform::GFx::AMP::ViewStats *v2; // eax
  int v3; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v5; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpStats *v8; // esi
  bool v9; // bl
  Scaleform::AmpStats_vtbl *v10; // edi
  unsigned __int64 v11; // rax
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsDisplayObjectActive; // [esp+8h] [ebp-10h] BYREF

  v2 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_IsDisplayObjectActive,
    v2,
    "ObjectInterface::IsDisplayObjectActive",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_IsDisplayObjectActive);
  v3 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v3 + 60) - 17) >= 0xC || (*(_DWORD *)(v3 + 56) & 0x20) != 0 )
  {
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsDisplayObjectActive.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsDisplayObjectActive.Stats )
    {
      v5 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsDisplayObjectActive.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v5->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_IsDisplayObjectActive.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsDisplayObjectActive.StartTicks) >> 32);
    }
    return 0;
  }
  else
  {
    v8 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsDisplayObjectActive.Stats;
    v9 = pdata[12] != 0;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsDisplayObjectActive.Stats )
    {
      v10 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsDisplayObjectActive.Stats->__vftable;
      v11 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v10->NativePopCallstack)(
        v8,
        v11 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_IsDisplayObjectActive.StartTicks),
        (v11 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_IsDisplayObjectActive.StartTicks) >> 32);
    }
    return v9;
  }
}
