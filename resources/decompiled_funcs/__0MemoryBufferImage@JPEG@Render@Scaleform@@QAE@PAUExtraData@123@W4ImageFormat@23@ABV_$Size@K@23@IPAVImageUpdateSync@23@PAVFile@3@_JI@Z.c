void __thiscall Scaleform::Render::JPEG::MemoryBufferImage::MemoryBufferImage(
        Scaleform::Render::JPEG::MemoryBufferImage *this,
        Scaleform::GFx::Resource *exd,
        Scaleform::Render::ImageFormat format,
        const Scaleform::Render::Size<unsigned long> *size,
        unsigned int use,
        Scaleform::Render::ImageUpdateSync *sync,
        Scaleform::File *file,
        __int64 filePos,
        unsigned int length)
{
  Scaleform::Render::MemoryBufferImage::MemoryBufferImage(this, format, size, use, sync, file, filePos, length);
  this->__vftable = (Scaleform::Render::JPEG::MemoryBufferImage_vtbl *)&Scaleform::Render::JPEG::MemoryBufferImage::`vftable';
  this->Flags = (unsigned int)exd;
  if ( exd )
  {
    Scaleform::RefCountImpl::AddRef(exd);
    if ( this->pExtraData->IsTableHeader((Scaleform::Render::JPEG::ExtraData *)this->Flags) )
      this->Flags |= 1u;
  }
}
