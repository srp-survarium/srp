void __thiscall Scaleform::Render::JPEG::ImageSource::ImageSource(
        Scaleform::Render::JPEG::ImageSource *this,
        Scaleform::GFx::Resource *file,
        Scaleform::Render::ImageFormat format,
        Scaleform::GFx::Resource *exd,
        unsigned __int64 len,
        bool withHeaders)
{
  Scaleform::Render::FileImageSource::FileImageSource(this, file, format, len);
  this->__vftable = (Scaleform::Render::JPEG::ImageSource_vtbl *)&Scaleform::Render::JPEG::ImageSource::`vftable';
  this->pOriginalInput = 0;
  if ( exd )
    Scaleform::RefCountImpl::AddRef(exd);
  this->pExtraData.pObject = (Scaleform::Render::JPEG::ExtraData *)exd;
  this->WithHeaders = withHeaders;
}
