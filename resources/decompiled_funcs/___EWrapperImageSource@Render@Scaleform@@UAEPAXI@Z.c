Scaleform::Render::WrapperImageSource *__thiscall Scaleform::Render::WrapperImageSource::`vector deleting destructor'(
        Scaleform::Render::WrapperImageSource *this,
        char a2)
{
  Scaleform::Render::Image *pObject; // ecx

  pObject = this->pDelegate.pObject;
  if ( pObject )
    pObject->Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
