void __thiscall Scaleform::GFx::MovieImpl::UpdateAllRenderNodes(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieImpl::UpdateAllDrawingContexts(this);
  if ( this->FocusRectChanged )
    Scaleform::GFx::MovieImpl::UpdateFocusRectRenderNodes(this);
}
