void __thiscall Scaleform::Render::JPEG::MemoryBufferImage::~MemoryBufferImage(
        Scaleform::Render::JPEG::MemoryBufferImage *this)
{
  Scaleform::Render::JPEG::ExtraData *pExtraData; // ecx
  volatile LONG *v3; // esi

  pExtraData = this->pExtraData;
  this->__vftable = (Scaleform::Render::JPEG::MemoryBufferImage_vtbl *)&Scaleform::Render::JPEG::MemoryBufferImage::`vftable';
  if ( ((unsigned __int8)pExtraData & 3) != 0 && ((unsigned int)pExtraData & 0xFFFFFFFC) != 0 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)((unsigned int)pExtraData & 0xFFFFFFFC));
  v3 = (volatile LONG *)(this->FilePath.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->FileData.Data.Data);
  Scaleform::Render::Image::~Image(this);
}
