void __thiscall Scaleform::GFx::MovieImpl::ForceUpdateImages(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::Render::ContextImpl::Context::ForceUpdateImages(&this->RenderContext);
  ++this->PreviouslyCaptured;
}
