void __thiscall Scaleform::Render::RenderBuffer::~RenderBuffer(Scaleform::Render::RenderBuffer *this)
{
  this->__vftable = (Scaleform::Render::RenderBuffer_vtbl *)&Scaleform::Render::RenderBuffer::`vftable';
  Scaleform::Render::RenderBuffer::destroyRenderTargetData(this);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
