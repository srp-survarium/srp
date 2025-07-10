void __thiscall Scaleform::GFx::DrawTextManager::Capture(Scaleform::GFx::DrawTextManager *this, bool onChangeOnly)
{
  if ( !onChangeOnly || Scaleform::Render::ContextImpl::Context::HasChanges(&this->pImpl->RenderContext) )
    Scaleform::Render::ContextImpl::Context::Capture(&this->pImpl->RenderContext);
}
