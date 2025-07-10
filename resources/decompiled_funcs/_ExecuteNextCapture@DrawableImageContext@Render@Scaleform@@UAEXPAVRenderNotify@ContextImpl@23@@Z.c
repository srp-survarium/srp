void __thiscall Scaleform::Render::DrawableImageContext::ExecuteNextCapture(
        Scaleform::Render::DrawableImageContext *this,
        Scaleform::Render::ContextImpl::RenderNotify *notify)
{
  Scaleform::Render::ContextImpl::Context *RContext; // ecx

  RContext = this->RContext;
  if ( RContext )
    Scaleform::Render::ContextImpl::Context::NextCapture(RContext, notify, Capture_Immediate);
}
