char __thiscall Scaleform::GFx::AS2ValueObjectInterface::GetDisplayMatrix(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::Render::Matrix2x4<float> *pmat)
{
  Scaleform::GFx::AMP::ViewStats *v4; // eax
  Scaleform::GFx::InteractiveObject *v5; // eax
  Scaleform::AmpStats *v6; // esi
  Scaleform::AmpStats_vtbl *v7; // edi
  unsigned __int64 v8; // rax
  float *v10; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v12; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v14; // [esp+10h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> v15; // [esp+20h] [ebp-20h]

  v4 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v14,
    v4,
    "ObjectInterface::GetDisplayMatrix",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetDisplayMatrix);
  v5 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( v5 )
  {
    v10 = (float *)v5->GetMatrix(v5);
    v15.M[0][0] = *v10;
    Stats = v14.Stats;
    v15.M[0][1] = v10[1];
    v15.M[0][2] = v10[2];
    v15.M[0][3] = v10[3];
    v15.M[1][0] = v10[4];
    v15.M[1][1] = v10[5];
    v15.M[1][2] = v10[6];
    v15.M[1][3] = v10[7];
    v15.M[0][3] = v15.M[0][3] * 0.05000000074505806;
    v15.M[1][3] = 0.05000000074505806 * v15.M[1][3];
    *pmat = v15;
    if ( Stats )
    {
      v12 = Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v12->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v14.StartTicks),
        (ProfileTicks - v14.StartTicks) >> 32);
    }
    return 1;
  }
  else
  {
    v6 = v14.Stats;
    if ( v14.Stats )
    {
      v7 = v14.Stats->__vftable;
      v8 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v7->NativePopCallstack)(
        v6,
        v8 - LODWORD(v14.StartTicks),
        (v8 - v14.StartTicks) >> 32);
    }
    return 0;
  }
}
