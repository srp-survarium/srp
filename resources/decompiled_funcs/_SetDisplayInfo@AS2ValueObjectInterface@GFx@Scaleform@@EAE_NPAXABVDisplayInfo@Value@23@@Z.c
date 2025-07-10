char __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetDisplayInfo(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        const Scaleform::GFx::Value::DisplayInfo *cinfo)
{
  Scaleform::GFx::TextField *v3; // ebx
  const Scaleform::GFx::Value::DisplayInfo *v5; // esi
  Scaleform::Render::TreeNode *RenderNode; // eax
  const Scaleform::Render::Cxform *Cxform; // eax
  long double v8; // st7
  double v9; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // ecx
  long double v11; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v12; // ecx
  long double XRotation; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v14; // edi
  long double v15; // st7
  long double YRotation; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v17; // edi
  long double v18; // st7
  long double (__thiscall *GetFOV)(Scaleform::GFx::DisplayObjectBase *); // eax
  unsigned __int64 v20; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v21; // edi
  float *v22; // eax
  long double Y; // st7
  long double Rotation; // st7
  long double v25; // st7
  long double v26; // st6
  double v27; // st7
  long double v28; // st6
  bool v29; // c0
  bool v30; // c3
  double v31; // st7
  double v32; // st7
  long double v33; // st6
  long double v34; // st7
  long double v35; // st7
  long double v36; // st7
  int v37; // eax
  long double v38; // st7
  long double v39; // st7
  int v40; // eax
  bool v41; // al
  Scaleform::GFx::TextField_vtbl *v42; // edx
  long double v43; // st6
  long double v44; // st6
  long double v45; // st6
  float v; // [esp+8D4h] [ebp-A8h]
  Scaleform::Render::EdgeAAMode v_4; // [esp+8D8h] [ebp-A4h]
  float v_4a; // [esp+8D8h] [ebp-A4h]
  char result_2; // [esp+8EAh] [ebp-92h]
  bool result_3; // [esp+8EBh] [ebp-91h]
  long double result_4; // [esp+8ECh] [ebp-90h] BYREF
  long double sx; // [esp+8F4h] [ebp-88h]
  long double Z; // [esp+8FCh] [ebp-80h]
  long double ZScale; // [esp+904h] [ebp-78h]
  Scaleform::Render::Matrix2x4<float> v55; // [esp+90Ch] [ebp-70h] BYREF
  Scaleform::Render::Cxform v56; // [esp+92Ch] [ebp-50h] BYREF
  long double v57; // [esp+954h] [ebp-28h]
  long double X; // [esp+95Ch] [ebp-20h]
  long double v59; // [esp+964h] [ebp-18h]
  long double v60; // [esp+96Ch] [ebp-10h]
  long double v61; // [esp+974h] [ebp-8h]

  v3 = (Scaleform::GFx::TextField *)Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v3 )
    return 0;
  result_2 = 0;
  v5 = cinfo;
  result_3 = v3->GetType(v3) == MouseWheel;
  if ( (cinfo->VarsSet & 0x4000) != 0 )
  {
    v_4 = cinfo->EdgeAAMode;
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v3);
    Scaleform::Render::TreeNode::SetEdgeAAMode(RenderNode, v_4);
  }
  if ( (cinfo->VarsSet & 0x20) != 0 && !Scaleform::GFx::NumberUtil::IsNaN(cinfo->Alpha) )
  {
    Cxform = Scaleform::GFx::DisplayObjectBase::GetCxform(v3);
    v8 = cinfo->Alpha / 100.0;
    qmemcpy(&v56, Cxform, sizeof(v56));
    v56.M[0][3] = v8;
    Scaleform::GFx::DisplayObjectBase::SetCxform(v3, &v56);
    v3->SetAcceptAnimMoves(v3, 0);
    v5 = cinfo;
  }
  if ( (v5->VarsSet & 0x40) != 0 )
    v3->SetVisible(v3, v5->Visible);
  if ( SLOBYTE(v5->VarsSet) < 0 )
  {
    Z = v5->Z;
    if ( Scaleform::GFx::NumberUtil::IsNaN(Z) )
      v9 = 0.0;
    else
      v9 = Z;
    result_4 = v9;
    if ( v9 == -INFINITY || (result_4 = v9, v9 == INFINITY) )
      v9 = 0.0;
    pGeomData = v3->pGeomData;
    if ( pGeomData->Z != v9 )
    {
      pGeomData->Z = v9;
      result_2 = 1;
    }
  }
  if ( (v5->VarsSet & 0x400) != 0 )
  {
    ZScale = v5->ZScale;
    if ( Scaleform::GFx::NumberUtil::IsNaN(ZScale)
      || (result_4 = ZScale, ZScale == -INFINITY)
      || Scaleform::GFx::NumberUtil::IsPOSITIVE_INFINITY(ZScale) )
    {
      v11 = 100.0;
    }
    else
    {
      v11 = ZScale;
    }
    v12 = v3->pGeomData;
    if ( v11 != v12->ZScale )
    {
      v12->ZScale = v11;
      result_2 = 1;
    }
  }
  if ( (v5->VarsSet & 0x100) != 0 )
  {
    XRotation = v5->XRotation;
    v14 = v3->pGeomData;
    if ( v14->XRotation != XRotation )
    {
      v15 = fmod(XRotation, 360.0);
      if ( v15 <= 180.0 )
      {
        if ( v15 < -180.0 )
          v15 = v15 + 360.0;
        v14->XRotation = v15;
        result_2 = 1;
      }
      else
      {
        result_2 = 1;
        v14->XRotation = v15 - 360.0;
      }
    }
  }
  if ( (v5->VarsSet & 0x200) == 0 || (YRotation = v5->YRotation, v17 = v3->pGeomData, v17->YRotation == YRotation) )
  {
    if ( !result_2 )
      goto LABEL_43;
  }
  else
  {
    v18 = fmod(YRotation, 360.0);
    if ( v18 <= 180.0 )
    {
      if ( v18 < -180.0 )
        v18 = v18 + 360.0;
      v17->YRotation = v18;
    }
    else
    {
      v17->YRotation = v18 - 360.0;
    }
  }
  v3->UpdateTransform3D(v3);
LABEL_43:
  if ( (v5->VarsSet & 0x800) != 0 )
  {
    GetFOV = v3->GetFOV;
    Z = v5->FOV;
    if ( Z != GetFOV(v3) )
    {
      *(double *)&v20 = fmod(Z, 180.0);
      ((void (__thiscall *)(Scaleform::GFx::TextField *, _DWORD, _DWORD))v3->SetFOV)(v3, v20, HIDWORD(v20));
    }
  }
  else
  {
    if ( (v5->VarsSet & 0x1000) != 0 )
      v3->SetProjectionMatrix3D(v3, &v5->ProjectionMatrix3D);
    if ( (v5->VarsSet & 0x2000) != 0 )
      v3->SetViewMatrix3D(v3, &v5->ViewMatrix3D);
  }
  if ( (v5->VarsSet & 0x1F) == 0 )
    return 1;
  if ( result_3 )
  {
    v3->Flags |= 0x2000u;
    Scaleform::GFx::TextField::SetDirtyFlag(v3);
  }
  v3->SetAcceptAnimMoves(v3, 0);
  v21 = v3->pGeomData;
  v22 = (float *)v3->GetMatrix(v3);
  v55.M[0][0] = *v22;
  v55.M[0][1] = v22[1];
  v55.M[0][2] = v22[2];
  v55.M[0][3] = v22[3];
  v55.M[1][0] = v22[4];
  v55.M[1][1] = v22[5];
  v55.M[1][2] = v22[6];
  v55.M[1][3] = v22[7];
  if ( result_3 && (v5->VarsSet & 3) != 0 )
  {
    Scaleform::GFx::TextField::TransformToTextRectSpace(v3, (Scaleform::Render::Point<float> *)&result_4, v5);
    X = *(float *)&result_4;
    Y = *((float *)&result_4 + 1);
  }
  else
  {
    if ( (v5->VarsSet & 1) != 0 )
      X = v5->X;
    if ( (v5->VarsSet & 2) == 0 )
      goto LABEL_61;
    Y = v5->Y;
  }
  v59 = Y;
LABEL_61:
  LODWORD(sx) = v5->VarsSet;
  if ( (LOBYTE(sx) & 0x1C) == 0 )
    goto LABEL_91;
  Scaleform::Render::Matrix2x4<float>::operator=((Scaleform::Render::Matrix2x4<float> *)&v56, &v21->OrigMatrix);
  v56.M[0][3] = v55.M[0][3];
  v56.M[1][3] = v55.M[1][3];
  v61 = atan2(v56.M[1][0], v56.M[0][0]);
  result_4 = sqrt(v56.M[0][0] * v56.M[0][0] + v56.M[1][0] * v56.M[1][0]);
  v57 = sqrt(v56.M[1][1] * v56.M[1][1] + v56.M[0][1] * v56.M[0][1]);
  ZScale = v21->XScale / 100.0;
  v60 = v21->YScale / 100.0;
  Z = v21->Rotation * 3.141592653589793 / 180.0;
  if ( (LOBYTE(sx) & 4) != 0 )
    Rotation = v5->Rotation;
  else
    Rotation = Scaleform::GFx::NumberUtil::NaN();
  sx = Rotation;
  if ( !Scaleform::GFx::NumberUtil::IsNaN(Rotation) )
  {
    v25 = fmod(sx, 360.0);
    if ( v25 <= 180.0 )
    {
      v29 = v25 > -180.0;
      v30 = -180.0 == v25;
      v28 = v25;
      v27 = 180.0;
      if ( !v29 && !v30 )
        v28 = v28 + 360.0;
    }
    else
    {
      v26 = v25;
      v27 = 180.0;
      v28 = v26 - 360.0;
    }
    v21->Rotation = v28;
    Z = v28 * 3.141592653589793 / v27;
  }
  if ( (v5->VarsSet & 8) != 0 )
    v31 = v5->XScale / 100.0;
  else
    v31 = Scaleform::GFx::NumberUtil::NaN();
  sx = v31;
  if ( ZScale != v31 && !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(v31) )
  {
    v21->XScale = v5->XScale;
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
  if ( (v5->VarsSet & 0x10) != 0 )
    v32 = v5->YScale / 100.0;
  else
    v32 = Scaleform::GFx::NumberUtil::NaN();
  sx = v32;
  v33 = v60;
  if ( v60 == v32 )
    goto LABEL_88;
  if ( Scaleform::GFx::NumberUtil::IsNaNOrInfinity(v32) )
  {
    v34 = v60;
    goto LABEL_90;
  }
  v21->YScale = v5->YScale;
  v34 = 0.0;
  if ( 0.0 != v57 && (v33 = sx, sx <= 1.0e16) )
LABEL_88:
    v34 = v33;
  else
    v57 = 1.0;
LABEL_90:
  *(float *)&sx = Z - v61;
  v_4a = *(float *)&sx;
  *(float *)&sx = v34 / v57;
  v = *(float *)&sx;
  *(float *)&sx = ZScale / result_4;
  Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
    (Scaleform::Render::Matrix2x4<float> *)&v56,
    *(float *)&sx,
    v,
    v_4a);
  v55.M[0][0] = v56.M[0][0];
  v55.M[0][1] = v56.M[0][1];
  v55.M[0][2] = v56.M[0][2];
  v55.M[0][3] = v56.M[0][3];
  v55.M[1][0] = v56.M[1][0];
  v55.M[1][1] = v56.M[1][1];
  v55.M[1][2] = v56.M[1][2];
  v55.M[1][3] = v56.M[1][3];
LABEL_91:
  if ( (v5->VarsSet & 1) != 0 )
    v35 = X;
  else
    v35 = Scaleform::GFx::NumberUtil::NaN();
  result_4 = v35;
  if ( !Scaleform::GFx::NumberUtil::IsNaN(v35) )
  {
    Z = result_4;
    if ( result_4 == -INFINITY || Scaleform::GFx::NumberUtil::IsPOSITIVE_INFINITY(result_4) )
      v36 = 0.0;
    else
      v36 = result_4;
    v37 = (int)floor(v36 * 20.0);
    LODWORD(sx) = v37;
    v21->X = v37;
    v55.M[0][3] = (float)v37;
  }
  if ( (v5->VarsSet & 2) != 0 )
    v38 = v59;
  else
    v38 = Scaleform::GFx::NumberUtil::NaN();
  result_4 = v38;
  if ( !Scaleform::GFx::NumberUtil::IsNaN(v38) )
  {
    Z = result_4;
    if ( result_4 == -INFINITY || Scaleform::GFx::NumberUtil::IsPOSITIVE_INFINITY(result_4) )
      v39 = 0.0;
    else
      v39 = result_4;
    v40 = (int)floor(v39 * 20.0);
    LODWORD(sx) = v40;
    v21->Y = v40;
    v55.M[1][3] = (float)v40;
  }
  if ( Scaleform::Render::Matrix2x4<float>::IsValid(&v55) )
  {
    v41 = Scaleform::GFx::DisplayObjectBase::Has3D(v3);
    v42 = v3->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    if ( v41 )
      v42->UpdateTransform3D(v3);
    else
      v42->SetMatrix(v3, &v55);
  }
  if ( !result_3 )
    return 1;
  if ( (v5->VarsSet & 1) != 0 )
  {
    v43 = X * 20.0;
    if ( X * 20.0 <= 0.0 )
      v44 = v43 - 0.5;
    else
      v44 = v43 + 0.5;
    v21->X = (int)v44;
  }
  if ( (v5->VarsSet & 2) == 0 )
    return 1;
  v45 = v59 * 20.0;
  if ( v59 * 20.0 <= 0.0 )
    v21->Y = (int)(v45 - 0.5);
  else
    v21->Y = (int)(v45 + 0.5);
  return 1;
}
