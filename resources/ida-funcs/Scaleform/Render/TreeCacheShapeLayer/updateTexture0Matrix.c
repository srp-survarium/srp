void __thiscall Scaleform::Render::TreeCacheShapeLayer::updateTexture0Matrix(
        Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::Render::ShapeMeshProvider *MeshProvider; // eax
  Scaleform::Render::MeshProvider_vtbl *v4; // ebx
  Scaleform::Render::MeshProvider *v5; // edi
  unsigned int v6; // eax
  Scaleform::Render::Matrix2x4<float> m; // [esp+30h] [ebp-20h] BYREF

  if ( !this->ComplexShape )
  {
    pObject = this->SorterShapeNode.pBundle.pObject;
    if ( pObject )
    {
      if ( *(_DWORD *)(*(_DWORD *)&pObject[1].NeedUpdate + 20) )
      {
        m.M[0][0] = 1.0;
        m.M[0][1] = 0.0;
        m.M[0][2] = 0.0;
        m.M[0][3] = 0.0;
        m.M[1][0] = 0.0;
        m.M[1][2] = 0.0;
        m.M[1][3] = 0.0;
        m.M[1][1] = 1.0;
        MeshProvider = Scaleform::Render::TreeCacheShapeLayer::GetMeshProvider(this);
        v4 = MeshProvider->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable;
        v5 = &MeshProvider->Scaleform::Render::MeshProvider;
        v6 = Scaleform::Render::TreeCacheShapeLayer::calcMeshGenFlags(this);
        v4->GetFillMatrix(v5, this->pMeshKey.pObject->pMesh.pObject, &m, this->Layer, 0, v6);
        Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(&this->M, &m, Element_Cxform);
      }
    }
  }
}
