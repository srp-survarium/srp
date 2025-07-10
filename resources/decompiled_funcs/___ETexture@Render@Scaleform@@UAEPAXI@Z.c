Scaleform::Render::Texture *__thiscall Scaleform::Render::Texture::`vector deleting destructor'(
        Scaleform::Render::Texture *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->__vftable = (Scaleform::Render::Texture_vtbl *)&Scaleform::Render::Texture::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->pManagerLocks.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
