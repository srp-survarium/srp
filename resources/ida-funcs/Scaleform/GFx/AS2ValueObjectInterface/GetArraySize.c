int __thiscall Scaleform::GFx::AS2ValueObjectInterface::GetArraySize(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata)
{
  Scaleform::GFx::AMP::ViewStats *v2; // eax
  char *v3; // eax
  Scaleform::AmpStats *Stats; // esi
  int v5; // edi
  Scaleform::AmpStats_vtbl *v6; // ebx
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v9; // [esp+0h] [ebp-10h] BYREF

  v2 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v9,
    v2,
    "ObjectInterface::GetArraySize",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetArraySize);
  if ( pdata )
    v3 = pdata - 16;
  else
    v3 = 0;
  Stats = v9.Stats;
  v5 = *((_DWORD *)v3 + 15);
  if ( v9.Stats )
  {
    v6 = v9.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v6->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v9.StartTicks),
      (ProfileTicks - v9.StartTicks) >> 32);
  }
  return v5;
}
