Scaleform::Render::ContextImpl::RenderNotify::ServiceCommand *__thiscall Scaleform::Render::ContextImpl::RenderNotify::ServiceCommand::`scalar deleting destructor'(
        Scaleform::Render::ContextImpl::RenderNotify::ServiceCommand *this,
        char a2)
{
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
