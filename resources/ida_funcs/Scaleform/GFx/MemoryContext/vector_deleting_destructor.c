Scaleform::GFx::MemoryContext *__thiscall Scaleform::GFx::MemoryContext::`vector deleting destructor'(
        Scaleform::GFx::MemoryContext *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::MemoryContext_vtbl *)&Scaleform::GFx::MemoryContext::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
