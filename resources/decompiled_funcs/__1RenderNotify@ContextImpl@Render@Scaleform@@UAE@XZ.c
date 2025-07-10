void __thiscall Scaleform::Render::ContextImpl::RenderNotify::~RenderNotify(
        Scaleform::Render::ContextImpl::RenderNotify *this)
{
  this->__vftable = (Scaleform::Render::ContextImpl::RenderNotify_vtbl *)&Scaleform::Render::ContextImpl::RenderNotify::`vftable';
  Scaleform::Render::ContextImpl::RenderNotify::ReleaseAllContextData(this);
  Scaleform::RefCountImplCore::~RefCountImplCore(&this->ServiceCommandInstance);
}
