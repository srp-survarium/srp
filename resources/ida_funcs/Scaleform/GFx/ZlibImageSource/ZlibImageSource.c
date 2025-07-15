void __thiscall Scaleform::GFx::ZlibImageSource::ZlibImageSource(
        Scaleform::GFx::ZlibImageSource *this,
        Scaleform::GFx::Resource *zlib,
        Scaleform::GFx::Resource *file,
        const Scaleform::Render::Size<unsigned long> *size,
        Scaleform::GFx::ZlibImageSource::SourceBitmapDataFormat bmpFormatId,
        Scaleform::Render::ImageFormat format,
        unsigned __int16 colorTableSize,
        unsigned __int64 uncompressedLen)
{
  unsigned int Height; // ecx

  Scaleform::Render::FileImageSource::FileImageSource(this, file, format, uncompressedLen);
  this->__vftable = (Scaleform::GFx::ZlibImageSource_vtbl *)&Scaleform::GFx::ZlibImageSource::`vftable';
  if ( zlib )
    Scaleform::RefCountImpl::AddRef(zlib);
  this->Zlib.pObject = (Scaleform::GFx::ZlibSupportBase *)zlib;
  this->ColorTableSize = colorTableSize;
  this->BitmapFormatId = bmpFormatId;
  Height = size->Height;
  this->Size.Width = size->Width;
  this->Size.Height = Height;
}
