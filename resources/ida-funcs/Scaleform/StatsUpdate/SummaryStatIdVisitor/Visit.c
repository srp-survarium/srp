void __thiscall Scaleform::StatsUpdate::SummaryStatIdVisitor::Visit(
        Scaleform::StatsUpdate::SummaryStatIdVisitor *this,
        Scaleform::MemoryHeap *parent,
        Scaleform::MemoryHeap *heap)
{
  unsigned int Size; // edx
  unsigned int v5; // eax
  Scaleform::HeapId *Data; // ecx
  Scaleform::StatBag other; // [esp+8h] [ebp-20Ch] BYREF

  if ( ((heap->Info.Desc.Flags & 0x1000) != 0) == this->Debug )
  {
    Size = this->ExcludedHeaps.Data.Size;
    v5 = 0;
    if ( Size )
    {
      Data = this->ExcludedHeaps.Data.Data;
      while ( heap->Info.Desc.HeapId != *Data )
      {
        ++v5;
        ++Data;
        if ( v5 >= Size )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      Scaleform::StatBag::StatBag(&other, 0, 0x2000u);
      heap->GetStats(heap, &other);
      Scaleform::StatBag::CombineStatBags(
        &this->StatIdBag,
        &other,
        (bool (__thiscall *)(Scaleform::StatBag *, unsigned int, Scaleform::Stat *))Scaleform::StatBag::Add);
      Scaleform::MemoryHeap::VisitChildHeaps(heap, this);
      Scaleform::StatBag::~StatBag(&other);
    }
  }
}
