char __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetCxform(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        const Scaleform::Render::Cxform *cx)
{
  Scaleform::GFx::AMP::ViewStats *v3; // eax
  int v4; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v6; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::DisplayObjectBase *v9; // esi
  Scaleform::AmpStats *v10; // esi
  Scaleform::AmpStats_vtbl *v11; // edi
  unsigned __int64 v12; // rax
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetCxform; // [esp+8h] [ebp-10h] BYREF

  v3 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetCxform,
    v3,
    "ObjectInterface::SetCxform",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_SetCxform);
  v4 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v4 + 60) - 17) >= 0xC || (*(_DWORD *)(v4 + 56) & 0x20) != 0 )
  {
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetCxform.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetCxform.Stats )
    {
      v6 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetCxform.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v6->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetCxform.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetCxform.StartTicks) >> 32);
    }
    return 0;
  }
  else
  {
    v9 = (Scaleform::GFx::DisplayObjectBase *)pdata[12];
    Scaleform::GFx::DisplayObjectBase::SetCxform(v9, cx);
    v9->SetAcceptAnimMoves(v9, 0);
    v10 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetCxform.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetCxform.Stats )
    {
      v11 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetCxform.Stats->__vftable;
      v12 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v11->NativePopCallstack)(
        v10,
        v12 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetCxform.StartTicks),
        (v12 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetCxform.StartTicks) >> 32);
    }
    return 1;
  }
}
