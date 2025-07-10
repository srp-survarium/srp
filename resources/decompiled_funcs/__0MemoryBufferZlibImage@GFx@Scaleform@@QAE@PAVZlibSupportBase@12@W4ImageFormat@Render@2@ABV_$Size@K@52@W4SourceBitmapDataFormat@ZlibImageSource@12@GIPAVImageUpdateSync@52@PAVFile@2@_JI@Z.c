void __thiscall Scaleform::GFx::MemoryBufferZlibImage::MemoryBufferZlibImage(
        Scaleform::GFx::MemoryBufferZlibImage *this,
        Scaleform::GFx::Resource *zlib,
        Scaleform::Render::ImageFormat format,
        const Scaleform::Render::Size<unsigned long> *size,
        Scaleform::GFx::ZlibImageSource::SourceBitmapDataFormat bmpFormatId,
        unsigned __int16 colorTableSize,
        unsigned int use,
        Scaleform::Render::ImageUpdateSync *sync,
        Scaleform::File *file,
        __int64 filePos,
        unsigned int length)
{
  Scaleform::Render::MemoryBufferImage::MemoryBufferImage(this, format, size, use, sync, file, filePos, length);
  this->__vftable = (Scaleform::GFx::MemoryBufferZlibImage_vtbl *)&Scaleform::GFx::MemoryBufferZlibImage::`vftable';
  if ( zlib )
    Scaleform::RefCountImpl::AddRef(zlib);
  this->Zlib.pObject = (Scaleform::GFx::ZlibSupportBase *)zlib;
  this->BitmapFormatId = bmpFormatId;
  this->ColorTableSize = colorTableSize;
}
