void __thiscall Scaleform::Render::RenderBuffer::RenderBuffer(
        Scaleform::Render::RenderBuffer *this,
        Scaleform::Render::RenderBufferManager *manager,
        Scaleform::Render::RenderBufferType type,
        const Scaleform::Render::Size<unsigned long> *bufferSize)
{
  unsigned int Height; // edx

  this->pRenderTargetData = 0;
  this->Type = type;
  this->__vftable = (Scaleform::Render::RenderBuffer_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->pManager = manager;
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::RenderBuffer_vtbl *)&Scaleform::Render::RenderBuffer::`vftable';
  Height = bufferSize->Height;
  this->BufferSize.Width = bufferSize->Width;
  this->BufferSize.Height = Height;
}
