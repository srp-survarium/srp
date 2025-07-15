char __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetDisplayInfo(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        const Scaleform::GFx::Value::DisplayInfo *cinfo)
{
  Scaleform::GFx::AMP::ViewStats *v3; // eax
  int v4; // ecx
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v6; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::TextField *v9; // ebx
  const Scaleform::GFx::Value::DisplayInfo *v10; // esi
  Scaleform::Render::TreeNode *RenderNode; // eax
  const Scaleform::Render::Cxform *Cxform; // eax
  long double v13; // st7
  double v14; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // ecx
  long double v16; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v17; // ecx
  long double XRotation; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v19; // edi
  long double v20; // st7
  long double YRotation; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v22; // edi
  long double v23; // st7
  long double (__thiscall *GetFOV)(Scaleform::GFx::DisplayObjectBase *); // eax
  unsigned __int64 v25; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v26; // edi
  float *v27; // eax
  long double Y; // st7
  long double Rotation; // st7
  long double v30; // st7
  long double v31; // st6
  double v32; // st7
  long double v33; // st6
  bool v34; // c0
  bool v35; // c3
  double v36; // st7
  double v37; // st7
  long double v38; // st6
  long double v39; // st7
  long double v40; // st7
  long double v41; // st7
  int v42; // eax
  long double v43; // st7
  long double v44; // st7
  int v45; // eax
  bool v46; // al
  Scaleform::GFx::TextField_vtbl *v47; // edx
  long double v48; // st6
  long double v49; // st6
  long double v50; // st6
  Scaleform::AmpStats *v51; // esi
  Scaleform::AmpStats_vtbl *v52; // edi
  unsigned __int64 v53; // rax
  float sy; // [esp+A1Ch] [ebp-B8h]
  Scaleform::Render::EdgeAAMode sy_4; // [esp+A20h] [ebp-B4h]
  float sy_4a; // [esp+A20h] [ebp-B4h]
  char result_2; // [esp+A32h] [ebp-A2h]
  bool result_3; // [esp+A33h] [ebp-A1h]
  long double result_4; // [esp+A34h] [ebp-A0h] BYREF
  long double sx; // [esp+A3Ch] [ebp-98h]
  long double FOV; // [esp+A44h] [ebp-90h]
  long double ZScale; // [esp+A4Ch] [ebp-88h]
  Scaleform::Render::Matrix2x4<float> v63; // [esp+A54h] [ebp-80h] BYREF
  Scaleform::Render::Cxform v64; // [esp+A74h] [ebp-60h] BYREF
  long double X; // [esp+A9Ch] [ebp-38h]
  long double v66; // [esp+AA4h] [ebp-30h]
  long double v67; // [esp+AACh] [ebp-28h]
  Scaleform::AmpFunctionTimer v68; // [esp+AB4h] [ebp-20h] BYREF
  long double v69; // [esp+AC4h] [ebp-10h]
  long double v70; // [esp+ACCh] [ebp-8h]

  v3 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v68,
    v3,
    "ObjectInterface::SetDisplayInfo",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_SetDisplayInfo);
  v4 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v4 + 60) - 17) >= 0xC || (*(_DWORD *)(v4 + 56) & 0x20) != 0 )
  {
    Stats = v68.Stats;
    if ( v68.Stats )
    {
      v6 = v68.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v6->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v68.StartTicks),
        (ProfileTicks - v68.StartTicks) >> 32);
    }
    return 0;
  }
  v9 = (Scaleform::GFx::TextField *)pdata[12];
  result_2 = 0;
  v10 = cinfo;
  result_3 = v9->GetType(v9) == MouseWheel;
  if ( (cinfo->VarsSet & 0x4000) != 0 )
  {
    sy_4 = cinfo->EdgeAAMode;
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v9);
    Scaleform::Render::TreeNode::SetEdgeAAMode(RenderNode, sy_4);
  }
  if ( (cinfo->VarsSet & 0x20) != 0 && !Scaleform::GFx::NumberUtil::IsNaN(cinfo->Alpha) )
  {
    Cxform = Scaleform::GFx::DisplayObjectBase::GetCxform(v9);
    v13 = cinfo->Alpha / 100.0;
    qmemcpy(&v64, Cxform, sizeof(v64));
    v64.M[0][3] = v13;
    Scaleform::GFx::DisplayObjectBase::SetCxform(v9, &v64);
    v9->SetAcceptAnimMoves(v9, 0);
    v10 = cinfo;
  }
  if ( (v10->VarsSet & 0x40) != 0 )
    v9->SetVisible(v9, v10->Visible);
  if ( SLOBYTE(v10->VarsSet) < 0 )
  {
    FOV = v10->Z * 20.0;
    if ( Scaleform::GFx::NumberUtil::IsNaN(FOV) )
      v14 = 0.0;
    else
      v14 = FOV;
    result_4 = v14;
    if ( v14 == -INFINITY || (result_4 = v14, v14 == INFINITY) )
      v14 = 0.0;
    pGeomData = v9->pGeomData;
    if ( pGeomData->Z != v14 )
    {
      pGeomData->Z = v14;
      result_2 = 1;
    }
  }
  if ( (v10->VarsSet & 0x400) != 0 )
  {
    ZScale = v10->ZScale;
    if ( Scaleform::GFx::NumberUtil::IsNaN(ZScale)
      || (result_4 = ZScale, ZScale == -INFINITY)
      || Scaleform::GFx::NumberUtil::IsPOSITIVE_INFINITY(ZScale) )
    {
      v16 = 100.0;
    }
    else
    {
      v16 = ZScale;
    }
    v17 = v9->pGeomData;
    if ( v16 != v17->ZScale )
    {
      v17->ZScale = v16;
      result_2 = 1;
    }
  }
  if ( (v10->VarsSet & 0x100) != 0 )
  {
    XRotation = v10->XRotation;
    v19 = v9->pGeomData;
    if ( v19->XRotation != XRotation )
    {
      v20 = fmod(XRotation, 360.0);
      if ( v20 <= 180.0 )
      {
        if ( v20 < -180.0 )
          v20 = v20 + 360.0;
        v19->XRotation = v20;
        result_2 = 1;
      }
      else
      {
        result_2 = 1;
        v19->XRotation = v20 - 360.0;
      }
    }
  }
  if ( (v10->VarsSet & 0x200) == 0 || (YRotation = v10->YRotation, v22 = v9->pGeomData, v22->YRotation == YRotation) )
  {
    if ( !result_2 )
      goto LABEL_46;
  }
  else
  {
    v23 = fmod(YRotation, 360.0);
    if ( v23 <= 180.0 )
    {
      if ( v23 < -180.0 )
        v23 = v23 + 360.0;
      v22->YRotation = v23;
    }
    else
    {
      v22->YRotation = v23 - 360.0;
    }
  }
  v9->UpdateTransform3D(v9);
LABEL_46:
  if ( (v10->VarsSet & 0x800) != 0 )
  {
    GetFOV = v9->GetFOV;
    FOV = v10->FOV;
    if ( FOV != GetFOV(v9) )
    {
      *(double *)&v25 = fmod(FOV, 180.0);
      ((void (__thiscall *)(Scaleform::GFx::TextField *, _DWORD, _DWORD))v9->SetFOV)(v9, v25, HIDWORD(v25));
    }
  }
  else
  {
    if ( (v10->VarsSet & 0x1000) != 0 )
      v9->SetProjectionMatrix3D(v9, &v10->ProjectionMatrix3D);
    if ( (v10->VarsSet & 0x2000) != 0 )
      v9->SetViewMatrix3D(v9, &v10->ViewMatrix3D);
  }
  if ( (v10->VarsSet & 0x1F) == 0 )
    goto LABEL_126;
  if ( result_3 )
  {
    v9->Flags |= 0x2000u;
    Scaleform::GFx::TextField::SetDirtyFlag(v9);
  }
  v9->SetAcceptAnimMoves(v9, 0);
  v26 = v9->pGeomData;
  v27 = (float *)v9->GetMatrix(v9);
  v63.M[0][0] = *v27;
  v63.M[0][1] = v27[1];
  v63.M[0][2] = v27[2];
  v63.M[0][3] = v27[3];
  v63.M[1][0] = v27[4];
  v63.M[1][1] = v27[5];
  v63.M[1][2] = v27[6];
  v63.M[1][3] = v27[7];
  if ( result_3 && (v10->VarsSet & 3) != 0 )
  {
    Scaleform::GFx::TextField::TransformToTextRectSpace(v9, (Scaleform::Render::Point<float> *)&result_4, v10);
    X = *(float *)&result_4;
    Y = *((float *)&result_4 + 1);
LABEL_63:
    v66 = Y;
    goto LABEL_64;
  }
  if ( (v10->VarsSet & 1) != 0 )
    X = v10->X;
  if ( (v10->VarsSet & 2) != 0 )
  {
    Y = v10->Y;
    goto LABEL_63;
  }
LABEL_64:
  LODWORD(sx) = v10->VarsSet;
  if ( (LOBYTE(sx) & 0x1C) != 0 )
  {
    Scaleform::Render::Matrix2x4<float>::operator=((Scaleform::Render::Matrix2x4<float> *)&v64, &v26->OrigMatrix);
    v64.M[0][3] = v63.M[0][3];
    v64.M[1][3] = v63.M[1][3];
    v70 = atan2(v64.M[1][0], v64.M[0][0]);
    result_4 = sqrt(v64.M[1][0] * v64.M[1][0] + v64.M[0][0] * v64.M[0][0]);
    v67 = sqrt(v64.M[1][1] * v64.M[1][1] + v64.M[0][1] * v64.M[0][1]);
    ZScale = v26->XScale / 100.0;
    v69 = v26->YScale / 100.0;
    FOV = v26->Rotation * 3.141592653589793 / 180.0;
    if ( (LOBYTE(sx) & 4) != 0 )
      Rotation = v10->Rotation;
    else
      Rotation = Scaleform::GFx::NumberUtil::NaN();
    sx = Rotation;
    if ( !Scaleform::GFx::NumberUtil::IsNaN(Rotation) )
    {
      v30 = fmod(sx, 360.0);
      if ( v30 <= 180.0 )
      {
        v34 = v30 > -180.0;
        v35 = -180.0 == v30;
        v33 = v30;
        v32 = 180.0;
        if ( !v34 && !v35 )
          v33 = v33 + 360.0;
      }
      else
      {
        v31 = v30;
        v32 = 180.0;
        v33 = v31 - 360.0;
      }
      v26->Rotation = v33;
      FOV = v33 * 3.141592653589793 / v32;
    }
    if ( (v10->VarsSet & 8) != 0 )
      v36 = v10->XScale / 100.0;
    else
      v36 = Scaleform::GFx::NumberUtil::NaN();
    sx = v36;
    if ( ZScale != v36 && !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(v36) )
    {
      v26->XScale = v10->XScale;
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
    if ( (v10->VarsSet & 0x10) != 0 )
      v37 = v10->YScale / 100.0;
    else
      v37 = Scaleform::GFx::NumberUtil::NaN();
    sx = v37;
    v38 = v69;
    if ( v69 == v37 )
      goto LABEL_91;
    if ( Scaleform::GFx::NumberUtil::IsNaNOrInfinity(v37) )
    {
      v39 = v69;
      goto LABEL_93;
    }
    v26->YScale = v10->YScale;
    v39 = 0.0;
    if ( 0.0 != v67 && (v38 = sx, sx <= 1.0e16) )
LABEL_91:
      v39 = v38;
    else
      v67 = 1.0;
LABEL_93:
    *(float *)&sx = FOV - v70;
    sy_4a = *(float *)&sx;
    *(float *)&sx = v39 / v67;
    sy = *(float *)&sx;
    *(float *)&sx = ZScale / result_4;
    Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
      (Scaleform::Render::Matrix2x4<float> *)&v64,
      *(float *)&sx,
      sy,
      sy_4a);
    v63.M[0][0] = v64.M[0][0];
    v63.M[0][1] = v64.M[0][1];
    v63.M[0][2] = v64.M[0][2];
    v63.M[0][3] = v64.M[0][3];
    v63.M[1][0] = v64.M[1][0];
    v63.M[1][1] = v64.M[1][1];
    v63.M[1][2] = v64.M[1][2];
    v63.M[1][3] = v64.M[1][3];
  }
  if ( (v10->VarsSet & 1) != 0 )
    v40 = X;
  else
    v40 = Scaleform::GFx::NumberUtil::NaN();
  result_4 = v40;
  if ( !Scaleform::GFx::NumberUtil::IsNaN(v40) )
  {
    FOV = result_4;
    if ( result_4 == -INFINITY || Scaleform::GFx::NumberUtil::IsPOSITIVE_INFINITY(result_4) )
      v41 = 0.0;
    else
      v41 = result_4;
    v42 = (int)floor(v41 * 20.0);
    LODWORD(sx) = v42;
    v26->X = v42;
    v63.M[0][3] = (float)v42;
  }
  if ( (v10->VarsSet & 2) != 0 )
    v43 = v66;
  else
    v43 = Scaleform::GFx::NumberUtil::NaN();
  result_4 = v43;
  if ( !Scaleform::GFx::NumberUtil::IsNaN(v43) )
  {
    FOV = result_4;
    if ( result_4 == -INFINITY || Scaleform::GFx::NumberUtil::IsPOSITIVE_INFINITY(result_4) )
      v44 = 0.0;
    else
      v44 = result_4;
    v45 = (int)floor(v44 * 20.0);
    LODWORD(sx) = v45;
    v26->Y = v45;
    v63.M[1][3] = (float)v45;
  }
  if ( Scaleform::Render::Matrix2x4<float>::IsValid(&v63) )
  {
    v46 = Scaleform::GFx::DisplayObjectBase::Has3D(v9);
    v47 = v9->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    if ( v46 )
      v47->UpdateTransform3D(v9);
    else
      v47->SetMatrix(v9, &v63);
  }
  if ( result_3 )
  {
    if ( (v10->VarsSet & 1) != 0 )
    {
      v48 = X * 20.0;
      if ( X * 20.0 <= 0.0 )
        v49 = v48 - 0.5;
      else
        v49 = v48 + 0.5;
      v26->X = (int)v49;
    }
    if ( (v10->VarsSet & 2) != 0 )
    {
      v50 = v66 * 20.0;
      if ( v66 * 20.0 <= 0.0 )
        v26->Y = (int)(v50 - 0.5);
      else
        v26->Y = (int)(v50 + 0.5);
    }
  }
LABEL_126:
  v51 = v68.Stats;
  if ( v68.Stats )
  {
    v52 = v68.Stats->__vftable;
    v53 = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v52->NativePopCallstack)(
      v51,
      v53 - LODWORD(v68.StartTicks),
      (v53 - v68.StartTicks) >> 32);
  }
  return 1;
}
