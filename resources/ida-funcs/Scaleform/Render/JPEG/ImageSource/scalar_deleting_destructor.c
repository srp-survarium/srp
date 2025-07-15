Scaleform::Render::JPEG::ImageSource *__thiscall Scaleform::Render::JPEG::ImageSource::`scalar deleting destructor'(
        Scaleform::Render::JPEG::ImageSource *this,
        char a2)
{
  Scaleform::Render::JPEG::Input *pOriginalInput; // ecx
  Scaleform::Render::JPEG::Input *v4; // ecx
  Scaleform::RefCountVImpl *pObject; // ecx

  pOriginalInput = this->pOriginalInput;
  this->__vftable = (Scaleform::Render::JPEG::ImageSource_vtbl *)&Scaleform::Render::JPEG::ImageSource::`vftable';
  if ( pOriginalInput )
  {
    pOriginalInput->AbortImage(pOriginalInput);
    v4 = this->pOriginalInput;
    if ( v4 )
      ((void (__thiscall *)(Scaleform::Render::JPEG::Input *, int))v4->~Scaleform::Render::JPEG::Input)(v4, 1);
  }
  pObject = (Scaleform::RefCountVImpl *)this->pExtraData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::Render::FileImageSource::~FileImageSource(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
