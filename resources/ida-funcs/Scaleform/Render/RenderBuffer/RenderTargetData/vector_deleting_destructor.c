Scaleform::Render::RenderBuffer::RenderTargetData *__thiscall Scaleform::Render::RenderBuffer::RenderTargetData::`vector deleting destructor'(
        Scaleform::Render::RenderBuffer::RenderTargetData *this,
        char a2)
{
  Scaleform::Render::RenderBuffer::RenderTargetData::~RenderTargetData(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
