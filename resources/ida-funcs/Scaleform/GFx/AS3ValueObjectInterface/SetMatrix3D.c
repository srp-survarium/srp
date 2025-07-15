char __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetMatrix3D(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        Scaleform::Render::Matrix3x4<float> *mat)
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
  Scaleform::AmpStats *v13; // esi
  Scaleform::AmpStats_vtbl *v14; // edi
  unsigned __int64 v15; // rax
  float eX; // [esp+2ECh] [ebp-ACh] BYREF
  Scaleform::AmpFunctionTimer v17; // [esp+2F0h] [ebp-A8h] BYREF
  float eY; // [esp+304h] [ebp-94h] BYREF
  unsigned __int8 dst[48]; // [esp+308h] [ebp-90h] BYREF
  Scaleform::GFx::DisplayObjectBase::GeomDataType gd; // [esp+338h] [ebp-60h] BYREF

  v3 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v17,
    v3,
    "ObjectInterface::SetMatrix3D",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_SetMatrix3D);
  v4 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v4 + 60) - 17) >= 0xC || (*(_DWORD *)(v4 + 56) & 0x20) != 0 )
  {
    Stats = v17.Stats;
    if ( v17.Stats )
    {
      v6 = v17.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v6->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v17.StartTicks),
        (ProfileTicks - v17.StartTicks) >> 32);
    }
    return 0;
  }
  else
  {
    v9 = (Scaleform::GFx::DisplayObjectBase *)pdata[12];
    if ( Scaleform::Render::Matrix3x4<float>::IsValid(mat) )
    {
      memcpy((int)dst, (const __m128i *)mat, sizeof(dst));
      *(float *)&dst[12] = *(float *)&dst[12] * 20.0;
      *(float *)&dst[28] = *(float *)&dst[28] * 20.0;
      *(float *)&dst[44] = 20.0 * *(float *)&dst[44];
      v9->SetMatrix3D(v9, (const Scaleform::Render::Matrix3x4<float> *)dst);
      Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(&gd);
      Scaleform::GFx::DisplayObjectBase::GetGeomData(v9, &gd);
      gd.Z = mat->M[2][3];
      eX = mat->M[1][2] * mat->M[1][2] + mat->M[0][2] * mat->M[0][2] + mat->M[2][2] * mat->M[2][2];
      eX = sqrt(eX);
      gd.ZScale = eX * 100.0;
      Scaleform::Render::Matrix3x4<float>::GetEulerAngles(mat, &eX, &eY, 0);
      gd.XRotation = eX * 180.0 / 3.141592653589793;
      gd.YRotation = 180.0 * eY / 3.141592653589793;
      Scaleform::GFx::DisplayObjectBase::SetGeomData(v9, &gd);
      v13 = v17.Stats;
      if ( v17.Stats )
      {
        v14 = v17.Stats->__vftable;
        v15 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v14->NativePopCallstack)(
          v13,
          v15 - LODWORD(v17.StartTicks),
          (v15 - v17.StartTicks) >> 32);
      }
      return 1;
    }
    else
    {
      v10 = v17.Stats;
      if ( v17.Stats )
      {
        v11 = v17.Stats->__vftable;
        v12 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v11->NativePopCallstack)(
          v10,
          v12 - LODWORD(v17.StartTicks),
          (v12 - v17.StartTicks) >> 32);
      }
      return 0;
    }
  }
}
