char __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetDisplayInfo(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        const Scaleform::GFx::Value::DisplayInfo *cinfo)
{
  Scaleform::GFx::AMP::ViewStats *v4; // eax
  Scaleform::GFx::InteractiveObject *v5; // eax
  Scaleform::GFx::TextField *v6; // ebx
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 ProfileTicks; // rax
  const Scaleform::GFx::Value::DisplayInfo *v11; // esi
  Scaleform::Render::TreeNode *RenderNode; // eax
  const Scaleform::Render::Cxform *Cxform; // esi
  long double v14; // st7
  double v15; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // ecx
  long double v17; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v18; // ecx
  long double XRotation; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v20; // edi
  long double v21; // st7
  long double YRotation; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v23; // edi
  long double v24; // st7
  long double (__thiscall *GetFOV)(Scaleform::GFx::DisplayObjectBase *); // eax
  unsigned __int64 v26; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v27; // edi
  float *v28; // eax
  long double Y; // st7
  long double Rotation; // st7
  long double v31; // st7
  long double v32; // st6
  double v33; // st7
  long double v34; // st6
  bool v35; // c0
  bool v36; // c3
  double v37; // st7
  double v38; // st7
  long double v39; // st6
  long double v40; // st7
  long double v41; // st7
  long double v42; // st7
  int v43; // eax
  long double v44; // st7
  long double v45; // st7
  int v46; // eax
  bool v47; // al
  Scaleform::GFx::TextField_vtbl *v48; // edx
  long double v49; // st6
  long double v50; // st6
  long double v51; // st6
  Scaleform::AmpStats *v52; // esi
  Scaleform::AmpStats_vtbl *v53; // edi
  unsigned __int64 v54; // rax
  float sy; // [esp+10h] [ebp-B8h]
  Scaleform::Render::EdgeAAMode sy_4; // [esp+14h] [ebp-B4h]
  float sy_4a; // [esp+14h] [ebp-B4h]
  char result_2; // [esp+26h] [ebp-A2h]
  bool result_3; // [esp+27h] [ebp-A1h]
  long double result_4; // [esp+28h] [ebp-A0h] BYREF
  long double sx; // [esp+30h] [ebp-98h]
  long double Z; // [esp+38h] [ebp-90h]
  long double ZScale; // [esp+40h] [ebp-88h]
  Scaleform::Render::Matrix2x4<float> v64; // [esp+48h] [ebp-80h] BYREF
  Scaleform::Render::Cxform v65; // [esp+68h] [ebp-60h] BYREF
  long double X; // [esp+90h] [ebp-38h]
  long double v67; // [esp+98h] [ebp-30h]
  long double v68; // [esp+A0h] [ebp-28h]
  Scaleform::AmpFunctionTimer v69; // [esp+A8h] [ebp-20h] BYREF
  long double v70; // [esp+B8h] [ebp-10h]
  long double v71; // [esp+C0h] [ebp-8h]

  v4 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v69,
    v4,
    "ObjectInterface::SetDisplayInfo",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_SetDisplayInfo);
  v5 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  v6 = (Scaleform::GFx::TextField *)v5;
  if ( !v5 )
  {
    Stats = v69.Stats;
    if ( v69.Stats )
    {
      v8 = v69.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v69.StartTicks),
        (ProfileTicks - v69.StartTicks) >> 32);
    }
    return 0;
  }
  result_2 = 0;
  v11 = cinfo;
  result_3 = v5->GetType(v5) == MouseWheel;
  if ( (cinfo->VarsSet & 0x4000) != 0 )
  {
    sy_4 = cinfo->EdgeAAMode;
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v6);
    Scaleform::Render::TreeNode::SetEdgeAAMode(RenderNode, sy_4);
  }
  if ( (cinfo->VarsSet & 0x20) != 0 && !Scaleform::GFx::NumberUtil::IsNaN(cinfo->Alpha) )
  {
    Cxform = Scaleform::GFx::DisplayObjectBase::GetCxform(v6);
    v14 = cinfo->Alpha / 100.0;
    qmemcpy(&v65, Cxform, sizeof(v65));
    v65.M[0][3] = v14;
    Scaleform::GFx::DisplayObjectBase::SetCxform(v6, &v65);
    v6->SetAcceptAnimMoves(v6, 0);
    v11 = cinfo;
  }
  if ( (v11->VarsSet & 0x40) != 0 )
    v6->SetVisible(v6, v11->Visible);
  if ( SLOBYTE(v11->VarsSet) < 0 )
  {
    Z = v11->Z;
    if ( Scaleform::GFx::NumberUtil::IsNaN(Z) )
      v15 = 0.0;
    else
      v15 = Z;
    result_4 = v15;
    if ( v15 == -INFINITY || (result_4 = v15, v15 == INFINITY) )
      v15 = 0.0;
    pGeomData = v6->pGeomData;
    if ( pGeomData->Z != v15 )
    {
      pGeomData->Z = v15;
      result_2 = 1;
    }
  }
  if ( (v11->VarsSet & 0x400) != 0 )
  {
    ZScale = v11->ZScale;
    if ( Scaleform::GFx::NumberUtil::IsNaN(ZScale)
      || (result_4 = ZScale, ZScale == -INFINITY)
      || Scaleform::GFx::NumberUtil::IsPOSITIVE_INFINITY(ZScale) )
    {
      v17 = 100.0;
    }
    else
    {
      v17 = ZScale;
    }
    v18 = v6->pGeomData;
    if ( v17 != v18->ZScale )
    {
      v18->ZScale = v17;
      result_2 = 1;
    }
  }
  if ( (v11->VarsSet & 0x100) != 0 )
  {
    XRotation = v11->XRotation;
    v20 = v6->pGeomData;
    if ( v20->XRotation != XRotation )
    {
      v21 = fmod(XRotation, 360.0);
      if ( v21 <= 180.0 )
      {
        if ( v21 < -180.0 )
          v21 = v21 + 360.0;
        v20->XRotation = v21;
        result_2 = 1;
      }
      else
      {
        result_2 = 1;
        v20->XRotation = v21 - 360.0;
      }
    }
  }
  if ( (v11->VarsSet & 0x200) == 0 || (YRotation = v11->YRotation, v23 = v6->pGeomData, v23->YRotation == YRotation) )
  {
    if ( !result_2 )
      goto LABEL_45;
  }
  else
  {
    v24 = fmod(YRotation, 360.0);
    if ( v24 <= 180.0 )
    {
      if ( v24 < -180.0 )
        v24 = v24 + 360.0;
      v23->YRotation = v24;
    }
    else
    {
      v23->YRotation = v24 - 360.0;
    }
  }
  v6->UpdateTransform3D(v6);
LABEL_45:
  if ( (v11->VarsSet & 0x800) != 0 )
  {
    GetFOV = v6->GetFOV;
    Z = v11->FOV;
    if ( Z != GetFOV(v6) )
    {
      *(double *)&v26 = fmod(Z, 180.0);
      ((void (__thiscall *)(Scaleform::GFx::TextField *, _DWORD, _DWORD))v6->SetFOV)(v6, v26, HIDWORD(v26));
    }
  }
  else
  {
    if ( (v11->VarsSet & 0x1000) != 0 )
      v6->SetProjectionMatrix3D(v6, &v11->ProjectionMatrix3D);
    if ( (v11->VarsSet & 0x2000) != 0 )
      v6->SetViewMatrix3D(v6, &v11->ViewMatrix3D);
  }
  if ( (v11->VarsSet & 0x1F) == 0 )
    goto LABEL_125;
  if ( result_3 )
  {
    v6->Flags |= 0x2000u;
    Scaleform::GFx::TextField::SetDirtyFlag(v6);
  }
  v6->SetAcceptAnimMoves(v6, 0);
  v27 = v6->pGeomData;
  v28 = (float *)v6->GetMatrix(v6);
  v64.M[0][0] = *v28;
  v64.M[0][1] = v28[1];
  v64.M[0][2] = v28[2];
  v64.M[0][3] = v28[3];
  v64.M[1][0] = v28[4];
  v64.M[1][1] = v28[5];
  v64.M[1][2] = v28[6];
  v64.M[1][3] = v28[7];
  if ( result_3 && (v11->VarsSet & 3) != 0 )
  {
    Scaleform::GFx::TextField::TransformToTextRectSpace(v6, (Scaleform::Render::Point<float> *)&result_4, v11);
    X = *(float *)&result_4;
    Y = *((float *)&result_4 + 1);
LABEL_62:
    v67 = Y;
    goto LABEL_63;
  }
  if ( (v11->VarsSet & 1) != 0 )
    X = v11->X;
  if ( (v11->VarsSet & 2) != 0 )
  {
    Y = v11->Y;
    goto LABEL_62;
  }
LABEL_63:
  LODWORD(sx) = v11->VarsSet;
  if ( (LOBYTE(sx) & 0x1C) != 0 )
  {
    Scaleform::Render::Matrix2x4<float>::operator=((Scaleform::Render::Matrix2x4<float> *)&v65, &v27->OrigMatrix);
    v65.M[0][3] = v64.M[0][3];
    v65.M[1][3] = v64.M[1][3];
    v71 = atan2(v65.M[1][0], v65.M[0][0]);
    result_4 = sqrt(v65.M[0][0] * v65.M[0][0] + v65.M[1][0] * v65.M[1][0]);
    v68 = sqrt(v65.M[1][1] * v65.M[1][1] + v65.M[0][1] * v65.M[0][1]);
    ZScale = v27->XScale / 100.0;
    v70 = v27->YScale / 100.0;
    Z = v27->Rotation * 3.141592653589793 / 180.0;
    if ( (LOBYTE(sx) & 4) != 0 )
      Rotation = v11->Rotation;
    else
      Rotation = Scaleform::GFx::NumberUtil::NaN();
    sx = Rotation;
    if ( !Scaleform::GFx::NumberUtil::IsNaN(Rotation) )
    {
      v31 = fmod(sx, 360.0);
      if ( v31 <= 180.0 )
      {
        v35 = v31 > -180.0;
        v36 = -180.0 == v31;
        v34 = v31;
        v33 = 180.0;
        if ( !v35 && !v36 )
          v34 = v34 + 360.0;
      }
      else
      {
        v32 = v31;
        v33 = 180.0;
        v34 = v32 - 360.0;
      }
      v27->Rotation = v34;
      Z = v34 * 3.141592653589793 / v33;
    }
    if ( (v11->VarsSet & 8) != 0 )
      v37 = v11->XScale / 100.0;
    else
      v37 = Scaleform::GFx::NumberUtil::NaN();
    sx = v37;
    if ( ZScale != v37 && !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(v37) )
    {
      v27->XScale = v11->XScale;
      if ( 0.0 == result_4 || sx > 1.0e16 )
      {
        result_4 = 1.0;
        ZScale = 0.0;
      }
      else
      {
        ZScale = sx;
      }
    }
    if ( (v11->VarsSet & 0x10) != 0 )
      v38 = v11->YScale / 100.0;
    else
      v38 = Scaleform::GFx::NumberUtil::NaN();
    sx = v38;
    v39 = v70;
    if ( v70 == v38 )
      goto LABEL_90;
    if ( Scaleform::GFx::NumberUtil::IsNaNOrInfinity(v38) )
    {
      v40 = v70;
      goto LABEL_92;
    }
    v27->YScale = v11->YScale;
    v40 = 0.0;
    if ( 0.0 != v68 && (v39 = sx, sx <= 1.0e16) )
LABEL_90:
      v40 = v39;
    else
      v68 = 1.0;
LABEL_92:
    *(float *)&sx = Z - v71;
    sy_4a = *(float *)&sx;
    *(float *)&sx = v40 / v68;
    sy = *(float *)&sx;
    *(float *)&sx = ZScale / result_4;
    Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
      (Scaleform::Render::Matrix2x4<float> *)&v65,
      *(float *)&sx,
      sy,
      sy_4a);
    v64.M[0][0] = v65.M[0][0];
    v64.M[0][1] = v65.M[0][1];
    v64.M[0][2] = v65.M[0][2];
    v64.M[0][3] = v65.M[0][3];
    v64.M[1][0] = v65.M[1][0];
    v64.M[1][1] = v65.M[1][1];
    v64.M[1][2] = v65.M[1][2];
    v64.M[1][3] = v65.M[1][3];
  }
  if ( (v11->VarsSet & 1) != 0 )
    v41 = X;
  else
    v41 = Scaleform::GFx::NumberUtil::NaN();
  result_4 = v41;
  if ( !Scaleform::GFx::NumberUtil::IsNaN(v41) )
  {
    Z = result_4;
    if ( result_4 == -INFINITY || Scaleform::GFx::NumberUtil::IsPOSITIVE_INFINITY(result_4) )
      v42 = 0.0;
    else
      v42 = result_4;
    v43 = (int)floor(v42 * 20.0);
    LODWORD(sx) = v43;
    v27->X = v43;
    v64.M[0][3] = (float)v43;
  }
  if ( (v11->VarsSet & 2) != 0 )
    v44 = v67;
  else
    v44 = Scaleform::GFx::NumberUtil::NaN();
  result_4 = v44;
  if ( !Scaleform::GFx::NumberUtil::IsNaN(v44) )
  {
    Z = result_4;
    if ( result_4 == -INFINITY || Scaleform::GFx::NumberUtil::IsPOSITIVE_INFINITY(result_4) )
      v45 = 0.0;
    else
      v45 = result_4;
    v46 = (int)floor(v45 * 20.0);
    LODWORD(sx) = v46;
    v27->Y = v46;
    v64.M[1][3] = (float)v46;
  }
  if ( Scaleform::Render::Matrix2x4<float>::IsValid(&v64) )
  {
    v47 = Scaleform::GFx::DisplayObjectBase::Has3D(v6);
    v48 = v6->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    if ( v47 )
      v48->UpdateTransform3D(v6);
    else
      v48->SetMatrix(v6, &v64);
  }
  if ( result_3 )
  {
    if ( (v11->VarsSet & 1) != 0 )
    {
      v49 = X * 20.0;
      if ( X * 20.0 <= 0.0 )
        v50 = v49 - 0.5;
      else
        v50 = v49 + 0.5;
      v27->X = (int)v50;
    }
    if ( (v11->VarsSet & 2) != 0 )
    {
      v51 = v67 * 20.0;
      if ( v67 * 20.0 <= 0.0 )
        v27->Y = (int)(v51 - 0.5);
      else
        v27->Y = (int)(v51 + 0.5);
    }
  }
LABEL_125:
  v52 = v69.Stats;
  if ( v69.Stats )
  {
    v53 = v69.Stats->__vftable;
    v54 = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v53->NativePopCallstack)(
      v52,
      v54 - LODWORD(v69.StartTicks),
      (v54 - v69.StartTicks) >> 32);
  }
  return 1;
}
