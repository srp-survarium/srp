Scaleform::Render::JPEG::MemoryBufferImage *__thiscall Scaleform::Render::JPEG::MemoryBufferImage::`vector deleting destructor'(
        Scaleform::Render::JPEG::MemoryBufferImage *this,
        char a2)
{
  Scaleform::Render::JPEG::MemoryBufferImage::~MemoryBufferImage(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
