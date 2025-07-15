Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::MovieImpl::GetTopMostEntity(
        Scaleform::GFx::MovieImpl *this,
        const Scaleform::Render::Point<float> *mousePos,
        unsigned int controllerIdx,
        bool testAll,
        const Scaleform::GFx::InteractiveObject *ignoreMC)
{
  double v6; // st7
  double v7; // st6
  void (__thiscall *GetProjectionMatrix3D)(Scaleform::GFx::Movie *, Scaleform::Render::Matrix4x4<float> *); // edx
  Scaleform::GFx::MovieImpl_vtbl *v9; // eax
  void (__thiscall *GetViewMatrix3D)(Scaleform::GFx::Movie *, Scaleform::Render::Matrix3x4<float> *); // edx
  signed int v11; // eax
  double v12; // st7
  Scaleform::GFx::InteractiveObject *pObject; // edi
  Scaleform::GFx::DisplayObjectBase *pParent; // ecx
  Scaleform::GFx::InteractiveObject *v15; // eax
  signed int Size; // edi
  Scaleform::GFx::InteractiveObject *v17; // ecx
  float v18; // [esp+4D0h] [ebp-C4h]
  float v19; // [esp+4D0h] [ebp-C4h]
  float v20; // [esp+4D0h] [ebp-C4h]
  float v21; // [esp+4D0h] [ebp-C4h]
  signed int v22; // [esp+4D0h] [ebp-C4h]
  float v23; // [esp+4D4h] [ebp-C0h]
  int v24; // [esp+4D4h] [ebp-C0h]
  _DWORD v25[3]; // [esp+4D8h] [ebp-BCh] BYREF
  const Scaleform::GFx::InteractiveObject *v26; // [esp+4E4h] [ebp-B0h]
  int v27; // [esp+4E8h] [ebp-ACh]
  unsigned int v28; // [esp+4ECh] [ebp-A8h]
  float v29; // [esp+4F0h] [ebp-A4h]
  Scaleform::Render::Matrix2x4<float> pmat; // [esp+4F4h] [ebp-A0h] BYREF
  Scaleform::Render::Point<float> result; // [esp+51Ch] [ebp-78h] BYREF
  unsigned __int8 src[48]; // [esp+524h] [ebp-70h] BYREF
  unsigned __int8 dst[64]; // [esp+554h] [ebp-40h] BYREF

  v18 = this->ViewOffsetY * 20.0;
  v6 = mousePos->y - v18;
  v19 = this->VisibleFrameRect.y2 - this->VisibleFrameRect.y1;
  v23 = v6 / v19 * 2.0 - 1.0;
  v20 = 20.0 * this->ViewOffsetX;
  v7 = mousePos->x - v20;
  v21 = this->VisibleFrameRect.x2 - this->VisibleFrameRect.x1;
  this->ScreenToWorld.Sx = v7 / v21 * 2.0 - 1.0;
  this->ScreenToWorld.Sy = -v23;
  memset((int)dst, 0, sizeof(dst));
  GetProjectionMatrix3D = this->GetProjectionMatrix3D;
  *(float *)dst = 1.0;
  *(float *)&dst[20] = 1.0;
  *(float *)&dst[40] = 1.0;
  *(float *)&dst[60] = 1.0;
  GetProjectionMatrix3D(this, (Scaleform::Render::Matrix4x4<float> *)dst);
  memcpy((unsigned __int8 *)&this->ScreenToWorld.MatProj, dst, sizeof(this->ScreenToWorld.MatProj));
  memset((int)src, 0, sizeof(src));
  v9 = this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
  *(float *)src = 1.0;
  GetViewMatrix3D = v9->GetViewMatrix3D;
  *(float *)&src[20] = 1.0;
  *(float *)&src[40] = 1.0;
  GetViewMatrix3D(this, (Scaleform::Render::Matrix3x4<float> *)src);
  memcpy((unsigned __int8 *)&this->ScreenToWorld.MatView, src, sizeof(this->ScreenToWorld.MatView));
  v11 = this->TopmostLevelCharacters.Data.Size - 1;
  v24 = 0;
  v22 = v11;
  if ( v11 < 0 )
    goto LABEL_9;
  v12 = 0.0;
  while ( 1 )
  {
    pObject = this->TopmostLevelCharacters.Data.Data[v11].pObject;
    pParent = pObject->pParent;
    if ( pParent )
      break;
LABEL_6:
    v22 = --v11;
    if ( v11 < 0 )
      goto LABEL_9;
  }
  pmat.M[0][0] = 1.0;
  pmat.M[1][1] = 1.0;
  pmat.M[0][1] = v12;
  pmat.M[0][2] = v12;
  pmat.M[0][3] = v12;
  pmat.M[1][0] = v12;
  pmat.M[1][2] = v12;
  pmat.M[1][3] = v12;
  Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pParent, &pmat);
  Scaleform::Render::Matrix2x4<float>::TransformByInverse(&pmat, &result, mousePos);
  LOBYTE(v29) = testAll;
  v28 = controllerIdx;
  v26 = ignoreMC;
  v27 = 0;
  if ( pObject->GetTopMostMouseEntity(pObject, &result, (Scaleform::GFx::DisplayObjectBase::TopMostDescr *)v25) != TopMost_Found )
  {
    v12 = 0.0;
    v11 = v22;
    goto LABEL_6;
  }
  v15 = (Scaleform::GFx::InteractiveObject *)v25[0];
  v24 = v25[0];
  if ( !v25[0] )
  {
LABEL_9:
    Size = this->MovieLevels.Data.Size;
    if ( Size <= 0 )
    {
      return (Scaleform::GFx::InteractiveObject *)v24;
    }
    else
    {
      while ( 1 )
      {
        v17 = this->MovieLevels.Data.Data[Size - 1].pSprite.pObject;
        v26 = ignoreMC;
        v28 = controllerIdx;
        LOBYTE(v29) = testAll;
        v27 = 0;
        if ( v17->GetTopMostMouseEntity(v17, mousePos, (Scaleform::GFx::DisplayObjectBase::TopMostDescr *)v25) == TopMost_Found )
          break;
        if ( --Size <= 0 )
          return (Scaleform::GFx::InteractiveObject *)v24;
      }
      return (Scaleform::GFx::InteractiveObject *)v25[0];
    }
  }
  return v15;
}
