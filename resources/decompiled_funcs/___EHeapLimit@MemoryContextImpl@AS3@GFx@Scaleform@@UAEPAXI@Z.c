Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit *__thiscall Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit::`vector deleting destructor'(
        Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit_vtbl *)&Scaleform::Render::StateData::Interface::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
