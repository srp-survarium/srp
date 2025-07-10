Scaleform::Render::ContextImpl::ContextLock *__thiscall Scaleform::Render::ContextImpl::ContextLock::`scalar deleting destructor'(
        Scaleform::Render::ContextImpl::ContextLock *this,
        char a2)
{
  Scaleform::Lock::~Lock(&this->LockObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
