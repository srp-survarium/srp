char __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetDisplayInfo(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        Scaleform::GFx::Value::DisplayInfo *pinfo)
{
  Scaleform::GFx::AMP::ViewStats *v3; // eax
  int v4; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v6; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::TextField *v9; // edi
  Scaleform::AmpStats *v10; // esi
  Scaleform::AmpStats_vtbl *v11; // edi
  unsigned __int64 v12; // rax
  Scaleform::GFx::Value::DisplayInfo *v13; // esi
  long double v14; // st7
  bool (__thiscall *GetVisible)(Scaleform::GFx::DisplayObjectBase *); // eax
  bool v16; // al
  long double v17; // st7
  unsigned int RenderNode; // eax
  int v19; // eax
  Scaleform::AmpStats *v20; // esi
  Scaleform::AmpStats_vtbl *v21; // edi
  unsigned __int64 v22; // rax
  Scaleform::AmpFunctionTimer v23; // [esp+858h] [ebp-110h] BYREF
  long double YScale; // [esp+868h] [ebp-100h]
  long double v25; // [esp+870h] [ebp-F8h]
  long double v26; // [esp+878h] [ebp-F0h]
  long double XScale; // [esp+880h] [ebp-E8h]
  long double Rotation; // [esp+888h] [ebp-E0h]
  long double v29; // [esp+890h] [ebp-D8h]
  Scaleform::Render::Matrix3x4<float> pmat; // [esp+898h] [ebp-D0h] BYREF
  Scaleform::GFx::DisplayObjectBase::GeomDataType v31; // [esp+8C8h] [ebp-A0h] BYREF
  unsigned __int8 src[64]; // [esp+928h] [ebp-40h] BYREF

  v3 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v23,
    v3,
    "ObjectInterface::GetDisplayInfo",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetDisplayInfo);
  v4 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v4 + 60) - 17) >= 0xC || (*(_DWORD *)(v4 + 56) & 0x20) != 0 )
  {
    Stats = v23.Stats;
    if ( v23.Stats )
    {
      v6 = v23.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v6->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v23.StartTicks),
        (ProfileTicks - v23.StartTicks) >> 32);
    }
    return 0;
  }
  else
  {
    v9 = (Scaleform::GFx::TextField *)pdata[12];
    if ( v9 )
    {
      Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(&v31);
      Scaleform::GFx::DisplayObjectBase::GetGeomData(v9, &v31);
      if ( v9->GetType(v9) == MouseWheel )
      {
        v13 = pinfo;
        Scaleform::GFx::TextField::GetPosition(v9, pinfo);
      }
      else
      {
        v29 = (double)v31.X * 0.05;
        v26 = 0.05 * (double)v31.Y;
        Rotation = v31.Rotation;
        XScale = v31.XScale;
        YScale = v31.YScale;
        v14 = Scaleform::GFx::DisplayObjectBase::GetCxform(v9)->M[0][3] * 100.0;
        GetVisible = v9->GetVisible;
        v25 = v14;
        v16 = GetVisible(v9);
        v13 = pinfo;
        pinfo->X = v29;
        v17 = v26;
        pinfo->VarsSet |= 0x7FFu;
        pinfo->Y = v17;
        pinfo->Visible = v16;
        pinfo->Rotation = Rotation;
        pinfo->XScale = XScale;
        pinfo->YScale = YScale;
        pinfo->Alpha = v25;
        pinfo->Z = v31.Z * 0.05;
        pinfo->XRotation = v31.XRotation;
        pinfo->YRotation = v31.YRotation;
        pinfo->ZScale = v31.ZScale;
      }
      v13->FOV = v9->GetFOV(v9);
      v13->VarsSet |= 0x800u;
      memset((int)src, 0, sizeof(src));
      *(float *)src = 1.0;
      *(float *)&src[20] = 1.0;
      *(float *)&src[40] = 1.0;
      *(float *)&src[60] = 1.0;
      if ( v9->GetProjectionMatrix3D(v9, (Scaleform::Render::Matrix4x4<float> *)src, 0) )
      {
        v13->VarsSet |= 0x1000u;
        memcpy((int)&v13->ProjectionMatrix3D, (const __m128i *)src, sizeof(v13->ProjectionMatrix3D));
      }
      memset((int)&pmat, 0, sizeof(pmat));
      pmat.M[0][0] = 1.0;
      pmat.M[1][1] = 1.0;
      pmat.M[2][2] = 1.0;
      if ( v9->GetViewMatrix3D(v9, &pmat, 0) )
        Scaleform::GFx::Value::DisplayInfo::SetViewMatrix3D(v13, (const __m128i *)&pmat);
      RenderNode = (unsigned int)Scaleform::GFx::DisplayObjectBase::GetRenderNode(v9);
      v19 = *(_WORD *)(*(_DWORD *)(*(_DWORD *)((RenderNode & 0xFFFFF000) + 0x10)
                                 + 4 * ((int)(RenderNode - (RenderNode & 0xFFFFF000) - 28) / 28)
                                 + 20)
                     + 6)
          & 0xC;
      v13->VarsSet |= 0x4000u;
      v13->EdgeAAMode = v19;
      v20 = v23.Stats;
      if ( v23.Stats )
      {
        v21 = v23.Stats->__vftable;
        v22 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v21->NativePopCallstack)(
          v20,
          v22 - LODWORD(v23.StartTicks),
          (v22 - v23.StartTicks) >> 32);
      }
      return 1;
    }
    else
    {
      v10 = v23.Stats;
      if ( v23.Stats )
      {
        v11 = v23.Stats->__vftable;
        v12 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v11->NativePopCallstack)(
          v10,
          v12 - LODWORD(v23.StartTicks),
          (v12 - v23.StartTicks) >> 32);
      }
      return 0;
    }
  }
}
