Scaleform::GFx::Task *__thiscall Scaleform::GFx::Task::`vector deleting destructor'(
        Scaleform::GFx::Task *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::Task_vtbl *)&Scaleform::GFx::Task::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
