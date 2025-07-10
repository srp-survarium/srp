Scaleform::Render::DepthStencilSurface *__thiscall Scaleform::Render::DepthStencilSurface::`scalar deleting destructor'(
        Scaleform::Render::DepthStencilSurface *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pManagerLocks.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
