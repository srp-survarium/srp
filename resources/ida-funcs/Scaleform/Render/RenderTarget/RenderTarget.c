void __thiscall Scaleform::Render::RenderTarget::RenderTarget(
        Scaleform::Render::RenderTarget *this,
        Scaleform::Render::RenderBufferManager *manager,
        Scaleform::Render::RenderBufferType type,
        const Scaleform::Render::Size<unsigned long> *bufferSize)
{
  unsigned int Height; // eax
  unsigned int Width; // edi

  Scaleform::Render::RenderBuffer::RenderBuffer(this, manager, type, bufferSize);
  this->__vftable = (Scaleform::Render::RenderTarget_vtbl *)&Scaleform::Render::RenderTarget::`vftable';
  Height = bufferSize->Height;
  Width = bufferSize->Width;
  this->ViewRect.x1 = 0;
  this->ViewRect.y1 = 0;
  this->ViewRect.x2 = Width;
  this->ViewRect.y2 = Height;
}
