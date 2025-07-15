Scaleform::Render::JPEG::WrapperImageSource *__thiscall Scaleform::Render::JPEG::WrapperImageSource::`vector deleting destructor'(
        Scaleform::Render::JPEG::WrapperImageSource *this,
        char a2)
{
  Scaleform::Render::JPEG::Input *pOriginalInput; // ecx
  Scaleform::Render::JPEG::Input *v4; // ecx
  Scaleform::Render::Image *pObject; // ecx

  pOriginalInput = this->pOriginalInput;
  this->__vftable = (Scaleform::Render::JPEG::WrapperImageSource_vtbl *)&Scaleform::Render::JPEG::WrapperImageSource::`vftable';
  if ( pOriginalInput )
  {
    pOriginalInput->AbortImage(pOriginalInput);
    v4 = this->pOriginalInput;
    if ( v4 )
      ((void (__thiscall *)(Scaleform::Render::JPEG::Input *, int))v4->~Scaleform::Render::JPEG::Input)(v4, 1);
  }
  pObject = this->pDelegate.pObject;
  if ( pObject )
    pObject->Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
