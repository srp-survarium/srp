void __thiscall Scaleform::Render::FileImageSource::FileImageSource(
        Scaleform::Render::FileImageSource *this,
        Scaleform::GFx::Resource *file,
        Scaleform::Render::ImageFormat format,
        unsigned __int64 len)
{
  Scaleform::File *pObject; // ecx

  this->__vftable = (Scaleform::Render::FileImageSource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::FileImageSource_vtbl *)&Scaleform::Render::FileImageSource::`vftable';
  this->Format = format;
  this->Use = 0;
  if ( file )
    Scaleform::RefCountImpl::AddRef(file);
  this->pFile.pObject = (Scaleform::File *)file;
  LODWORD(this->FileLen) = len;
  pObject = this->pFile.pObject;
  HIDWORD(this->FileLen) = HIDWORD(len);
  this->FilePos = pObject->LTell(pObject);
  this->ImageId = Scaleform::Render::ImageBase::GetNextImageId();
}
