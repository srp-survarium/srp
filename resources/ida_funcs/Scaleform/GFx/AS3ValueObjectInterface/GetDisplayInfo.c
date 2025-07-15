char __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetDisplayInfo(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        Scaleform::GFx::Value::DisplayInfo *pinfo)
{
  int v3; // eax
  Scaleform::GFx::TextField *v5; // edi
  Scaleform::GFx::Value::DisplayInfo *v6; // esi
  bool v7; // al
  unsigned int RenderNode; // eax
  int v9; // eax
  long double YScale; // [esp+748h] [ebp-100h]
  long double v11; // [esp+750h] [ebp-F8h]
  long double v12; // [esp+758h] [ebp-F0h]
  long double Rotation; // [esp+760h] [ebp-E8h]
  long double v14; // [esp+768h] [ebp-E0h]
  long double XScale; // [esp+770h] [ebp-D8h]
  Scaleform::Render::Matrix3x4<float> pmat; // [esp+778h] [ebp-D0h] BYREF
  Scaleform::GFx::DisplayObjectBase::GeomDataType v17; // [esp+7A8h] [ebp-A0h] BYREF
  unsigned __int8 dst[64]; // [esp+808h] [ebp-40h] BYREF

  v3 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v3 + 60) - 17) >= 0xC )
    return 0;
  if ( (*(_DWORD *)(v3 + 56) & 0x20) != 0 )
    return 0;
  v5 = (Scaleform::GFx::TextField *)pdata[12];
  if ( !v5 )
    return 0;
  Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(&v17);
  Scaleform::GFx::DisplayObjectBase::GetGeomData(v5, &v17);
  if ( v5->GetType(v5) == MouseWheel )
  {
    v6 = pinfo;
    Scaleform::GFx::TextField::GetPosition(v5, pinfo);
  }
  else
  {
    v11 = (double)v17.X * 0.05;
    v14 = 0.05 * (double)v17.Y;
    Rotation = v17.Rotation;
    XScale = v17.XScale;
    YScale = v17.YScale;
    v12 = Scaleform::GFx::DisplayObjectBase::GetCxform(v5)->M[0][3] * 100.0;
    v7 = v5->GetVisible(v5);
    v6 = pinfo;
    pinfo->X = v11;
    pinfo->VarsSet |= 0x7FFu;
    pinfo->Y = v14;
    pinfo->Visible = v7;
    pinfo->Rotation = Rotation;
    pinfo->XScale = XScale;
    pinfo->YScale = YScale;
    pinfo->Alpha = v12;
    pinfo->Z = v17.Z * 0.05;
    pinfo->XRotation = v17.XRotation;
    pinfo->YRotation = v17.YRotation;
    pinfo->ZScale = v17.ZScale;
  }
  v6->FOV = v5->GetFOV(v5);
  v6->VarsSet |= 0x800u;
  memset((int)dst, 0, sizeof(dst));
  *(float *)dst = 1.0;
  *(float *)&dst[20] = 1.0;
  *(float *)&dst[40] = 1.0;
  *(float *)&dst[60] = 1.0;
  if ( v5->GetProjectionMatrix3D(v5, (Scaleform::Render::Matrix4x4<float> *)dst, 0) )
  {
    v6->VarsSet |= 0x1000u;
    memcpy((unsigned __int8 *)&v6->ProjectionMatrix3D, dst, sizeof(v6->ProjectionMatrix3D));
  }
  memset((int)&pmat, 0, sizeof(pmat));
  pmat.M[0][0] = 1.0;
  pmat.M[1][1] = 1.0;
  pmat.M[2][2] = 1.0;
  if ( v5->GetViewMatrix3D(v5, &pmat, 0) )
    Scaleform::GFx::Value::DisplayInfo::SetViewMatrix3D(v6, &pmat);
  RenderNode = (unsigned int)Scaleform::GFx::DisplayObjectBase::GetRenderNode(v5);
  v9 = *(_WORD *)(*(_DWORD *)(*(_DWORD *)((RenderNode & 0xFFFFF000) + 0x10)
                            + 4 * ((int)(RenderNode - (RenderNode & 0xFFFFF000) - 28) / 28)
                            + 20)
                + 6)
     & 0xC;
  v6->VarsSet |= 0x4000u;
  v6->EdgeAAMode = v9;
  return 1;
}
