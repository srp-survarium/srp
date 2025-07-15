char __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetCxform(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        void *pdata,
        Scaleform::Render::Cxform *pcx)
{
  Scaleform::GFx::AMP::ViewStats *v3; // eax
  int v4; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v6; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpStats *v9; // esi
  Scaleform::AmpStats_vtbl *v10; // edi
  unsigned __int64 v11; // rax
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetCxform; // [esp+8h] [ebp-10h] BYREF

  v3 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetCxform,
    v3,
    "ObjectInterface::GetCxform",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetCxform);
  v4 = *((_DWORD *)pdata + 5);
  if ( (unsigned int)(*(_DWORD *)(v4 + 60) - 17) >= 0xC || (*(_DWORD *)(v4 + 56) & 0x20) != 0 )
  {
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetCxform.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetCxform.Stats )
    {
      v6 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetCxform.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v6->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetCxform.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetCxform.StartTicks) >> 32);
    }
    return 0;
  }
  else
  {
    qmemcpy(
      pcx,
      Scaleform::GFx::DisplayObjectBase::GetCxform(*((Scaleform::GFx::DisplayObjectBase **)pdata + 12)),
      sizeof(Scaleform::Render::Cxform));
    v9 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetCxform.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetCxform.Stats )
    {
      v10 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetCxform.Stats->__vftable;
      v11 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v10->NativePopCallstack)(
        v9,
        v11 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetCxform.StartTicks),
        (v11 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetCxform.StartTicks) >> 32);
    }
    return 1;
  }
}
