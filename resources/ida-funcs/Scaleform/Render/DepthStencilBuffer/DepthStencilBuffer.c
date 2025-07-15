void __thiscall Scaleform::Render::DepthStencilBuffer::DepthStencilBuffer(
        Scaleform::Render::DepthStencilBuffer *this,
        Scaleform::Render::RenderBufferManager *manager,
        const Scaleform::Render::Size<unsigned long> *bufferSize)
{
  Scaleform::Render::RenderBuffer::RenderBuffer(this, manager, RBuffer_DepthStencil, bufferSize);
  this->__vftable = (Scaleform::Render::DepthStencilBuffer_vtbl *)&Scaleform::Render::DepthStencilBuffer::`vftable';
}
