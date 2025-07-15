char __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetMatrix3D(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        Scaleform::Render::Matrix3x4<float> *pmat)
{
  Scaleform::GFx::AMP::ViewStats *v3; // eax
  int v4; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v6; // edi
  unsigned __int64 ProfileTicks; // rax
  const __m128i *v9; // eax
  Scaleform::AmpStats *v10; // esi
  Scaleform::AmpStats_vtbl *v11; // edi
  unsigned __int64 v12; // rax
  Scaleform::AmpFunctionTimer v13; // [esp+80h] [ebp-40h] BYREF
  unsigned __int8 dst[48]; // [esp+90h] [ebp-30h] BYREF

  v3 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v13,
    v3,
    "ObjectInterface::GetMatrix3D",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetMatrix3D);
  v4 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v4 + 60) - 17) >= 0xC || (*(_DWORD *)(v4 + 56) & 0x20) != 0 )
  {
    Stats = v13.Stats;
    if ( v13.Stats )
    {
      v6 = v13.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v6->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v13.StartTicks),
        (ProfileTicks - v13.StartTicks) >> 32);
    }
    return 0;
  }
  else
  {
    v9 = (const __m128i *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)pdata[12] + 16))(pdata[12]);
    memcpy((int)dst, v9, sizeof(dst));
    *(float *)&dst[12] = *(float *)&dst[12] * 0.05000000074505806;
    *(float *)&dst[28] = *(float *)&dst[28] * 0.05000000074505806;
    *(float *)&dst[44] = 0.05000000074505806 * *(float *)&dst[44];
    memcpy((int)pmat, (const __m128i *)dst, sizeof(Scaleform::Render::Matrix3x4<float>));
    v10 = v13.Stats;
    if ( v13.Stats )
    {
      v11 = v13.Stats->__vftable;
      v12 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v11->NativePopCallstack)(
        v10,
        v12 - LODWORD(v13.StartTicks),
        (v12 - v13.StartTicks) >> 32);
    }
    return 1;
  }
}
