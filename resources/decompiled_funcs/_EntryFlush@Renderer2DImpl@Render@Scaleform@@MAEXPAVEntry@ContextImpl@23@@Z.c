void __thiscall Scaleform::Render::Renderer2DImpl::EntryFlush(
        Scaleform::Render::Renderer2DImpl *this,
        Scaleform::Render::ContextImpl::Entry *p)
{
  this->EntryDestroy(this, p);
}
