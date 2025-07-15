bool __thiscall Scaleform::GFx::AS2ValueObjectInterface::IsDisplayObjectActive(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata)
{
  Scaleform::GFx::AMP::ViewStats *v3; // eax
  Scaleform::GFx::InteractiveObject *v4; // eax
  Scaleform::AmpStats *Stats; // esi
  bool v6; // bl
  Scaleform::AmpStats_vtbl *v7; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v10; // [esp+8h] [ebp-10h] BYREF

  v3 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v10,
    v3,
    "ObjectInterface::IsDisplayObjectActive",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_IsDisplayObjectActive);
  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  Stats = v10.Stats;
  v6 = v4 != 0;
  if ( v10.Stats )
  {
    v7 = v10.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v7->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v10.StartTicks),
      (ProfileTicks - v10.StartTicks) >> 32);
  }
  return v6;
}
