Scaleform::Render::MeshProvider_KeySupport *__thiscall Scaleform::Render::MeshProvider_KeySupport::`vector deleting destructor'(
        Scaleform::Render::MeshProvider_KeySupport *this,
        char a2)
{
  this->Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::MeshProvider_KeySupport_vtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable'{for `Scaleform::Render::MeshProvider'};
  Scaleform::Render::MeshKeySetHandle::releaseCache(&this->hKeySet);
  this->Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::MeshProvider::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


void *__thiscall Scaleform::Render::MeshProvider_KeySupport::`vector deleting destructor'(char *this, unsigned int a2)
{
  return Scaleform::Render::MeshProvider_KeySupport::`vector deleting destructor'(
           (Scaleform::Render::MeshProvider_KeySupport *)(this - 8),
           a2);
}
