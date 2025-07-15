Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::MovieImpl::GetTopMostEntity(
        Scaleform::GFx::MovieImpl *this,
        const Scaleform::Render::Point<float> *mousePos,
        float controllerIdx,
        bool testAll,
        const Scaleform::GFx::InteractiveObject *ignoreMC)
{
  double v6; // st7
  double v7; // st6
  void (__thiscall *GetProjectionMatrix3D)(Scaleform::GFx::Movie *, Scaleform::Render::Matrix4x4<float> *); // edx
  Scaleform::GFx::MovieImpl_vtbl *v9; // eax
  signed int v10; // eax
  double v11; // st7
  Scaleform::GFx::InteractiveObject *pObject; // edi
  Scaleform::GFx::DisplayObjectBase *pParent; // ecx
  signed int Size; // edi
  Scaleform::GFx::InteractiveObject *v15; // ecx
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  float v20; // [esp+1Ch] [ebp-D4h]
  float v21; // [esp+1Ch] [ebp-D4h]
  float v22; // [esp+1Ch] [ebp-D4h]
  float v23; // [esp+1Ch] [ebp-D4h]
  signed int v24; // [esp+1Ch] [ebp-D4h]
  float v25; // [esp+20h] [ebp-D0h]
  int v26; // [esp+20h] [ebp-D0h]
  _DWORD v27[3]; // [esp+24h] [ebp-CCh] BYREF
  const Scaleform::GFx::InteractiveObject *v28; // [esp+30h] [ebp-C0h]
  int v29; // [esp+34h] [ebp-BCh]
  float v30; // [esp+38h] [ebp-B8h]
  float v31; // [esp+3Ch] [ebp-B4h]
  Scaleform::Render::Matrix2x4<float> pmat; // [esp+40h] [ebp-B0h] BYREF
  Scaleform::AmpFunctionTimer v33; // [esp+68h] [ebp-88h] BYREF
  Scaleform::Render::Point<float> result; // [esp+78h] [ebp-78h] BYREF
  unsigned __int8 v35[48]; // [esp+80h] [ebp-70h] BYREF
  unsigned __int8 src[64]; // [esp+B0h] [ebp-40h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v33,
    this->AdvanceStats.pObject,
    "MovieImpl::GetTopMostEntity",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  v20 = this->ViewOffsetY * 20.0;
  v6 = mousePos->y - v20;
  v21 = this->VisibleFrameRect.y2 - this->VisibleFrameRect.y1;
  v25 = v6 / v21 * 2.0 - 1.0;
  v22 = 20.0 * this->ViewOffsetX;
  v7 = mousePos->x - v22;
  v23 = this->VisibleFrameRect.x2 - this->VisibleFrameRect.x1;
  this->ScreenToWorld.Sx = v7 / v23 * 2.0 - 1.0;
  this->ScreenToWorld.Sy = -v25;
  memset((int)src, 0, sizeof(src));
  GetProjectionMatrix3D = this->GetProjectionMatrix3D;
  *(float *)src = 1.0;
  *(float *)&src[20] = 1.0;
  *(float *)&src[40] = 1.0;
  *(float *)&src[60] = 1.0;
  GetProjectionMatrix3D(this, (Scaleform::Render::Matrix4x4<float> *)src);
  memcpy((int)&this->ScreenToWorld.MatProj, (const __m128i *)src, sizeof(this->ScreenToWorld.MatProj));
  memset((int)v35, 0, sizeof(v35));
  *(float *)v35 = 1.0;
  *(float *)&v35[20] = 1.0;
  v9 = this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
  *(float *)&v35[40] = 1.0;
  v9->GetViewMatrix3D(this, (Scaleform::Render::Matrix3x4<float> *)v35);
  memcpy((int)&this->ScreenToWorld.MatView, (const __m128i *)v35, sizeof(this->ScreenToWorld.MatView));
  v10 = this->TopmostLevelCharacters.Data.Size - 1;
  v26 = 0;
  v24 = v10;
  if ( v10 < 0 )
    goto LABEL_9;
  v11 = 0.0;
  while ( 1 )
  {
    pObject = this->TopmostLevelCharacters.Data.Data[v10].pObject;
    pParent = pObject->pParent;
    if ( pParent )
      break;
LABEL_6:
    v24 = --v10;
    if ( v10 < 0 )
      goto LABEL_9;
  }
  pmat.M[0][0] = 1.0;
  pmat.M[1][1] = 1.0;
  pmat.M[0][1] = v11;
  pmat.M[0][2] = v11;
  pmat.M[0][3] = v11;
  pmat.M[1][0] = v11;
  pmat.M[1][2] = v11;
  pmat.M[1][3] = v11;
  Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pParent, &pmat);
  Scaleform::Render::Matrix2x4<float>::TransformByInverse(&pmat, &result, mousePos);
  LOBYTE(v31) = testAll;
  v30 = controllerIdx;
  v28 = ignoreMC;
  v29 = 0;
  if ( pObject->GetTopMostMouseEntity(pObject, &result, (Scaleform::GFx::DisplayObjectBase::TopMostDescr *)v27) != TopMost_Found )
  {
    v11 = 0.0;
    v10 = v24;
    goto LABEL_6;
  }
  v26 = v27[0];
  if ( !v27[0] )
  {
LABEL_9:
    Size = this->MovieLevels.Data.Size;
    if ( Size > 0 )
    {
      while ( 1 )
      {
        v15 = this->MovieLevels.Data.Data[Size - 1].pSprite.pObject;
        v28 = ignoreMC;
        v30 = controllerIdx;
        LOBYTE(v31) = testAll;
        v29 = 0;
        if ( v15->GetTopMostMouseEntity(v15, mousePos, (Scaleform::GFx::DisplayObjectBase::TopMostDescr *)v27) == TopMost_Found )
          break;
        if ( --Size <= 0 )
          goto LABEL_14;
      }
      v26 = v27[0];
    }
  }
LABEL_14:
  Stats = v33.Stats;
  if ( v33.Stats )
  {
    p_NativePopCallstack = &v33.Stats->NativePopCallstack;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v33.StartTicks),
      (ProfileTicks - v33.StartTicks) >> 32);
  }
  return (Scaleform::GFx::InteractiveObject *)v26;
}
