Scaleform::Render::DepthStencilBuffer *__thiscall Scaleform::Render::DepthStencilBuffer::`scalar deleting destructor'(
        Scaleform::Render::DepthStencilBuffer *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::DepthStencilBuffer_vtbl *)&Scaleform::Render::DepthStencilBuffer::`vftable';
  Scaleform::Render::RenderBuffer::~RenderBuffer(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
