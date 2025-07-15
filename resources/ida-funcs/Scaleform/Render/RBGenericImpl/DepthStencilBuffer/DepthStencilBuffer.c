void __thiscall Scaleform::Render::RBGenericImpl::DepthStencilBuffer::DepthStencilBuffer(
        Scaleform::Render::RBGenericImpl::DepthStencilBuffer *this,
        Scaleform::Render::RBGenericImpl::RenderBufferManager *manager,
        const Scaleform::Render::Size<unsigned long> *bufferSize)
{
  unsigned int Width; // edx

  this->__vftable = (Scaleform::Render::RBGenericImpl::DepthStencilBuffer_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->pManager = manager;
  this->__vftable = (Scaleform::Render::RBGenericImpl::DepthStencilBuffer_vtbl *)&Scaleform::Render::RenderBuffer::`vftable';
  this->RefCount = 1;
  this->Type = RBuffer_DepthStencil;
  this->pRenderTargetData = 0;
  Width = bufferSize->Width;
  this->BufferSize.Height = bufferSize->Height;
  this->BufferSize.Width = Width;
  this->pPrev = 0;
  this->pNext = 0;
  this->pBuffer = this;
  this->ListType = RBCL_Uncached;
  this->Format = Image_None;
  this->DataSize = 0;
  this->__vftable = (Scaleform::Render::RBGenericImpl::DepthStencilBuffer_vtbl *)&Scaleform::Render::RBGenericImpl::DepthStencilBuffer::`vftable';
  this->pSurface.pObject = 0;
}
