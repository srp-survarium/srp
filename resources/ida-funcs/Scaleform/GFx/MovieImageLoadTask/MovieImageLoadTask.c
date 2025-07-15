void __thiscall Scaleform::GFx::MovieImageLoadTask::MovieImageLoadTask(
        Scaleform::GFx::MovieImageLoadTask *this,
        Scaleform::GFx::MovieDataDef *pdef,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        Scaleform::GFx::Resource *pin,
        Scaleform::GFx::FileTypeConstants::FileFormatType format,
        Scaleform::GFx::Resource *pls)
{
  Scaleform::GFx::LoaderTask::LoaderTask(this, pls, Id_MovieImageLoad);
  this->__vftable = (Scaleform::GFx::MovieImageLoadTask_vtbl *)&Scaleform::GFx::MovieImageLoadTask::`vftable';
  if ( pdef )
    Scaleform::RefCountImpl::AddRef(pdef);
  this->pDef.pObject = pdef;
  if ( pdefImpl )
    Scaleform::RefCountImpl::AddRef(pdefImpl);
  this->pDefImpl.pObject = pdefImpl;
  if ( pin )
    Scaleform::RefCountImpl::AddRef(pin);
  this->pImageFile.pObject = (Scaleform::File *)pin;
  this->ImageFormat = format;
  this->pImageRes.pObject = 0;
}
