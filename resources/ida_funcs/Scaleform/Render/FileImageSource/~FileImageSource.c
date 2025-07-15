void __thiscall Scaleform::Render::FileImageSource::~FileImageSource(Scaleform::Render::FileImageSource *this)
{
  Scaleform::File *pObject; // ecx

  this->__vftable = (Scaleform::Render::FileImageSource_vtbl *)&Scaleform::Render::FileImageSource::`vftable';
  pObject = this->pFile.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
