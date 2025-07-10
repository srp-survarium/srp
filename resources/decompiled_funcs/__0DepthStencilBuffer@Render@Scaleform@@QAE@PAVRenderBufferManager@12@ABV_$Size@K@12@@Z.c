void __thiscall Scaleform::Render::DepthStencilBuffer::DepthStencilBuffer(
        Scaleform::Render::DepthStencilBuffer *this,
        Scaleform::Render::RenderBufferManager *manager,
        const Scaleform::Render::Size<unsigned long> *bufferSize)
{
  unsigned int Height; // edx

  this->__vftable = (Scaleform::Render::DepthStencilBuffer_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->pManager = manager;
  this->__vftable = (Scaleform::Render::DepthStencilBuffer_vtbl *)&Scaleform::Render::RenderBuffer::`vftable';
  this->RefCount = 1;
  this->Type = RBuffer_DepthStencil;
  this->pRenderTargetData = 0;
  Height = bufferSize->Height;
  this->BufferSize.Width = bufferSize->Width;
  this->BufferSize.Height = Height;
  this->__vftable = (Scaleform::Render::DepthStencilBuffer_vtbl *)&Scaleform::Render::DepthStencilBuffer::`vftable';
}
