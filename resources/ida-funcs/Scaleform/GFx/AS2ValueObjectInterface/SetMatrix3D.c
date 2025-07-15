char __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetMatrix3D(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        __m128i *mat)
{
  Scaleform::GFx::AMP::ViewStats *v4; // eax
  Scaleform::GFx::InteractiveObject *v5; // edi
  Scaleform::AmpStats *v6; // esi
  Scaleform::AmpStats_vtbl *v7; // edi
  unsigned __int64 v8; // rax
  Scaleform::AmpStats *v10; // esi
  Scaleform::AmpStats_vtbl *v11; // edi
  unsigned __int64 v12; // rax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v14; // edi
  unsigned __int64 ProfileTicks; // rax
  float eX; // [esp+14h] [ebp-ACh] BYREF
  Scaleform::AmpFunctionTimer v17; // [esp+18h] [ebp-A8h] BYREF
  float eY; // [esp+2Ch] [ebp-94h] BYREF
  unsigned __int8 dst[48]; // [esp+30h] [ebp-90h] BYREF
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [esp+60h] [ebp-60h] BYREF

  v4 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v17,
    v4,
    "ObjectInterface::SetMatrix3D",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_SetMatrix3D);
  v5 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( v5 )
  {
    if ( Scaleform::Render::Matrix3x4<float>::IsValid((Scaleform::Render::Matrix3x4<float> *)mat) )
    {
      memcpy((int)dst, mat, sizeof(dst));
      *(float *)&dst[12] = *(float *)&dst[12] * 20.0;
      *(float *)&dst[28] = 20.0 * *(float *)&dst[28];
      v5->SetMatrix3D(v5, (const Scaleform::Render::Matrix3x4<float> *)dst);
      Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(&geomData);
      Scaleform::GFx::DisplayObjectBase::GetGeomData(v5, &geomData);
      geomData.Z = *(float *)&mat[2].m128i_i32[3];
      eX = *(float *)&mat[1].m128i_i32[2] * *(float *)&mat[1].m128i_i32[2]
         + *(float *)&mat->m128i_i32[2] * *(float *)&mat->m128i_i32[2]
         + *(float *)&mat[2].m128i_i32[2] * *(float *)&mat[2].m128i_i32[2];
      eX = sqrt(eX);
      geomData.ZScale = eX * 100.0;
      Scaleform::Render::Matrix3x4<float>::GetEulerAngles((Scaleform::Render::Matrix3x4<float> *)mat, &eX, &eY, 0);
      geomData.XRotation = eX * 180.0 / 3.141592653589793;
      geomData.YRotation = 180.0 * eY / 3.141592653589793;
      Scaleform::GFx::DisplayObjectBase::SetGeomData(v5, &geomData);
      Stats = v17.Stats;
      if ( v17.Stats )
      {
        v14 = v17.Stats->__vftable;
        ProfileTicks = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v14->NativePopCallstack)(
          Stats,
          ProfileTicks - LODWORD(v17.StartTicks),
          (ProfileTicks - v17.StartTicks) >> 32);
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
  else
  {
    v6 = v17.Stats;
    if ( v17.Stats )
    {
      v7 = v17.Stats->__vftable;
      v8 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v7->NativePopCallstack)(
        v6,
        v8 - LODWORD(v17.StartTicks),
        (v8 - v17.StartTicks) >> 32);
    }
    return 0;
  }
}
