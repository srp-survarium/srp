BOOL __thiscall Scaleform::GFx::MovieImpl::IsShutdownRenderingComplete(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *RContext; // eax
  BOOL result; // eax

  result = 0;
  if ( Scaleform::Render::ContextImpl::Context::IsShutdownComplete(&this->RenderContext) )
  {
    pObject = this->DIContext.pObject;
    if ( !pObject )
      return 1;
    RContext = pObject->RContext;
    if ( !RContext || Scaleform::Render::ContextImpl::Context::IsShutdownComplete(RContext) )
      return 1;
  }
  return result;
}
