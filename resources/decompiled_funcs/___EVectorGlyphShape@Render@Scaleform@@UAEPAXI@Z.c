Scaleform::Render::VectorGlyphShape *__thiscall Scaleform::Render::VectorGlyphShape::`vector deleting destructor'(
        Scaleform::Render::VectorGlyphShape *this,
        char a2)
{
  Scaleform::Render::GlyphRaster *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx

  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::VectorGlyphShape_vtbl *)&Scaleform::Render::VectorGlyphShape::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::VectorGlyphShape::`vftable'{for `Scaleform::Render::MeshProvider'};
  pObject = this->pRaster.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v4 = (Scaleform::RefCountVImpl *)this->pShape.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::VectorGlyphShape_vtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable'{for `Scaleform::Render::MeshProvider'};
  Scaleform::Render::MeshKeySetHandle::releaseCache(&this->hKeySet);
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::MeshProvider::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
