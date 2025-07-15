char __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetDisplayMatrix(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        Scaleform::Render::Matrix2x4<float> *pmat)
{
  Scaleform::GFx::AMP::ViewStats *v3; // eax
  int v4; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v6; // edi
  unsigned __int64 ProfileTicks; // rax
  float *v9; // eax
  Scaleform::AmpStats *v10; // esi
  Scaleform::AmpStats_vtbl *v11; // edi
  unsigned __int64 v12; // rax
  Scaleform::AmpFunctionTimer v13; // [esp+60h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> v14; // [esp+70h] [ebp-20h]

  v3 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v13,
    v3,
    "ObjectInterface::GetDisplayMatrix",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetDisplayMatrix);
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
    v9 = (float *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)pdata[12] + 8))(pdata[12]);
    v14.M[0][0] = *v9;
    v10 = v13.Stats;
    v14.M[0][1] = v9[1];
    v14.M[0][2] = v9[2];
    v14.M[0][3] = v9[3];
    v14.M[1][0] = v9[4];
    v14.M[1][1] = v9[5];
    v14.M[1][2] = v9[6];
    v14.M[1][3] = v9[7];
    v14.M[0][3] = v14.M[0][3] * 0.05000000074505806;
    v14.M[1][3] = 0.05000000074505806 * v14.M[1][3];
    *pmat = v14;
    if ( v10 )
    {
      v11 = v10->__vftable;
      v12 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v11->NativePopCallstack)(
        v10,
        v12 - LODWORD(v13.StartTicks),
        (v12 - v13.StartTicks) >> 32);
    }
    return 1;
  }
}
