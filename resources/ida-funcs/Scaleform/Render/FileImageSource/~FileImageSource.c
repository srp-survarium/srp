void __thiscall Scaleform::Render::FileImageSource::~FileImageSource(Scaleform::Render::FileImageSource *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->__vftable = (Scaleform::Render::FileImageSource_vtbl *)&Scaleform::Render::FileImageSource::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->pFile.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
