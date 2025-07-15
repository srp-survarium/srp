char __thiscall Scaleform::GFx::AS2ValueObjectInterface::GetDisplayInfo(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::GFx::Value::DisplayInfo *pinfo)
{
  Scaleform::GFx::AMP::ViewStats *v4; // eax
  Scaleform::GFx::InteractiveObject *v5; // eax
  Scaleform::GFx::TextField *v6; // edi
  Scaleform::AmpStats *v7; // esi
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 v9; // rax
  Scaleform::GFx::Value::DisplayInfo *v11; // esi
  long double v12; // st7
  bool (__thiscall *GetVisible)(Scaleform::GFx::DisplayObjectBase *); // eax
  bool v14; // al
  long double v15; // st7
  unsigned int RenderNode; // eax
  int v17; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v19; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v21; // [esp+10h] [ebp-110h] BYREF
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [esp+20h] [ebp-100h] BYREF
  long double YScale; // [esp+80h] [ebp-A0h]
  long double v24; // [esp+88h] [ebp-98h]
  long double XScale; // [esp+90h] [ebp-90h]
  long double v26; // [esp+98h] [ebp-88h]
  long double Rotation; // [esp+A0h] [ebp-80h]
  long double v28; // [esp+A8h] [ebp-78h]
  unsigned __int8 v29[48]; // [esp+B0h] [ebp-70h] BYREF
  unsigned __int8 src[64]; // [esp+E0h] [ebp-40h] BYREF

  v4 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v21,
    v4,
    "ObjectInterface::GetDisplayInfo",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetDisplayInfo);
  v5 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  v6 = (Scaleform::GFx::TextField *)v5;
  if ( v5 )
  {
    geomData.OrigMatrix.M[0][0] = 1.0;
    geomData.OrigMatrix.M[0][1] = 0.0;
    geomData.Y = 0;
    geomData.OrigMatrix.M[0][2] = 0.0;
    geomData.X = 0;
    geomData.OrigMatrix.M[0][3] = 0.0;
    geomData.OrigMatrix.M[1][0] = 0.0;
    geomData.OrigMatrix.M[1][2] = 0.0;
    geomData.OrigMatrix.M[1][3] = 0.0;
    geomData.OrigMatrix.M[1][1] = 1.0;
    geomData.Rotation = 0.0;
    geomData.YScale = 100.0;
    geomData.XScale = 100.0;
    geomData.ZScale = 100.0;
    geomData.YRotation = 0.0;
    geomData.XRotation = 0.0;
    geomData.Z = 0.0;
    Scaleform::GFx::DisplayObjectBase::GetGeomData(v5, &geomData);
    if ( v6->GetType(v6) == MouseWheel )
    {
      v11 = pinfo;
      Scaleform::GFx::TextField::GetPosition(v6, pinfo);
    }
    else
    {
      v26 = (double)geomData.X * 0.05;
      v24 = 0.05 * (double)geomData.Y;
      Rotation = geomData.Rotation;
      XScale = geomData.XScale;
      YScale = geomData.YScale;
      v12 = Scaleform::GFx::DisplayObjectBase::GetCxform(v6)->M[0][3] * 100.0;
      GetVisible = v6->GetVisible;
      v28 = v12;
      v14 = GetVisible(v6);
      v11 = pinfo;
      pinfo->X = v26;
      v15 = v24;
      pinfo->VarsSet |= 0x7FFu;
      pinfo->Y = v15;
      pinfo->Visible = v14;
      pinfo->Rotation = Rotation;
      pinfo->XScale = XScale;
      pinfo->YScale = YScale;
      pinfo->Alpha = v28;
      pinfo->Z = geomData.Z;
      pinfo->XRotation = geomData.XRotation;
      pinfo->YRotation = geomData.YRotation;
      pinfo->ZScale = geomData.ZScale;
    }
    v11->FOV = v6->GetFOV(v6);
    v11->VarsSet |= 0x800u;
    memset((int)src, 0, sizeof(src));
    *(float *)src = 1.0;
    *(float *)&src[20] = 1.0;
    *(float *)&src[40] = 1.0;
    *(float *)&src[60] = 1.0;
    if ( v6->GetProjectionMatrix3D(v6, (Scaleform::Render::Matrix4x4<float> *)src, 0) )
    {
      v11->VarsSet |= 0x1000u;
      memcpy((int)&v11->ProjectionMatrix3D, (const __m128i *)src, sizeof(v11->ProjectionMatrix3D));
    }
    memset((int)v29, 0, sizeof(v29));
    *(float *)v29 = 1.0;
    *(float *)&v29[20] = 1.0;
    *(float *)&v29[40] = 1.0;
    if ( v6->GetViewMatrix3D(v6, (Scaleform::Render::Matrix3x4<float> *)v29, 0) )
    {
      v11->VarsSet |= 0x2000u;
      memcpy((int)&v11->ViewMatrix3D, (const __m128i *)v29, sizeof(v11->ViewMatrix3D));
    }
    RenderNode = (unsigned int)Scaleform::GFx::DisplayObjectBase::GetRenderNode(v6);
    v17 = *(_WORD *)(*(_DWORD *)(*(_DWORD *)((RenderNode & 0xFFFFF000) + 0x10)
                               + 4 * ((int)(RenderNode - (RenderNode & 0xFFFFF000) - 28) / 28)
                               + 20)
                   + 6)
        & 0xC;
    v11->VarsSet |= 0x4000u;
    v11->EdgeAAMode = v17;
    Stats = v21.Stats;
    if ( v21.Stats )
    {
      v19 = v21.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v19->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v21.StartTicks),
        (ProfileTicks - v21.StartTicks) >> 32);
    }
    return 1;
  }
  else
  {
    v7 = v21.Stats;
    if ( v21.Stats )
    {
      v8 = v21.Stats->__vftable;
      v9 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
        v7,
        v9 - LODWORD(v21.StartTicks),
        (v9 - v21.StartTicks) >> 32);
    }
    return 0;
  }
}
