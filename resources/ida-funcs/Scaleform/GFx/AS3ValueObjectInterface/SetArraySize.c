char __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetArraySize(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        unsigned int sz)
{
  Scaleform::GFx::AMP::ViewStats *v3; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v5; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetArraySize; // [esp+4h] [ebp-10h] BYREF

  v3 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetArraySize,
    v3,
    "ObjectInterface::SetArraySize",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_SetArraySize);
  Scaleform::GFx::AS3::Impl::SparseArray::Resize((Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 32), sz);
  Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetArraySize.Stats;
  if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetArraySize.Stats )
  {
    v5 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetArraySize.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v5->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetArraySize.StartTicks),
      (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetArraySize.StartTicks) >> 32);
  }
  return 1;
}
