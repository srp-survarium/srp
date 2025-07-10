Scaleform::GFx::ImageCreator *__thiscall Scaleform::GFx::ImageCreator::`vector deleting destructor'(
        Scaleform::GFx::ImageCreator *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pTextureManager.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->__vftable = (Scaleform::GFx::ImageCreator_vtbl *)&Scaleform::GFx::State::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
