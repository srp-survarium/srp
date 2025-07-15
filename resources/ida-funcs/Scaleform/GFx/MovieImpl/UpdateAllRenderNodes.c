void __usercall Scaleform::GFx::MovieImpl::UpdateAllRenderNodes(Scaleform::GFx::MovieImpl *this@<ecx>, int a2@<ebx>)
{
  Scaleform::GFx::MovieImpl::UpdateAllDrawingContexts(this, a2);
  if ( this->FocusRectChanged )
    Scaleform::GFx::MovieImpl::UpdateFocusRectRenderNodes(this);
}
