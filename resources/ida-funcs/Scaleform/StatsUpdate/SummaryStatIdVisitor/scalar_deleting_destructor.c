Scaleform::StatsUpdate::SummaryStatIdVisitor *__thiscall Scaleform::StatsUpdate::SummaryStatIdVisitor::`scalar deleting destructor'(
        Scaleform::StatsUpdate::SummaryStatIdVisitor *this,
        char a2)
{
  Scaleform::HeapId *Data; // eax

  Data = this->ExcludedHeaps.Data.Data;
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  Scaleform::StatBag::~StatBag(&this->StatIdBag);
  this->__vftable = (Scaleform::StatsUpdate::SummaryStatIdVisitor_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
