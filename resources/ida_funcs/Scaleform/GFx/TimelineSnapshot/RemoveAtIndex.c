void __thiscall Scaleform::GFx::TimelineSnapshot::RemoveAtIndex(
        Scaleform::GFx::TimelineSnapshot *this,
        unsigned int idx)
{
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *v3; // edi
  unsigned int Size; // eax

  v3 = (Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *)this->SnapshotSortedArray.Data.Data[idx];
  v3->pNext[1].pNext = v3[1].pNext;
  v3[1].pNext->pNext = v3->pNext;
  Size = this->SnapshotSortedArray.Data.Size;
  if ( Size == 1 )
  {
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,Scaleform::AllocatorDH_POD<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,2>,Scaleform::ArrayDefaultPolicy>>::Clear(&this->SnapshotSortedArray);
  }
  else
  {
    memmove(
      (unsigned __int8 *)&this->SnapshotSortedArray.Data.Data[idx],
      (unsigned __int8 *)&this->SnapshotSortedArray.Data.Data[idx + 1],
      4 * (Size - idx) - 4);
    --this->SnapshotSortedArray.Data.Size;
  }
  v3->pNext = this->SnapshotHeap.FirstEmptySlot;
  this->SnapshotHeap.FirstEmptySlot = v3;
}
