int __thiscall Scaleform::Render::TreeCacheShapeLayer::calcMeshKey(
        Scaleform::Render::TreeCacheShapeLayer *this,
        Scaleform::Render::ShapeMeshProvider *pmeshProvider,
        const Scaleform::Render::Matrix2x4<float> *m,
        unsigned int drawLayer,
        Scaleform::Render::Rect<float> *keyData,
        Scaleform::Render::Scale9GridData *s9g,
        float morphRatio)
{
  Scaleform::Render::TreeCacheShapeLayer *v7; // esi
  unsigned int v8; // esi
  unsigned int State; // eax
  int v10; // eax
  Scaleform::Render::TreeCacheShapeLayer *v11; // ebx
  unsigned int v12; // eax
  int v13; // eax
  double v14; // st7
  const Scaleform::Render::Matrix2x4<float> *v15; // ebx
  int v16; // ebx
  Scaleform::Render::TreeNode *pNode; // eax
  char v19; // bl
  unsigned int StrokeStyle; // eax
  unsigned int flags; // [esp+14h] [ebp-50h]
  float flagsa; // [esp+14h] [ebp-50h]
  Scaleform::Render::TreeCacheShapeLayer *pParent; // [esp+18h] [ebp-4Ch]
  float v24; // [esp+18h] [ebp-4Ch]
  float v26; // [esp+20h] [ebp-44h]
  Scaleform::Render::StrokeStyleType s1; // [esp+24h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v28; // [esp+44h] [ebp-20h] BYREF

  v7 = this;
  flags = 1;
  if ( SLOBYTE(this->Flags) >= 0 )
    goto LABEL_17;
  pParent = this;
  if ( !this->pNode )
    pParent = (Scaleform::Render::TreeCacheShapeLayer *)this->pParent;
  v28.M[0][0] = 1.0;
  v28.M[1][1] = 1.0;
  v28.M[0][1] = 0.0;
  v28.M[0][2] = 0.0;
  v28.M[0][3] = 0.0;
  v28.M[1][0] = 0.0;
  v28.M[1][2] = 0.0;
  v28.M[1][3] = 0.0;
  if ( pParent )
  {
    while ( 1 )
    {
      v8 = *(_DWORD *)(*(_DWORD *)(((int)pParent->pNode & 0xFFFFF000) + 0x14)
                     + 4 * ((int)((int)&pParent->pNode[-1] - ((int)pParent->pNode & 0xFFFFF000)) / 28)
                     + 20)
         & 0xFFFFFFFE;
      State = Scaleform::Render::StateBag::GetState(
                (Scaleform::Render::StateBag *)(v8 + 64),
                State_VirtualKeyboardInterface);
      v10 = State ? *(_DWORD *)(State + 4) : 0;
      v11 = v10 ? (*(_DWORD *)(v10 + 12) != 2989 ? *(Scaleform::Render::TreeCacheShapeLayer **)(v10 + 12) : 0) : 0;
      v12 = Scaleform::Render::StateBag::GetState((Scaleform::Render::StateBag *)(v8 + 64), State_Log);
      if ( v12 )
        break;
      Scaleform::Render::Matrix2x4<float>::Append(&v28, (const Scaleform::Render::Matrix2x4<float> *)(v8 + 16));
      if ( !v11 )
        v11 = (Scaleform::Render::TreeCacheShapeLayer *)pParent->pParent;
      pParent = v11;
      if ( !v11 )
      {
        v7 = this;
        goto LABEL_17;
      }
    }
    v13 = *(_DWORD *)(v12 + 4);
    v14 = *(float *)(v13 + 16);
    v13 += 16;
    s1.Width = v14;
    v15 = m;
    s1.Units = *(float *)(v13 + 4);
    s1.Flags = *(unsigned int *)(v13 + 8);
    s1.Miter = *(float *)(v13 + 12);
    s9g->S9Rect.x1 = s1.Width;
    s9g->S9Rect.y1 = s1.Units;
    s9g->S9Rect.x2 = *(float *)&s1.Flags;
    s9g->S9Rect.y2 = s1.Miter;
    v24 = *(float *)(v8 + 116);
    flagsa = *(float *)(v8 + 120);
    v26 = *(float *)(v8 + 124);
    s9g->Bounds.x1 = *(float *)(v8 + 112);
    s9g->Bounds.y1 = v24;
    s9g->Bounds.x2 = flagsa;
    s9g->Bounds.y2 = v26;
    s9g->ShapeMtx = v28;
    s9g->Scale9Mtx = *(Scaleform::Render::Matrix2x4<float> *)(v8 + 16);
    s9g->ViewMtx = *m;
    Scaleform::Render::TreeNode::NodeData::contractByFilterBounds(
      (Scaleform::Render::TreeNode::NodeData *)v8,
      &s9g->Bounds);
    v7 = this;
    flags = 17;
  }
  else
  {
LABEL_17:
    v15 = m;
  }
  if ( (flags & 0x10) != 0 )
  {
    Scaleform::Render::Scale9GridData::MakeMeshKey(s9g, keyData);
LABEL_20:
    v16 = flags;
    goto LABEL_21;
  }
  v19 = Scaleform::Render::MeshKey::CalcMatrixKey(v15, &keyData->x1, 0);
  StrokeStyle = pmeshProvider->DrawLayers.Data.Data[drawLayer].StrokeStyle;
  if ( StrokeStyle )
  {
    flags = 2;
    s1.pFill.pObject = 0;
    s1.pDashes.pObject = 0;
    Scaleform::Render::ShapeMeshProvider::GetStrokeStyle(pmeshProvider, StrokeStyle, &s1, 0.0);
    if ( (s1.Flags & 1) != 0 )
      flags = 3;
    if ( (s1.Flags & 6) == 0 )
      flags |= 0x20u;
    if ( s1.pDashes.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)s1.pDashes.pObject);
    if ( s1.pFill.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)s1.pFill.pObject);
  }
  if ( v19 )
    goto LABEL_20;
  v16 = flags | 0x8000;
LABEL_21:
  pNode = v7->pNode;
  if ( !pNode )
    pNode = v7->pParent->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode;
  if ( *(_BYTE *)(*(_DWORD *)((*(_DWORD *)(*(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x14)
                                         + 4 * ((int)((int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000)) / 28)
                                         + 20)
                             & 0xFFFFFFFE)
                            + 144)
                + 80) )
    v16 |= 0x100u;
  *((float *)keyData + Scaleform::Render::MeshKey::GetKeySize(v16) - 1) = morphRatio;
  return v16;
}
