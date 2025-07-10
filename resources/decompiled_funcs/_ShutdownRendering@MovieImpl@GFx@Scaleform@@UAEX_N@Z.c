void __thiscall Scaleform::GFx::MovieImpl::ShutdownRendering(Scaleform::GFx::MovieImpl *this, int wait)
{
  Scaleform::Render::ContextImpl::Context::Shutdown(&this->RenderContext, wait);
}
