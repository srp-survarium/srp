char __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetDisplayInfo(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        const Scaleform::GFx::Value::DisplayInfo *cinfo)
{
  int v3; // ecx
  Scaleform::GFx::TextField *v5; // ebx
  const Scaleform::GFx::Value::DisplayInfo *v6; // esi
  Scaleform::Render::TreeNode *RenderNode; // eax
  const Scaleform::Render::Cxform *Cxform; // esi
  long double v9; // st7
  double v10; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // ecx
  long double v12; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v13; // ecx
  long double XRotation; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v15; // edi
  long double v16; // st7
  long double YRotation; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v18; // edi
  long double v19; // st7
  long double (__thiscall *GetFOV)(Scaleform::GFx::DisplayObjectBase *); // eax
  unsigned __int64 v21; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v22; // edi
  float *v23; // eax
  long double Y; // st7
  long double Rotation; // st7
  long double v26; // st7
  long double v27; // st6
  double v28; // st7
  long double v29; // st6
  bool v30; // c0
  bool v31; // c3
  double v32; // st7
  double v33; // st7
  long double v34; // st6
  long double v35; // st7
  long double v36; // st7
  long double v37; // st7
  int v38; // eax
  long double v39; // st7
  long double v40; // st7
  int v41; // eax
  bool v42; // al
  Scaleform::GFx::TextField_vtbl *v43; // edx
  long double v44; // st6
  long double v45; // st6
  long double v46; // st6
  float v; // [esp+8D4h] [ebp-A8h]
  Scaleform::Render::EdgeAAMode v_4; // [esp+8D8h] [ebp-A4h]
  float v_4a; // [esp+8D8h] [ebp-A4h]
  char result_2; // [esp+8EAh] [ebp-92h]
  bool result_3; // [esp+8EBh] [ebp-91h]
  long double result_4; // [esp+8ECh] [ebp-90h] BYREF
  long double sx; // [esp+8F4h] [ebp-88h]
  long double FOV; // [esp+8FCh] [ebp-80h]
  long double ZScale; // [esp+904h] [ebp-78h]
  Scaleform::Render::Matrix2x4<float> v56; // [esp+90Ch] [ebp-70h] BYREF
  Scaleform::Render::Cxform v57; // [esp+92Ch] [ebp-50h] BYREF
  long double v58; // [esp+954h] [ebp-28h]
  long double X; // [esp+95Ch] [ebp-20h]
  long double v60; // [esp+964h] [ebp-18h]
  long double v61; // [esp+96Ch] [ebp-10h]
  long double v62; // [esp+974h] [ebp-8h]

  v3 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v3 + 60) - 17) >= 0xC || (*(_DWORD *)(v3 + 56) & 0x20) != 0 )
    return 0;
  v5 = (Scaleform::GFx::TextField *)pdata[12];
  result_2 = 0;
  v6 = cinfo;
  result_3 = v5->GetType(v5) == MouseWheel;
  if ( (cinfo->VarsSet & 0x4000) != 0 )
  {
    v_4 = cinfo->EdgeAAMode;
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v5);
    Scaleform::Render::TreeNode::SetEdgeAAMode(RenderNode, v_4);
  }
  if ( (cinfo->VarsSet & 0x20) != 0 && !Scaleform::GFx::NumberUtil::IsNaN(cinfo->Alpha) )
  {
    Cxform = Scaleform::GFx::DisplayObjectBase::GetCxform(v5);
    v9 = cinfo->Alpha / 100.0;
    qmemcpy(&v57, Cxform, sizeof(v57));
    v57.M[0][3] = v9;
    Scaleform::GFx::DisplayObjectBase::SetCxform(v5, &v57);
    v5->SetAcceptAnimMoves(v5, 0);
    v6 = cinfo;
  }
  if ( (v6->VarsSet & 0x40) != 0 )
    v5->SetVisible(v5, v6->Visible);
  if ( SLOBYTE(v6->VarsSet) < 0 )
  {
    FOV = v6->Z * 20.0;
    if ( Scaleform::GFx::NumberUtil::IsNaN(FOV) )
      v10 = 0.0;
    else
      v10 = FOV;
    result_4 = v10;
    if ( v10 == -INFINITY || (result_4 = v10, v10 == INFINITY) )
      v10 = 0.0;
    pGeomData = v5->pGeomData;
    if ( pGeomData->Z != v10 )
    {
      pGeomData->Z = v10;
      result_2 = 1;
    }
  }
  if ( (v6->VarsSet & 0x400) != 0 )
  {
    ZScale = v6->ZScale;
    if ( Scaleform::GFx::NumberUtil::IsNaN(ZScale)
      || (result_4 = ZScale, ZScale == -INFINITY)
      || Scaleform::GFx::NumberUtil::IsPOSITIVE_INFINITY(ZScale) )
    {
      v12 = 100.0;
    }
    else
    {
      v12 = ZScale;
    }
    v13 = v5->pGeomData;
    if ( v12 != v13->ZScale )
    {
      v13->ZScale = v12;
      result_2 = 1;
    }
  }
  if ( (v6->VarsSet & 0x100) != 0 )
  {
    XRotation = v6->XRotation;
    v15 = v5->pGeomData;
    if ( v15->XRotation != XRotation )
    {
      v16 = fmod(XRotation, 360.0);
      if ( v16 <= 180.0 )
      {
        if ( v16 < -180.0 )
          v16 = v16 + 360.0;
        v15->XRotation = v16;
        result_2 = 1;
      }
      else
      {
        result_2 = 1;
        v15->XRotation = v16 - 360.0;
      }
    }
  }
  if ( (v6->VarsSet & 0x200) == 0 || (YRotation = v6->YRotation, v18 = v5->pGeomData, v18->YRotation == YRotation) )
  {
    if ( !result_2 )
      goto LABEL_44;
  }
  else
  {
    v19 = fmod(YRotation, 360.0);
    if ( v19 <= 180.0 )
    {
      if ( v19 < -180.0 )
        v19 = v19 + 360.0;
      v18->YRotation = v19;
    }
    else
    {
      v18->YRotation = v19 - 360.0;
    }
  }
  v5->UpdateTransform3D(v5);
LABEL_44:
  if ( (v6->VarsSet & 0x800) != 0 )
  {
    GetFOV = v5->GetFOV;
    FOV = v6->FOV;
    if ( FOV != GetFOV(v5) )
    {
      *(double *)&v21 = fmod(FOV, 180.0);
      ((void (__thiscall *)(Scaleform::GFx::TextField *, _DWORD, _DWORD))v5->SetFOV)(v5, v21, HIDWORD(v21));
    }
  }
  else
  {
    if ( (v6->VarsSet & 0x1000) != 0 )
      v5->SetProjectionMatrix3D(v5, &v6->ProjectionMatrix3D);
    if ( (v6->VarsSet & 0x2000) != 0 )
      v5->SetViewMatrix3D(v5, &v6->ViewMatrix3D);
  }
  if ( (v6->VarsSet & 0x1F) == 0 )
    return 1;
  if ( result_3 )
  {
    v5->Flags |= 0x2000u;
    Scaleform::GFx::TextField::SetDirtyFlag(v5);
  }
  v5->SetAcceptAnimMoves(v5, 0);
  v22 = v5->pGeomData;
  v23 = (float *)v5->GetMatrix(v5);
  v56.M[0][0] = *v23;
  v56.M[0][1] = v23[1];
  v56.M[0][2] = v23[2];
  v56.M[0][3] = v23[3];
  v56.M[1][0] = v23[4];
  v56.M[1][1] = v23[5];
  v56.M[1][2] = v23[6];
  v56.M[1][3] = v23[7];
  if ( result_3 && (v6->VarsSet & 3) != 0 )
  {
    Scaleform::GFx::TextField::TransformToTextRectSpace(v5, (Scaleform::Render::Point<float> *)&result_4, v6);
    X = *(float *)&result_4;
    Y = *((float *)&result_4 + 1);
  }
  else
  {
    if ( (v6->VarsSet & 1) != 0 )
      X = v6->X;
    if ( (v6->VarsSet & 2) == 0 )
      goto LABEL_62;
    Y = v6->Y;
  }
  v60 = Y;
LABEL_62:
  LODWORD(sx) = v6->VarsSet;
  if ( (LOBYTE(sx) & 0x1C) == 0 )
    goto LABEL_92;
  Scaleform::Render::Matrix2x4<float>::operator=((Scaleform::Render::Matrix2x4<float> *)&v57, &v22->OrigMatrix);
  v57.M[0][3] = v56.M[0][3];
  v57.M[1][3] = v56.M[1][3];
  v62 = atan2(v57.M[1][0], v57.M[0][0]);
  result_4 = sqrt(v57.M[0][0] * v57.M[0][0] + v57.M[1][0] * v57.M[1][0]);
  v58 = sqrt(v57.M[1][1] * v57.M[1][1] + v57.M[0][1] * v57.M[0][1]);
  ZScale = v22->XScale / 100.0;
  v61 = v22->YScale / 100.0;
  FOV = v22->Rotation * 3.141592653589793 / 180.0;
  if ( (LOBYTE(sx) & 4) != 0 )
    Rotation = v6->Rotation;
  else
    Rotation = Scaleform::GFx::NumberUtil::NaN();
  sx = Rotation;
  if ( !Scaleform::GFx::NumberUtil::IsNaN(Rotation) )
  {
    v26 = fmod(sx, 360.0);
    if ( v26 <= 180.0 )
    {
      v30 = v26 > -180.0;
      v31 = -180.0 == v26;
      v29 = v26;
      v28 = 180.0;
      if ( !v30 && !v31 )
        v29 = v29 + 360.0;
    }
    else
    {
      v27 = v26;
      v28 = 180.0;
      v29 = v27 - 360.0;
    }
    v22->Rotation = v29;
    FOV = v29 * 3.141592653589793 / v28;
  }
  if ( (v6->VarsSet & 8) != 0 )
    v32 = v6->XScale / 100.0;
  else
    v32 = Scaleform::GFx::NumberUtil::NaN();
  sx = v32;
  if ( ZScale != v32 && !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(v32) )
  {
    v22->XScale = v6->XScale;
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
  if ( (v6->VarsSet & 0x10) != 0 )
    v33 = v6->YScale / 100.0;
  else
    v33 = Scaleform::GFx::NumberUtil::NaN();
  sx = v33;
  v34 = v61;
  if ( v61 == v33 )
    goto LABEL_89;
  if ( Scaleform::GFx::NumberUtil::IsNaNOrInfinity(v33) )
  {
    v35 = v61;
    goto LABEL_91;
  }
  v22->YScale = v6->YScale;
  v35 = 0.0;
  if ( 0.0 != v58 && (v34 = sx, sx <= 1.0e16) )
LABEL_89:
    v35 = v34;
  else
    v58 = 1.0;
LABEL_91:
  *(float *)&sx = FOV - v62;
  v_4a = *(float *)&sx;
  *(float *)&sx = v35 / v58;
  v = *(float *)&sx;
  *(float *)&sx = ZScale / result_4;
  Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
    (Scaleform::Render::Matrix2x4<float> *)&v57,
    *(float *)&sx,
    v,
    v_4a);
  v56.M[0][0] = v57.M[0][0];
  v56.M[0][1] = v57.M[0][1];
  v56.M[0][2] = v57.M[0][2];
  v56.M[0][3] = v57.M[0][3];
  v56.M[1][0] = v57.M[1][0];
  v56.M[1][1] = v57.M[1][1];
  v56.M[1][2] = v57.M[1][2];
  v56.M[1][3] = v57.M[1][3];
LABEL_92:
  if ( (v6->VarsSet & 1) != 0 )
    v36 = X;
  else
    v36 = Scaleform::GFx::NumberUtil::NaN();
  result_4 = v36;
  if ( !Scaleform::GFx::NumberUtil::IsNaN(v36) )
  {
    FOV = result_4;
    if ( result_4 == -INFINITY || Scaleform::GFx::NumberUtil::IsPOSITIVE_INFINITY(result_4) )
      v37 = 0.0;
    else
      v37 = result_4;
    v38 = (int)floor(v37 * 20.0);
    LODWORD(sx) = v38;
    v22->X = v38;
    v56.M[0][3] = (float)v38;
  }
  if ( (v6->VarsSet & 2) != 0 )
    v39 = v60;
  else
    v39 = Scaleform::GFx::NumberUtil::NaN();
  result_4 = v39;
  if ( !Scaleform::GFx::NumberUtil::IsNaN(v39) )
  {
    FOV = result_4;
    if ( result_4 == -INFINITY || Scaleform::GFx::NumberUtil::IsPOSITIVE_INFINITY(result_4) )
      v40 = 0.0;
    else
      v40 = result_4;
    v41 = (int)floor(v40 * 20.0);
    LODWORD(sx) = v41;
    v22->Y = v41;
    v56.M[1][3] = (float)v41;
  }
  if ( Scaleform::Render::Matrix2x4<float>::IsValid(&v56) )
  {
    v42 = Scaleform::GFx::DisplayObjectBase::Has3D(v5);
    v43 = v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    if ( v42 )
      v43->UpdateTransform3D(v5);
    else
      v43->SetMatrix(v5, &v56);
  }
  if ( !result_3 )
    return 1;
  if ( (v6->VarsSet & 1) != 0 )
  {
    v44 = X * 20.0;
    if ( X * 20.0 <= 0.0 )
      v45 = v44 - 0.5;
    else
      v45 = v44 + 0.5;
    v22->X = (int)v45;
  }
  if ( (v6->VarsSet & 2) == 0 )
    return 1;
  v46 = v60 * 20.0;
  if ( v60 * 20.0 <= 0.0 )
    v22->Y = (int)(v46 - 0.5);
  else
    v22->Y = (int)(v46 + 0.5);
  return 1;
}
