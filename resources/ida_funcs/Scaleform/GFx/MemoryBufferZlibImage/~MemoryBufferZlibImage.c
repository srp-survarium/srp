void __thiscall Scaleform::GFx::MemoryBufferZlibImage::~MemoryBufferZlibImage(
        Scaleform::GFx::MemoryBufferZlibImage *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  volatile LONG *v3; // esi

  pObject = (Scaleform::RefCountVImpl *)this->Zlib.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v3 = (volatile LONG *)(this->FilePath.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->FileData.Data.Data);
  Scaleform::Render::Image::~Image(this);
}
