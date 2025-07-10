void __thiscall Scaleform::Render::TextMeshLayer::~TextMeshLayer(Scaleform::Render::TextMeshLayer *this)
{
  Scaleform::Render::PrimitiveFill *pObject; // ecx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax
  Scaleform::Render::VectorGlyphShape *v4; // eax
  Scaleform::Render::MeshKey *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx

  pObject = this->pFill.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  pHandle = this->M.pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release(pHandle->pHeader);
  v4 = this->pShape.pObject;
  if ( v4 )
    v4->Release(&v4->Scaleform::Render::MeshProvider);
  v5 = this->pMeshKey.pObject;
  if ( v5 )
    Scaleform::Render::MeshKey::Release(v5);
  v6 = (Scaleform::RefCountVImpl *)this->pMesh.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
}
