void __thiscall Scaleform::Render::TreeCacheShapeLayer::RemoveMesh(Scaleform::Render::TreeCacheShapeLayer *this)
{
  Scaleform::Render::MeshKey *pObject; // ecx

  pObject = this->pMeshKey.pObject;
  if ( pObject )
    Scaleform::Render::MeshKey::Release(pObject);
  this->pMeshKey.pObject = 0;
}
