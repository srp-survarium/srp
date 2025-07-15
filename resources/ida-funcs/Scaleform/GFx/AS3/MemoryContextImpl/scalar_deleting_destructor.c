Scaleform::GFx::AS3::MemoryContextImpl *__thiscall Scaleform::GFx::AS3::MemoryContextImpl::`scalar deleting destructor'(
        Scaleform::GFx::AS3::MemoryContextImpl *this,
        char a2)
{
  Scaleform::GFx::AS2::MemoryContextImpl::~MemoryContextImpl(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
