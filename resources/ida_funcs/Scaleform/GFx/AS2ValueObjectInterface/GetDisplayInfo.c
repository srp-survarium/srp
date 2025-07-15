char __thiscall Scaleform::GFx::AS2ValueObjectInterface::GetDisplayInfo(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::GFx::Value::DisplayInfo *pinfo)
{
  Scaleform::GFx::TextField *v3; // edi
  Scaleform::GFx::Value::DisplayInfo *v5; // esi
  long double v6; // st7
  bool (__thiscall *GetVisible)(Scaleform::GFx::DisplayObjectBase *); // eax
  bool v8; // al
  long double v9; // st7
  unsigned int RenderNode; // eax
  int v11; // eax
  Scaleform::GFx::DisplayObjectBase::GeomDataType v12; // [esp+508h] [ebp-100h] BYREF
  long double YScale; // [esp+568h] [ebp-A0h]
  long double v14; // [esp+570h] [ebp-98h]
  long double Rotation; // [esp+578h] [ebp-90h]
  long double XScale; // [esp+580h] [ebp-88h]
  long double v17; // [esp+588h] [ebp-80h]
  long double v18; // [esp+590h] [ebp-78h]
  unsigned __int8 src[48]; // [esp+598h] [ebp-70h] BYREF
  unsigned __int8 dst[64]; // [esp+5C8h] [ebp-40h] BYREF

  v3 = (Scaleform::GFx::TextField *)Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v3 )
    return 0;
  v12.OrigMatrix.M[0][0] = 1.0;
  v12.OrigMatrix.M[0][1] = 0.0;
  v12.Y = 0;
  v12.OrigMatrix.M[0][2] = 0.0;
  v12.X = 0;
  v12.OrigMatrix.M[0][3] = 0.0;
  v12.OrigMatrix.M[1][0] = 0.0;
  v12.OrigMatrix.M[1][2] = 0.0;
  v12.OrigMatrix.M[1][3] = 0.0;
  v12.OrigMatrix.M[1][1] = 1.0;
  v12.Rotation = 0.0;
  v12.YScale = 100.0;
  v12.XScale = 100.0;
  v12.ZScale = 100.0;
  v12.YRotation = 0.0;
  v12.XRotation = 0.0;
  v12.Z = 0.0;
  Scaleform::GFx::DisplayObjectBase::GetGeomData(v3, &v12);
  if ( v3->GetType(v3) == MouseWheel )
  {
    v5 = pinfo;
    Scaleform::GFx::TextField::GetPosition(v3, pinfo);
  }
  else
  {
    v18 = (double)v12.X * 0.05;
    v17 = 0.05 * (double)v12.Y;
    Rotation = v12.Rotation;
    XScale = v12.XScale;
    YScale = v12.YScale;
    v6 = Scaleform::GFx::DisplayObjectBase::GetCxform(v3)->M[0][3] * 100.0;
    GetVisible = v3->GetVisible;
    v14 = v6;
    v8 = GetVisible(v3);
    v5 = pinfo;
    pinfo->X = v18;
    v9 = v17;
    pinfo->VarsSet |= 0x7FFu;
    pinfo->Y = v9;
    pinfo->Visible = v8;
    pinfo->Rotation = Rotation;
    pinfo->XScale = XScale;
    pinfo->YScale = YScale;
    pinfo->Alpha = v14;
    pinfo->Z = v12.Z;
    pinfo->XRotation = v12.XRotation;
    pinfo->YRotation = v12.YRotation;
    pinfo->ZScale = v12.ZScale;
  }
  v5->FOV = v3->GetFOV(v3);
  v5->VarsSet |= 0x800u;
  memset((int)dst, 0, sizeof(dst));
  *(float *)dst = 1.0;
  *(float *)&dst[20] = 1.0;
  *(float *)&dst[40] = 1.0;
  *(float *)&dst[60] = 1.0;
  if ( v3->GetProjectionMatrix3D(v3, (Scaleform::Render::Matrix4x4<float> *)dst, 0) )
  {
    v5->VarsSet |= 0x1000u;
    memcpy((unsigned __int8 *)&v5->ProjectionMatrix3D, dst, sizeof(v5->ProjectionMatrix3D));
  }
  memset((int)src, 0, sizeof(src));
  *(float *)src = 1.0;
  *(float *)&src[20] = 1.0;
  *(float *)&src[40] = 1.0;
  if ( v3->GetViewMatrix3D(v3, (Scaleform::Render::Matrix3x4<float> *)src, 0) )
  {
    v5->VarsSet |= 0x2000u;
    memcpy((unsigned __int8 *)&v5->ViewMatrix3D, src, sizeof(v5->ViewMatrix3D));
  }
  RenderNode = (unsigned int)Scaleform::GFx::DisplayObjectBase::GetRenderNode(v3);
  v11 = *(_WORD *)(*(_DWORD *)(*(_DWORD *)((RenderNode & 0xFFFFF000) + 0x10)
                             + 4 * ((int)(RenderNode - (RenderNode & 0xFFFFF000) - 28) / 28)
                             + 20)
                 + 6)
      & 0xC;
  v5->VarsSet |= 0x4000u;
  v5->EdgeAAMode = v11;
  return 1;
}
