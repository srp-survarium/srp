Scaleform::Render::RenderTarget *__thiscall Scaleform::Render::RenderBuffer::`vector deleting destructor'(
        Scaleform::Render::RenderTarget *this,
        char a2)
{
  Scaleform::Render::RenderBuffer::~RenderBuffer(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
