void __thiscall Scaleform::Render::ShapeMeshProvider::~ShapeMeshProvider(Scaleform::Render::ShapeMeshProvider *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v3; // ecx

  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::ShapeMeshProvider_vtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable'{for `Scaleform::Render::MeshProvider'};
  pObject = (Scaleform::RefCountVImpl *)this->pMorphData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v3 = (Scaleform::RefCountVImpl *)this->pShapeData.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->FillToStyleTable.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->DrawLayers.Data.Data);
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::ShapeMeshProvider_vtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable'{for `Scaleform::Render::MeshProvider'};
  Scaleform::Render::MeshKeySetHandle::releaseCache(&this->hKeySet);
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::MeshProvider::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
