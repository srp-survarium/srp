Scaleform::Render::MeshBase *__thiscall Scaleform::Render::TreeCacheShapeLayer::GetMesh(
        Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::MeshKey *pObject; // eax
  unsigned __int16 Flags; // ax
  unsigned int v4; // edi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // edx
  const Scaleform::Render::TreeShape::NodeData *ShapeNodeData; // eax
  float *v7; // eax
  Scaleform::Render::ShapeMeshProvider *MeshProvider; // eax
  Scaleform::Render::Bundle *v9; // eax
  Scaleform::Render::ShapeMeshProvider *v10; // eax
  Scaleform::Render::MeshKey *v11; // esi
  float MorphRatio; // [esp+0h] [ebp-80h]
  Scaleform::Render::Matrix2x4<float> mat; // [esp+20h] [ebp-60h] BYREF
  Scaleform::Render::Matrix4x4<float> result; // [esp+40h] [ebp-40h] BYREF

  if ( this->pRoot )
  {
    pObject = this->pMeshKey.pObject;
    if ( !pObject || !pObject->pMesh.pObject )
    {
      Flags = this->Flags;
      if ( (Flags & 0x40) != 0 )
        v4 = 2;
      else
        v4 = (Flags & 0xC) == 4;
      if ( (Flags & 0x80u) != 0 )
        v4 |= 8u;
      pHandle = this->M.pHandle;
      if ( (pHandle->pHeader->Format & 0x10) != 0 )
      {
        Scaleform::Render::TreeCacheNode::GetViewProj(this, &result);
        ShapeNodeData = Scaleform::Render::TreeCacheShapeLayer::GetShapeNodeData(this);
        Scaleform::Render::TreeCacheShapeLayer::getShapeMatrixFrom3D(this, ShapeNodeData, &mat, &result);
      }
      else
      {
        v7 = (float *)(&pHandle->pHeader[1].RefCount
                     + 4 * (unsigned __int8)byte_874214[5 * (pHandle->pHeader->Format & 0xF)]);
        mat.M[0][0] = *v7;
        mat.M[0][1] = v7[1];
        mat.M[0][2] = v7[2];
        mat.M[0][3] = v7[3];
        mat.M[1][0] = v7[4];
        mat.M[1][1] = v7[5];
        mat.M[1][2] = v7[6];
        mat.M[1][3] = v7[7];
      }
      MorphRatio = Scaleform::Render::TreeCacheShapeLayer::GetMorphRatio(this);
      MeshProvider = Scaleform::Render::TreeCacheShapeLayer::GetMeshProvider(this);
      Scaleform::Render::TreeCacheShapeLayer::updateMeshKey(
        this,
        this->pRenderer2D,
        MeshProvider,
        MorphRatio,
        &mat,
        v4,
        0);
      if ( !this->ComplexShape )
      {
        v9 = this->SorterShapeNode.pBundle.pObject;
        if ( v9 )
        {
          if ( *(_DWORD *)(*(_DWORD *)&v9[1].NeedUpdate + 20) )
          {
            result.M[0][0] = 1.0;
            result.M[0][1] = 0.0;
            result.M[0][2] = 0.0;
            result.M[0][3] = 0.0;
            result.M[1][0] = 0.0;
            result.M[1][2] = 0.0;
            result.M[1][3] = 0.0;
            result.M[1][1] = 1.0;
            v10 = Scaleform::Render::TreeCacheShapeLayer::GetMeshProvider(this);
            v10->GetFillMatrix(
              &v10->Scaleform::Render::MeshProvider,
              this->pMeshKey.pObject->pMesh.pObject,
              (Scaleform::Render::Matrix2x4<float> *)&result,
              this->Layer,
              0,
              v4);
            Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(
              &this->M,
              (const Scaleform::Render::Matrix2x4<float> *)&result,
              0);
          }
        }
      }
    }
  }
  v11 = this->pMeshKey.pObject;
  if ( v11 )
    return v11->pMesh.pObject;
  else
    return 0;
}
