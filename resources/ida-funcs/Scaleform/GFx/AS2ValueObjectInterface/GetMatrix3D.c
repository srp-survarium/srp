char __thiscall Scaleform::GFx::AS2ValueObjectInterface::GetMatrix3D(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::Render::Matrix3x4<float> *pmat)
{
  Scaleform::GFx::AMP::ViewStats *v4; // eax
  Scaleform::GFx::InteractiveObject *v5; // eax
  Scaleform::AmpStats *v6; // esi
  Scaleform::AmpStats_vtbl *v7; // edi
  unsigned __int64 v8; // rax
  const __m128i *v10; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v12; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v14; // [esp+10h] [ebp-40h] BYREF
  unsigned __int8 dst[48]; // [esp+20h] [ebp-30h] BYREF

  v4 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v14,
    v4,
    "ObjectInterface::GetMatrix3D",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetMatrix3D);
  v5 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( v5 )
  {
    v10 = (const __m128i *)v5->GetMatrix3D(v5);
    memcpy((int)dst, v10, sizeof(dst));
    *(float *)&dst[12] = *(float *)&dst[12] * 0.05000000074505806;
    *(float *)&dst[28] = 0.05000000074505806 * *(float *)&dst[28];
    memcpy((int)pmat, (const __m128i *)dst, sizeof(Scaleform::Render::Matrix3x4<float>));
    Stats = v14.Stats;
    if ( v14.Stats )
    {
      v12 = v14.Stats->__vftable;
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
