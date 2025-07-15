char __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetDisplayMatrix(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::GFx::AMP::ViewStats *v3; // eax
  int v4; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v6; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::DisplayObjectBase *v9; // edi
  Scaleform::AmpStats *v10; // esi
  Scaleform::AmpStats_vtbl *v11; // edi
  unsigned __int64 v12; // rax
  double v13; // st7
  int v14; // eax
  double v15; // st7
  double v16; // st6
  Scaleform::AmpStats *v17; // esi
  Scaleform::AmpStats_vtbl *v18; // edi
  unsigned __int64 v19; // rax
  Scaleform::AmpFunctionTimer v20; // [esp+180h] [ebp-90h] BYREF
  float v21[3]; // [esp+190h] [ebp-80h] BYREF
  float v22; // [esp+19Ch] [ebp-74h]
  float v23; // [esp+1A0h] [ebp-70h]
  float v24; // [esp+1A4h] [ebp-6Ch]
  float v25; // [esp+1A8h] [ebp-68h]
  float v26; // [esp+1ACh] [ebp-64h]
  Scaleform::GFx::DisplayObjectBase::GeomDataType gd; // [esp+1B0h] [ebp-60h] BYREF

  v3 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v20,
    v3,
    "ObjectInterface::SetDisplayMatrix",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_SetDisplayMatrix);
  v4 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v4 + 60) - 17) >= 0xC || (*(_DWORD *)(v4 + 56) & 0x20) != 0 )
  {
    Stats = v20.Stats;
    if ( v20.Stats )
    {
      v6 = v20.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v6->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v20.StartTicks),
        (ProfileTicks - v20.StartTicks) >> 32);
    }
    return 0;
  }
  else
  {
    v9 = (Scaleform::GFx::DisplayObjectBase *)pdata[12];
    if ( Scaleform::Render::Matrix2x4<float>::IsValid(mat) )
    {
      v21[0] = mat->M[0][0];
      v21[1] = mat->M[0][1];
      v21[2] = mat->M[0][2];
      v22 = mat->M[0][3];
      v23 = mat->M[1][0];
      v24 = mat->M[1][1];
      v25 = mat->M[1][2];
      v26 = mat->M[1][3];
      v22 = v22 * 20.0;
      v26 = 20.0 * v26;
      v9->SetMatrix(v9, (const Scaleform::Render::Matrix2x4<float> *)v21);
      Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(&gd);
      Scaleform::GFx::DisplayObjectBase::GetGeomData(v9, &gd);
      v13 = mat->M[1][3];
      gd.X = (int)mat->M[0][3];
      v14 = (int)v13;
      v15 = mat->M[1][0];
      v16 = mat->M[0][0];
      gd.Y = v14;
      gd.XScale = sqrt(v15 * v15 + v16 * v16) * 100.0;
      gd.YScale = sqrt(mat->M[1][1] * mat->M[1][1] + mat->M[0][1] * mat->M[0][1]) * 100.0;
      gd.Rotation = atan2(mat->M[1][0], mat->M[0][0]) * 180.0 / 3.141592653589793;
      Scaleform::GFx::DisplayObjectBase::SetGeomData(v9, &gd);
      v17 = v20.Stats;
      if ( v20.Stats )
      {
        v18 = v20.Stats->__vftable;
        v19 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v18->NativePopCallstack)(
          v17,
          v19 - LODWORD(v20.StartTicks),
          (v19 - v20.StartTicks) >> 32);
      }
      return 1;
    }
    else
    {
      v10 = v20.Stats;
      if ( v20.Stats )
      {
        v11 = v20.Stats->__vftable;
        v12 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v11->NativePopCallstack)(
          v10,
          v12 - LODWORD(v20.StartTicks),
          (v12 - v20.StartTicks) >> 32);
      }
      return 0;
    }
  }
}
