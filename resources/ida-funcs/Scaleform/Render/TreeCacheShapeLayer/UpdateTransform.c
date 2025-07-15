void __thiscall Scaleform::Render::TreeCacheShapeLayer::UpdateTransform(
        Scaleform::Render::TreeCacheShapeLayer *this,
        __int64 nodeData,
        Scaleform::Render::TransformFlags flags)
{
  Scaleform::Render::TreeCacheShapeLayer_vtbl *v4; // eax
  const Scaleform::Render::Matrix4x4<float> *ViewProj; // eax
  unsigned __int16 v6; // cx
  unsigned int v7; // eax
  double v8; // st6
  double v9; // st6
  char v10; // [esp+2Bh] [ebp-5Dh]
  float v11; // [esp+2Ch] [ebp-5Ch] BYREF
  float v12; // [esp+30h] [ebp-58h]
  float v13; // [esp+34h] [ebp-54h]
  Scaleform::Render::Rect<float> cullRect; // [esp+38h] [ebp-50h] BYREF
  Scaleform::Render::Matrix2x4<float> mat; // [esp+48h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [esp+68h] [ebp-20h] BYREF

  cullRect.x1 = *(float *)HIDWORD(nodeData);
  cullRect.y1 = *(float *)(HIDWORD(nodeData) + 4);
  cullRect.x2 = *(float *)(HIDWORD(nodeData) + 8);
  cullRect.y2 = *(float *)(HIDWORD(nodeData) + 12);
  Scaleform::Render::TreeCacheNode::updateCulling(
    this,
    (const Scaleform::Render::TreeNode::NodeData *)nodeData,
    (const Scaleform::Render::TransformArgs *)HIDWORD(nodeData),
    &cullRect,
    (Scaleform::Render::TransformFlags)(flags | 0x20));
  v11 = *(float *)(nodeData + 132);
  v12 = *(float *)(nodeData + 136);
  v13 = *(float *)(nodeData + 140);
  this->SortParentBounds.x1 = *(float *)(nodeData + 128);
  this->SortParentBounds.y1 = v11;
  this->SortParentBounds.x2 = v12;
  this->SortParentBounds.y2 = v13;
  v4 = this->__vftable;
  this->Flags &= ~0x400u;
  v4->ComputeFinalMatrix(this, (const Scaleform::Render::TransformArgs *)HIDWORD(nodeData), flags);
  if ( (flags & 1) != 0 )
  {
    v12 = *(float *)&this->SorterShapeNode.pBundle.pObject;
    if ( v12 != 0.0 )
    {
      v11 = 0.0;
      v10 = 0;
      if ( (flags & 0x80u) != 0 && this->pRoot )
      {
        ViewProj = Scaleform::Render::TransformArgs::GetViewProj((Scaleform::Render::TransformArgs *)HIDWORD(nodeData));
        Scaleform::Render::TreeCacheShapeLayer::getShapeMatrixFrom3D(
          this,
          (const Scaleform::Render::TreeShape::NodeData *)nodeData,
          &mat,
          ViewProj);
      }
      else
      {
        mat.M[0][0] = *(float *)(HIDWORD(nodeData) + 160);
        mat.M[0][1] = *(float *)(HIDWORD(nodeData) + 164);
        mat.M[0][2] = *(float *)(HIDWORD(nodeData) + 168);
        mat.M[0][3] = *(float *)(HIDWORD(nodeData) + 172);
        mat.M[1][0] = *(float *)(HIDWORD(nodeData) + 176);
        mat.M[1][1] = *(float *)(HIDWORD(nodeData) + 180);
        mat.M[1][2] = *(float *)(HIDWORD(nodeData) + 184);
        mat.M[1][3] = *(float *)(HIDWORD(nodeData) + 188);
      }
      v6 = this->Flags;
      if ( (v6 & 0x40) != 0 )
        v7 = 2;
      else
        v7 = (v6 & 0xC) == 4;
      if ( (v6 & 0x80u) != 0 )
        v7 |= 8u;
      if ( Scaleform::Render::TreeCacheShapeLayer::updateMeshKey(
             this,
             this->pRenderer2D,
             *(Scaleform::Render::ShapeMeshProvider **)(nodeData + 144),
             *(float *)(nodeData + 148),
             &mat,
             v7,
             (unsigned int *)&v11) )
      {
        v10 = 1;
        if ( 0.0 != *(float *)(nodeData + 148) )
          Scaleform::Render::TreeCacheShapeLayer::updateTexture0Matrix(this);
      }
      if ( (this->M.pHandle->pHeader->Format & 0x10) == 0 && (LOBYTE(v11) & 7) == 3 )
      {
        Scaleform::Render::Matrix2x4<float>::operator=(
          &m,
          (const Scaleform::Render::Matrix2x4<float> *)(HIDWORD(nodeData) + 160));
        if ( m.M[0][3] >= 0.0 )
          v8 = 0.5;
        else
          v8 = -0.5;
        v11 = v8;
        v13 = m.M[0][3] + v11;
        v13 = floor(v13);
        m.M[0][3] = v13;
        if ( m.M[1][3] >= 0.0 )
          v9 = 0.5;
        else
          v9 = -0.5;
        v11 = v9;
        v13 = m.M[1][3] + v11;
        v13 = floor(v13);
        m.M[1][3] = v13;
        Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(&this->M, &m);
      }
      if ( v10 )
        (*(void (__thiscall **)(float, Scaleform::Render::BundleEntry *))(*(_DWORD *)LODWORD(v12) + 12))(
          COERCE_FLOAT(LODWORD(v12)),
          &this->SorterShapeNode);
    }
  }
}
