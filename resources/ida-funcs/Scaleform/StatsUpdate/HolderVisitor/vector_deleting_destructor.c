Scaleform::StatsUpdate::HolderVisitor *__thiscall Scaleform::StatsUpdate::HolderVisitor::`vector deleting destructor'(
        Scaleform::StatsUpdate::HolderVisitor *this,
        char a2)
{
  Scaleform::MemoryHeap **Data; // eax

  Data = this->Heaps.Data.Data;
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  this->__vftable = (Scaleform::StatsUpdate::HolderVisitor_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
