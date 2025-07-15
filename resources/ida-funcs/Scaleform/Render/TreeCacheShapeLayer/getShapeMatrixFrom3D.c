void __thiscall Scaleform::Render::TreeCacheShapeLayer::getShapeMatrixFrom3D(
        Scaleform::Render::TreeCacheShapeLayer *this,
        const Scaleform::Render::TreeShape::NodeData *nd,
        Scaleform::Render::Matrix2x4<float> *mat,
        const Scaleform::Render::Matrix4x4<float> *viewProj)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // ecx
  const Scaleform::Render::Matrix3x4<float> *v6; // eax
  double v7; // st7
  float m_52; // [esp+1B8h] [ebp-ACh]
  float m_56; // [esp+1BCh] [ebp-A8h]
  float v10; // [esp+1D0h] [ebp-94h]
  float v11; // [esp+1D0h] [ebp-94h]
  float Scale; // [esp+1D0h] [ebp-94h]
  float v13; // [esp+1D0h] [ebp-94h]
  Scaleform::Render::Rect<float> v14; // [esp+1D4h] [ebp-90h] BYREF
  float src[6]; // [esp+1ECh] [ebp-78h] BYREF
  __m128 dest[2]; // [esp+204h] [ebp-60h] BYREF
  Scaleform::Render::Matrix4x4<float> v17; // [esp+224h] [ebp-40h] BYREF

  nd->pMeshProvider.pObject->GetIdentityBounds(&nd->pMeshProvider.pObject->Scaleform::Render::MeshProvider, &v14);
  pHeader = this->M.pHandle->pHeader;
  if ( (pHeader->Format & 0x10) != 0 )
    v6 = (const Scaleform::Render::Matrix3x4<float> *)(&pHeader[1].RefCount
                                                     + 4 * (unsigned __int8)byte_9B2B74[5 * (pHeader->Format & 0xF)]);
  else
    v6 = &Scaleform::Render::Matrix3x4<float>::Identity;
  Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v17, viewProj, v6);
  m_56 = (float)*(int *)((*(_DWORD *)(*(_DWORD *)(((int)this->pRoot->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode
                                                 & 0xFFFFF000)
                                                + 0x14)
                                    + 4
                                    * ((int)((int)&this->pRoot->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode[-1]
                                           - ((int)this->pRoot->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode
                                            & 0xFFFFF000))
                                     / 28)
                                    + 20)
                        & 0xFFFFFFFE)
                       + 180);
  m_52 = (float)*(int *)((*(_DWORD *)(*(_DWORD *)(((int)this->pRoot->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode
                                                 & 0xFFFFF000)
                                                + 0x14)
                                    + 4
                                    * ((int)((int)&this->pRoot->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode[-1]
                                           - ((int)this->pRoot->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode
                                            & 0xFFFFF000))
                                     / 28)
                                    + 20)
                        & 0xFFFFFFFE)
                       + 176);
  Scaleform::Render::Matrix4x4<float>::TransformHomogeneousAndScaleCorners(&v17, (__m128 *)&v14, m_52, m_56, dest);
  src[0] = v14.x1;
  src[1] = v14.y1;
  src[2] = v14.x2;
  src[4] = v14.x2;
  src[3] = v14.y1;
  src[5] = v14.y2;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(mat, src, dest[0].m128_f32);
  v10 = mat->M[0][0] * mat->M[1][1] - mat->M[1][0] * mat->M[0][1];
  v11 = fabs(v10);
  if ( v11 < 0.001 )
  {
    Scale = Scaleform::Render::Matrix2x4<float>::GetScale(mat);
    mat->M[0][0] = Scale;
    mat->M[0][1] = 0.0;
    mat->M[0][2] = 0.0;
    mat->M[0][3] = 0.0;
    mat->M[1][0] = 0.0;
    mat->M[1][2] = 0.0;
    mat->M[1][3] = 0.0;
    mat->M[1][1] = Scale;
  }
  if ( nd->pMeshProvider.pObject->DrawLayers.Data.Data[this->Layer].StrokeStyle )
  {
    v13 = Scaleform::Render::Matrix2x4<float>::GetScale(mat);
    if ( v13 >= 0.0049999999 )
      v7 = v13;
    else
      v7 = (float)0.0049999999;
    mat->M[0][0] = v7;
    mat->M[0][1] = 0.0;
    mat->M[0][2] = 0.0;
    mat->M[0][3] = 0.0;
    mat->M[1][0] = 0.0;
    mat->M[1][2] = 0.0;
    mat->M[1][3] = 0.0;
    mat->M[1][1] = v7;
  }
}
