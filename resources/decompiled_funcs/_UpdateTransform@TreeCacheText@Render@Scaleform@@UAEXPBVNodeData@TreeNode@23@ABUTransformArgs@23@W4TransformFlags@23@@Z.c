void __thiscall Scaleform::Render::TreeCacheText::UpdateTransform(
        Scaleform::Render::TreeCacheText *this,
        const Scaleform::Render::TreeNode::NodeData *nodeData,
        const Scaleform::Render::TransformArgs *t,
        Scaleform::Render::TransformFlags flags)
{
  Scaleform::Render::TreeCacheText_vtbl *v5; // eax
  unsigned int v6; // eax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v7; // edi
  double v8; // st6
  double v9; // st6
  Scaleform::Render::Bundle *v10; // edi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v11; // ecx
  const Scaleform::Render::Matrix4x4<float> *ViewProj; // eax
  unsigned __int16 v13; // ax
  Scaleform::Render::TextMeshLayer *v14; // esi
  unsigned int Start; // eax
  Scaleform::Render::Renderer2DImpl *pRenderer2D; // ecx
  const Scaleform::Render::TextMeshEntry *v17; // eax
  unsigned int v18; // eax
  Scaleform::Render::MeshKey *pObject; // ecx
  Scaleform::Render::Renderer2DImpl *v20; // eax
  const Scaleform::Render::ToleranceParams *p_Tolerances; // edi
  Scaleform::Render::MeshKey *MatchingKey; // eax
  Scaleform::Render::MeshKey *v23; // ecx
  Scaleform::Render::MeshKey *v24; // edi
  Scaleform::Render::Mesh *v25; // eax
  unsigned int v26; // eax
  Scaleform::Render::MeshKey *v27; // edi
  Scaleform::RefCountVImpl *v28; // ecx
  unsigned int *p_pMesh; // edi
  Scaleform::Render::MeshKey *v30; // eax
  Scaleform::Render::Mesh *v31; // edi
  Scaleform::RefCountVImpl *v32; // ecx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax
  float y1; // [esp+6ECh] [ebp-C8h]
  float v35; // [esp+6ECh] [ebp-C8h]
  float v36; // [esp+6ECh] [ebp-C8h]
  float v37; // [esp+6ECh] [ebp-C8h]
  float v38; // [esp+6ECh] [ebp-C8h]
  unsigned int v39; // [esp+6ECh] [ebp-C8h]
  float y2; // [esp+6F0h] [ebp-C4h]
  float v41; // [esp+6F0h] [ebp-C4h]
  float v42; // [esp+6F0h] [ebp-C4h]
  int v43; // [esp+6F0h] [ebp-C4h]
  float x2; // [esp+6F4h] [ebp-C0h]
  unsigned int v45; // [esp+6F4h] [ebp-C0h]
  float v46; // [esp+6F4h] [ebp-C0h]
  unsigned int v47; // [esp+6F4h] [ebp-C0h]
  unsigned int v48; // [esp+6F4h] [ebp-C0h]
  unsigned int meshGenFlags; // [esp+6F8h] [ebp-BCh]
  Scaleform::Render::MeshKeyManager *v50; // [esp+6FCh] [ebp-B8h] BYREF
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [esp+700h] [ebp-B4h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [esp+704h] [ebp-B0h] BYREF
  Scaleform::Render::Rect<float> v53; // [esp+724h] [ebp-90h] BYREF
  Scaleform::Render::Viewport v54; // [esp+738h] [ebp-7Ch] BYREF
  Scaleform::Render::Matrix4x4<float> dst; // [esp+764h] [ebp-50h] BYREF

  v53.x1 = t->CullRect.x1;
  v53.y1 = t->CullRect.y1;
  v53.x2 = t->CullRect.x2;
  v53.y2 = t->CullRect.y2;
  Scaleform::Render::TreeCacheNode::updateCulling(
    this,
    nodeData,
    t,
    &v53,
    (Scaleform::Render::TransformFlags)(flags | 0x20));
  y1 = nodeData->AproxParentBounds.y1;
  x2 = nodeData->AproxParentBounds.x2;
  y2 = nodeData->AproxParentBounds.y2;
  this->SortParentBounds.x1 = nodeData->AproxParentBounds.x1;
  this->SortParentBounds.y1 = y1;
  this->SortParentBounds.x2 = x2;
  this->SortParentBounds.y2 = y2;
  v5 = this->__vftable;
  this->Flags &= ~0x400u;
  v5->ComputeFinalMatrix(this, t, flags);
  v6 = *(_DWORD *)((*(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                              + 4 * ((int)((int)&this->pNode[-1] - ((int)this->pNode & 0xFFFFF000)) / 28)
                              + 20)
                  & 0xFFFFFFFE)
                 + 148);
  v45 = v6;
  result.pHandle = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)(flags & 1);
  if ( (flags & 1) == 0 )
  {
LABEL_19:
    if ( (this->TMProvider.Flags & 0x40) != 0 )
    {
      v13 = this->Flags;
      if ( (v13 & 0x40) != 0 )
        meshGenFlags = 2;
      else
        meshGenFlags = (v13 & 0xC) == 4;
      if ( (v13 & 0x80u) != 0 )
        meshGenFlags |= 8u;
      v39 = 0;
      if ( this->TMProvider.GetLayerCount(&this->TMProvider) )
      {
        v43 = 0;
        do
        {
          v14 = &this->TMProvider.Layers.Data.Data[v43];
          if ( v14->Type == TextLayer_Shapes || v14->Type == TextLayer_Shapes_Masked )
          {
            Start = v14->Start;
            pRenderer2D = this->pRenderer2D;
            v46 = this->TMProvider.HeightRatio * v14->SizeScale;
            m.M[0][0] = v46;
            m.M[0][1] = 0.0;
            m.M[0][2] = 0.0;
            m.M[0][3] = 0.0;
            v17 = &this->TMProvider.Entries.Data.Data[Start];
            m.M[1][0] = 0.0;
            m.M[1][2] = 0.0;
            m.M[1][3] = 0.0;
            m.M[1][1] = v46;
            v18 = Scaleform::Render::TextMeshProvider::CalcVectorParams(
                    v14,
                    v17,
                    &m,
                    v14->SizeScale,
                    &this->M,
                    pRenderer2D,
                    meshGenFlags,
                    (float *)&dst);
            pObject = v14->pMeshKey.pObject;
            v47 = v18;
            v20 = this->pRenderer2D;
            v50 = v20->pMeshKeyManager.pObject;
            p_Tolerances = &v20->Tolerances;
            if ( !pObject
              || !Scaleform::Render::MeshKey::Match(pObject, 0, flags, (const float *)&dst, &v20->Tolerances) )
            {
              MatchingKey = Scaleform::Render::MeshKeyManager::CreateMatchingKey(
                              v50,
                              v14->pShape.pObject,
                              0,
                              v47,
                              (float *)&dst,
                              p_Tolerances);
              v23 = v14->pMeshKey.pObject;
              v24 = MatchingKey;
              if ( v23 )
                Scaleform::Render::MeshKey::Release(v23);
              v14->pMeshKey.pObject = v24;
              if ( !v24->pMesh.pObject )
              {
                v50 = (Scaleform::Render::MeshKeyManager *)70;
                v25 = (Scaleform::Render::Mesh *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   this,
                                                   176,
                                                   &v50);
                if ( v25 )
                {
                  Scaleform::Render::Mesh::Mesh(
                    v25,
                    this->pRenderer2D,
                    v14->pMeshKey.pObject->pKeySet,
                    &m,
                    0.0,
                    0,
                    meshGenFlags);
                  v48 = v26;
                }
                else
                {
                  v48 = 0;
                }
                v27 = v14->pMeshKey.pObject;
                v28 = (Scaleform::RefCountVImpl *)v27->pMesh.pObject;
                p_pMesh = (unsigned int *)&v27->pMesh;
                if ( v28 )
                  Scaleform::RefCountImpl::Release(v28);
                *p_pMesh = v48;
              }
              v30 = v14->pMeshKey.pObject;
              v31 = (Scaleform::Render::Mesh *)v30->pMesh.pObject;
              if ( v31 )
                Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v30->pMesh.pObject);
              v32 = (Scaleform::RefCountVImpl *)v14->pMesh.pObject;
              if ( v32 )
                Scaleform::RefCountImpl::Release(v32);
              v14->pMesh.pObject = v31;
            }
          }
          ++v43;
          ++v39;
        }
        while ( v39 < this->TMProvider.GetLayerCount(&this->TMProvider) );
      }
    }
    if ( result.pHandle && (this->TMProvider.Flags & 0x100) != 0 )
    {
      pHandle = this->M.pHandle;
      if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
        ++pHandle->pHeader->RefCount;
      Scaleform::Render::TextMeshProvider::UpdateMaskClearBounds(
        &this->TMProvider,
        &result,
        (Scaleform::Render::MatrixPoolImpl::HMatrix)pHandle);
      if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
        Scaleform::Render::MatrixPoolImpl::DataHeader::Release(result.pHandle->pHeader);
    }
    return;
  }
  if ( (*(_BYTE *)(v6 + 16) & 1) != 0 )
  {
    v7 = this->M.pHandle;
    if ( (v7->pHeader->Format & 0x10) == 0
      && !Scaleform::Render::Matrix2x4<float>::IsFreeRotation(
            (Scaleform::Render::Matrix2x4<float> *)(&v7->pHeader[1].RefCount
                                                  + 4 * (unsigned __int8)byte_9B2B74[5 * (v7->pHeader->Format & 0xF)]),
            0.000001) )
    {
      Scaleform::Render::Matrix2x4<float>::operator=(
        &m,
        (const Scaleform::Render::Matrix2x4<float> *)(&v7->pHeader[1].RefCount
                                                    + 4 * (unsigned __int8)byte_9B2B74[5 * (v7->pHeader->Format & 0xF)]));
      if ( m.M[0][3] >= 0.0 )
        v8 = 0.5;
      else
        v8 = -0.5;
      v41 = v8;
      v35 = m.M[0][3] + v41;
      v36 = floor(v35);
      m.M[0][3] = v36;
      if ( m.M[1][3] >= 0.0 )
        v9 = 0.5;
      else
        v9 = -0.5;
      v42 = v9;
      v37 = m.M[1][3] + v42;
      v38 = floor(v37);
      m.M[1][3] = v38;
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(&this->M, &m);
    }
  }
  v10 = this->SorterShapeNode.pBundle.pObject;
  if ( v10 && (this->TMProvider.Flags & 0x20) != 0 )
  {
    memset((int)&dst, 0, sizeof(dst));
    dst.M[0][0] = 1.0;
    dst.M[1][1] = 1.0;
    v54.Height = 1;
    dst.M[2][2] = 1.0;
    v54.Width = 1;
    dst.M[3][3] = 1.0;
    v11 = this->M.pHandle;
    memset(&v54, 0, 16);
    memset(&v54.ScissorLeft, 0, 20);
    if ( (v11->pHeader->Format & 0x10) != 0 && this->pRoot )
    {
      ViewProj = Scaleform::Render::TransformArgs::GetViewProj(t);
      Scaleform::Render::TreeCacheText::getMatrix4F(this, &dst, ViewProj);
      qmemcpy(&v54, &Scaleform::Render::TreeCacheNode::GetNodeData(this->pRoot)[1].M34, sizeof(v54));
    }
    if ( Scaleform::Render::TextMeshProvider::NeedsUpdate(
           &this->TMProvider,
           &this->M,
           &dst,
           &v54,
           (const Scaleform::Render::TextFieldParam *)(v45 + 8)) )
    {
      v10->UpdateMesh(v10, &this->SorterShapeNode);
      Scaleform::Render::TextMeshProvider::Clear(&this->TMProvider);
      return;
    }
    goto LABEL_19;
  }
}
