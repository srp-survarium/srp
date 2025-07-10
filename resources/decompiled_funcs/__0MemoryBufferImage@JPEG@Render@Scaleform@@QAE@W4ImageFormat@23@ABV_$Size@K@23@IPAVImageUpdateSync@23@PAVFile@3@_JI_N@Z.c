void __thiscall Scaleform::Render::JPEG::MemoryBufferImage::MemoryBufferImage(
        Scaleform::Render::JPEG::MemoryBufferImage *this,
        Scaleform::Render::ImageFormat format,
        const Scaleform::Render::Size<unsigned long> *size,
        unsigned int use,
        Scaleform::Render::ImageUpdateSync *sync,
        Scaleform::File *file,
        __int64 filePos,
        unsigned int length,
        bool headers)
{
  Scaleform::Render::MemoryBufferImage::MemoryBufferImage(this, format, size, use, sync, file, filePos, length);
  this->__vftable = (Scaleform::Render::JPEG::MemoryBufferImage_vtbl *)&Scaleform::Render::JPEG::MemoryBufferImage::`vftable';
  this->Flags = 0;
  if ( headers )
    this->Flags = 1;
}
