Scaleform::Render::GradientImage *__thiscall Scaleform::Render::GradientImage::`scalar deleting destructor'(
        Scaleform::Render::GradientImage *this,
        char a2)
{
  Scaleform::Render::PrimitiveFillManager *pManager; // ecx
  Scaleform::RefCountVImpl *pObject; // ecx

  pManager = this->pManager;
  this->__vftable = (Scaleform::Render::GradientImage_vtbl *)&Scaleform::Render::GradientImage::`vftable';
  if ( pManager )
    Scaleform::Render::PrimitiveFillManager::removeGradient(pManager, this);
  pObject = (Scaleform::RefCountVImpl *)this->pData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::Render::Image::~Image(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
