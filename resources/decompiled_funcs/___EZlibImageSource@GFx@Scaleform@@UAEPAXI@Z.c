Scaleform::GFx::ZlibImageSource *__thiscall Scaleform::GFx::ZlibImageSource::`vector deleting destructor'(
        Scaleform::GFx::ZlibImageSource *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->__vftable = (Scaleform::GFx::ZlibImageSource_vtbl *)&Scaleform::GFx::ZlibImageSource::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->Zlib.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::Render::FileImageSource::~FileImageSource(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
