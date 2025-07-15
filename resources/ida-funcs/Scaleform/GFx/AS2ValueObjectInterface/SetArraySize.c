char __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetArraySize(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        int sz)
{
  Scaleform::GFx::AMP::ViewStats *v3; // eax
  Scaleform::GFx::AS2::ArrayObject *v4; // ecx
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v6; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v9; // [esp+0h] [ebp-10h] BYREF

  v3 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v9,
    v3,
    "ObjectInterface::SetArraySize",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_SetArraySize);
  if ( pdata )
    v4 = (Scaleform::GFx::AS2::ArrayObject *)(pdata - 16);
  else
    v4 = 0;
  Scaleform::GFx::AS2::ArrayObject::Resize(v4, sz);
  Stats = v9.Stats;
  if ( v9.Stats )
  {
    v6 = v9.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v6->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v9.StartTicks),
      (ProfileTicks - v9.StartTicks) >> 32);
  }
  return 1;
}
