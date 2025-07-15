Scaleform::GFx::AMP::MessageImageData *__thiscall Scaleform::GFx::AMP::MessageImageData::`vector deleting destructor'(
        Scaleform::GFx::AMP::MessageImageData *this,
        char a2)
{
  Scaleform::RefCountVImpl *ImageDataStream; // ecx

  ImageDataStream = (Scaleform::RefCountVImpl *)this->ImageDataStream;
  this->__vftable = (Scaleform::GFx::AMP::MessageImageData_vtbl *)&Scaleform::GFx::AMP::MessageImageData::`vftable';
  Scaleform::RefCountImpl::Release(ImageDataStream);
  this->__vftable = (Scaleform::GFx::AMP::MessageImageData_vtbl *)&Scaleform::GFx::AMP::Message::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
