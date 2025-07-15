void __thiscall Scaleform::Render::TreeCacheShapeLayer::TreeCacheShapeLayer(
        Scaleform::Render::TreeCacheShapeLayer *this,
        Scaleform::Render::TreeShape *node,
        const Scaleform::Render::SortKey *key,
        unsigned int drawLayer,
        Scaleform::Render::Renderer2DImpl *prenderer2D,
        unsigned int flags)
{
  Scaleform::Render::TreeCacheMeshBase::TreeCacheMeshBase(this, node, key, prenderer2D, flags);
  this->__vftable = (Scaleform::Render::TreeCacheShapeLayer_vtbl *)&Scaleform::Render::TreeCacheShapeLayer::`vftable';
  this->pMeshKey.pObject = 0;
  this->pGradient.pObject = 0;
  this->ComplexShape = key->pImpl->Type == SortKey_MeshProvider;
  this->Layer = drawLayer;
}
