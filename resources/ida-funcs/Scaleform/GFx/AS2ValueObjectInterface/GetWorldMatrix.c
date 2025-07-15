char __thiscall Scaleform::GFx::AS2ValueObjectInterface::GetWorldMatrix(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::Render::Matrix2x4<float> *pmat)
{
  Scaleform::GFx::AMP::ViewStats *v4; // eax
  Scaleform::GFx::InteractiveObject *v5; // eax
  Scaleform::AmpStats *v6; // esi
  Scaleform::AmpStats_vtbl *v7; // edi
  unsigned __int64 v8; // rax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v11; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v13; // [esp+10h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> pmata; // [esp+20h] [ebp-20h] BYREF

  v4 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v13,
    v4,
    "ObjectInterface::GetWorldMatrix",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetWorldMatrix);
  v5 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( v5 )
  {
    pmata.M[0][0] = 1.0;
    pmata.M[0][1] = 0.0;
    pmata.M[0][2] = 0.0;
    pmata.M[0][3] = 0.0;
    pmata.M[1][0] = 0.0;
    pmata.M[1][2] = 0.0;
    pmata.M[1][3] = 0.0;
    pmata.M[1][1] = 1.0;
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v5, &pmata);
    Stats = v13.Stats;
    pmata.M[0][3] = pmata.M[0][3] * 0.05000000074505806;
    pmata.M[1][3] = 0.05000000074505806 * pmata.M[1][3];
    *pmat = pmata;
    if ( Stats )
    {
      v11 = Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v11->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v13.StartTicks),
        (ProfileTicks - v13.StartTicks) >> 32);
    }
    return 1;
  }
  else
  {
    v6 = v13.Stats;
    if ( v13.Stats )
    {
      v7 = v13.Stats->__vftable;
      v8 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v7->NativePopCallstack)(
        v6,
        v8 - LODWORD(v13.StartTicks),
        (v8 - v13.StartTicks) >> 32);
    }
    return 0;
  }
}
