void __thiscall Scaleform::Render::TreeCacheShapeLayer::UpdateTransform(
        Scaleform::Render::TreeCacheShapeLayer *this,
        const Scaleform::Render::TreeShape::NodeData *nodeData,
        const Scaleform::Render::TransformArgs *t,
        Scaleform::Render::TransformFlags flags)
{
  Scaleform::Render::TreeCacheShapeLayer_vtbl *v5; // eax
  const Scaleform::Render::Matrix4x4<float> *ViewProj; // eax
  unsigned __int16 v7; // cx
  unsigned int v8; // eax
  double v9; // st6
  double v10; // st6
  char v11; // [esp+1D1h] [ebp-5Dh]
  unsigned int y1_low; // [esp+1D2h] [ebp-5Ch] BYREF
  float x2; // [esp+1D6h] [ebp-58h]
  float y2; // [esp+1DAh] [ebp-54h]
  Scaleform::Render::Rect<float> v15; // [esp+1DEh] [ebp-50h] BYREF
  Scaleform::Render::Matrix2x4<float> viewMatrix; // [esp+1EEh] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [esp+20Eh] [ebp-20h] BYREF

  v15.x1 = t->CullRect.x1;
  v15.y1 = t->CullRect.y1;
  v15.x2 = t->CullRect.x2;
  v15.y2 = t->CullRect.y2;
  Scaleform::Render::TreeCacheNode::updateCulling(
    this,
    nodeData,
    t,
    &v15,
    (Scaleform::Render::TransformFlags)(flags | 0x20));
  y1_low = LODWORD(nodeData->AproxParentBounds.y1);
  x2 = nodeData->AproxParentBounds.x2;
  y2 = nodeData->AproxParentBounds.y2;
  this->SortParentBounds.x1 = nodeData->AproxParentBounds.x1;
  this->SortParentBounds.y1 = *(float *)&y1_low;
  this->SortParentBounds.x2 = x2;
  this->SortParentBounds.y2 = y2;
  v5 = this->__vftable;
  this->Flags &= ~0x400u;
  v5->ComputeFinalMatrix(this, t, flags);
  if ( (flags & 1) != 0 )
  {
    x2 = *(float *)&this->SorterShapeNode.pBundle.pObject;
    if ( x2 != 0.0 )
    {
      *(float *)&y1_low = 0.0;
      v11 = 0;
      if ( (flags & 0x80u) != 0 && this->pRoot )
      {
        ViewProj = Scaleform::Render::TransformArgs::GetViewProj(t);
        Scaleform::Render::TreeCacheShapeLayer::getShapeMatrixFrom3D(this, nodeData, &viewMatrix, ViewProj);
      }
      else
      {
        viewMatrix.M[0][0] = t->Mat.M[0][0];
        viewMatrix.M[0][1] = t->Mat.M[0][1];
        viewMatrix.M[0][2] = t->Mat.M[0][2];
        viewMatrix.M[0][3] = t->Mat.M[0][3];
        viewMatrix.M[1][0] = t->Mat.M[1][0];
        viewMatrix.M[1][1] = t->Mat.M[1][1];
        viewMatrix.M[1][2] = t->Mat.M[1][2];
        viewMatrix.M[1][3] = t->Mat.M[1][3];
      }
      v7 = this->Flags;
      if ( (v7 & 0x40) != 0 )
        v8 = 2;
      else
        v8 = (v7 & 0xC) == 4;
      if ( (v7 & 0x80u) != 0 )
        v8 |= 8u;
      if ( Scaleform::Render::TreeCacheShapeLayer::updateMeshKey(
             this,
             this->pRenderer2D,
             nodeData->pMeshProvider.pObject,
             nodeData->MorphRatio,
             &viewMatrix,
             v8,
             &y1_low) )
      {
        v11 = 1;
        if ( 0.0 != nodeData->MorphRatio )
          Scaleform::Render::TreeCacheShapeLayer::updateTexture0Matrix(this);
      }
      if ( (this->M.pHandle->pHeader->Format & 0x10) == 0 && (y1_low & 7) == 3 )
      {
        Scaleform::Render::Matrix2x4<float>::operator=(&m, &t->Mat);
        if ( m.M[0][3] >= 0.0 )
          v9 = 0.5;
        else
          v9 = -0.5;
        *(float *)&y1_low = v9;
        y2 = m.M[0][3] + *(float *)&y1_low;
        y2 = floor(y2);
        m.M[0][3] = y2;
        if ( m.M[1][3] >= 0.0 )
          v10 = 0.5;
        else
          v10 = -0.5;
        *(float *)&y1_low = v10;
        y2 = m.M[1][3] + *(float *)&y1_low;
        y2 = floor(y2);
        m.M[1][3] = y2;
        Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(&this->M, &m);
      }
      if ( v11 )
        (*(void (__thiscall **)(float, Scaleform::Render::BundleEntry *))(*(_DWORD *)LODWORD(x2) + 12))(
          COERCE_FLOAT(LODWORD(x2)),
          &this->SorterShapeNode);
    }
  }
}
