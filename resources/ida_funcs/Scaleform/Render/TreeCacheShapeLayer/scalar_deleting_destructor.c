Scaleform::Render::TreeCacheShapeLayer *__thiscall Scaleform::Render::TreeCacheShapeLayer::`scalar deleting destructor'(
        Scaleform::Render::TreeCacheShapeLayer *this,
        char a2)
{
  Scaleform::Render::Image *pObject; // ecx
  Scaleform::Render::MeshKey *v4; // ecx

  this->__vftable = (Scaleform::Render::TreeCacheShapeLayer_vtbl *)&Scaleform::Render::TreeCacheShapeLayer::`vftable';
  pObject = this->pGradient.pObject;
  if ( pObject )
    pObject->Release(pObject);
  v4 = this->pMeshKey.pObject;
  if ( v4 )
    Scaleform::Render::MeshKey::Release(v4);
  Scaleform::Render::TreeCacheMeshBase::~TreeCacheMeshBase(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
