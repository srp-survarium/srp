char __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetDisplayMatrix(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::GFx::AMP::ViewStats *v4; // eax
  Scaleform::GFx::InteractiveObject *v5; // edi
  Scaleform::AmpStats *v6; // esi
  Scaleform::AmpStats_vtbl *v7; // edi
  unsigned __int64 v8; // rax
  Scaleform::AmpStats *v10; // esi
  Scaleform::AmpStats_vtbl *v11; // edi
  unsigned __int64 v12; // rax
  double v13; // st7
  int v14; // eax
  double v15; // st7
  double v16; // st6
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v18; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v20; // [esp+10h] [ebp-90h] BYREF
  float v21[3]; // [esp+20h] [ebp-80h] BYREF
  float v22; // [esp+2Ch] [ebp-74h]
  float v23; // [esp+30h] [ebp-70h]
  float v24; // [esp+34h] [ebp-6Ch]
  float v25; // [esp+38h] [ebp-68h]
  float v26; // [esp+3Ch] [ebp-64h]
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [esp+40h] [ebp-60h] BYREF

  v4 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v20,
    v4,
    "ObjectInterface::SetDisplayMatrix",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_SetDisplayMatrix);
  v5 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( v5 )
  {
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
      v5->SetMatrix(v5, (const Scaleform::Render::Matrix2x4<float> *)v21);
      Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(&geomData);
      Scaleform::GFx::DisplayObjectBase::GetGeomData(v5, &geomData);
      v13 = mat->M[1][3];
      geomData.X = (int)mat->M[0][3];
      v14 = (int)v13;
      v15 = mat->M[1][0];
      v16 = mat->M[0][0];
      geomData.Y = v14;
      geomData.XScale = sqrt(v15 * v15 + v16 * v16) * 100.0;
      geomData.YScale = sqrt(mat->M[1][1] * mat->M[1][1] + mat->M[0][1] * mat->M[0][1]) * 100.0;
      geomData.Rotation = atan2(mat->M[1][0], mat->M[0][0]) * 180.0 / 3.141592653589793;
      Scaleform::GFx::DisplayObjectBase::SetGeomData(v5, &geomData);
      Stats = v20.Stats;
      if ( v20.Stats )
      {
        v18 = v20.Stats->__vftable;
        ProfileTicks = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v18->NativePopCallstack)(
          Stats,
          ProfileTicks - LODWORD(v20.StartTicks),
          (ProfileTicks - v20.StartTicks) >> 32);
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
  else
  {
    v6 = v20.Stats;
    if ( v20.Stats )
    {
      v7 = v20.Stats->__vftable;
      v8 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v7->NativePopCallstack)(
        v6,
        v8 - LODWORD(v20.StartTicks),
        (v8 - v20.StartTicks) >> 32);
    }
    return 0;
  }
}
