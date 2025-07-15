Scaleform::Render::MemoryBufferImage *__thiscall Scaleform::Render::PNG::MemoryBufferImage::`scalar deleting destructor'(
        Scaleform::Render::MemoryBufferImage *this,
        char a2)
{
  volatile LONG *v3; // edi

  v3 = (volatile LONG *)(this->FilePath.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->FileData.Data.Data);
  Scaleform::Render::Image::~Image(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
