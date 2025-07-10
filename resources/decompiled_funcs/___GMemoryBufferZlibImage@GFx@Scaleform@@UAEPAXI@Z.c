Scaleform::GFx::MemoryBufferZlibImage *__thiscall Scaleform::GFx::MemoryBufferZlibImage::`scalar deleting destructor'(
        Scaleform::GFx::MemoryBufferZlibImage *this,
        char a2)
{
  Scaleform::GFx::MemoryBufferZlibImage::~MemoryBufferZlibImage(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
