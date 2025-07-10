void __thiscall Scaleform::Render::RenderTarget::RenderTarget(
        Scaleform::Render::RenderTarget *this,
        Scaleform::Render::RenderBufferManager *manager,
        Scaleform::Render::RenderBufferType type,
        const Scaleform::Render::Size<unsigned long> *bufferSize)
{
  unsigned int Height; // edx
  unsigned int v6; // edx
  unsigned int Width; // ecx

  this->__vftable = (Scaleform::Render::RenderTarget_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->Type = type;
  this->__vftable = (Scaleform::Render::RenderTarget_vtbl *)&Scaleform::Render::RenderBuffer::`vftable';
  this->RefCount = 1;
  this->pManager = manager;
  this->pRenderTargetData = 0;
  Height = bufferSize->Height;
  this->BufferSize.Width = bufferSize->Width;
  this->BufferSize.Height = Height;
  this->__vftable = (Scaleform::Render::RenderTarget_vtbl *)&Scaleform::Render::RenderTarget::`vftable';
  v6 = bufferSize->Height;
  Width = bufferSize->Width;
  this->ViewRect.x1 = 0;
  this->ViewRect.y1 = 0;
  this->ViewRect.x2 = Width;
  this->ViewRect.y2 = v6;
}
