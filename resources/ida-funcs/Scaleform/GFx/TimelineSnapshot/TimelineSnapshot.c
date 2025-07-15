void __thiscall Scaleform::GFx::TimelineSnapshot::TimelineSnapshot(
        Scaleform::GFx::TimelineSnapshot *this,
        Scaleform::GFx::TimelineSnapshot::DirectionType dir,
        Scaleform::MemoryHeap *pheap,
        Scaleform::GFx::InteractiveObject *powner)
{
  Scaleform::List<Scaleform::GFx::TimelineSnapshot::SnapshotElement,Scaleform::GFx::TimelineSnapshot::SnapshotElement> *p_SnapshotList; // ecx

  this->SnapshotHeap.FirstPage = 0;
  this->SnapshotHeap.LastPage = 0;
  this->SnapshotHeap.FirstEmptySlot = 0;
  this->SnapshotHeap.pHeapOrPtr = pheap;
  this->SnapshotHeap.NumElementsInPage = 50;
  this->SnapshotSortedArray.Data.Data = 0;
  this->SnapshotSortedArray.Data.Size = 0;
  this->SnapshotSortedArray.Data.Policy.Capacity = 0;
  this->SnapshotSortedArray.Data.pHeap = pheap;
  p_SnapshotList = &this->SnapshotList;
  p_SnapshotList->Root.pPrev = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)p_SnapshotList;
  p_SnapshotList->Root.pNext = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)p_SnapshotList;
  this->pOwnerSprite = powner;
  this->Direction = dir;
}
