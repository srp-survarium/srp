Scaleform::Render::FileImageSource *__thiscall Scaleform::Render::FileImageSource::`scalar deleting destructor'(
        Scaleform::Render::FileImageSource *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->__vftable = (Scaleform::Render::FileImageSource_vtbl *)&Scaleform::Render::FileImageSource::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->pFile.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
