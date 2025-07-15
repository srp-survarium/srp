Scaleform::Render::ContextImpl::RenderNotify *__thiscall Scaleform::Render::ContextImpl::RenderNotify::`scalar deleting destructor'(
        Scaleform::Render::ContextImpl::RenderNotify *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::ContextImpl::RenderNotify_vtbl *)&Scaleform::Render::ContextImpl::RenderNotify::`vftable';
  Scaleform::Render::ContextImpl::RenderNotify::ReleaseAllContextData(this);
  Scaleform::RefCountImplCore::~RefCountImplCore(&this->ServiceCommandInstance);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
