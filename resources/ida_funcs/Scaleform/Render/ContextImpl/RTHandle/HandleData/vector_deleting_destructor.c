Scaleform::Render::ContextImpl::RTHandle::HandleData *__thiscall Scaleform::Render::ContextImpl::RTHandle::HandleData::`vector deleting destructor'(
        Scaleform::Render::ContextImpl::RTHandle::HandleData *this,
        char a2)
{
  Scaleform::Render::ContextImpl::RTHandle::HandleData::~HandleData(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
