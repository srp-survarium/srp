void __thiscall Scaleform::GFx::TimelineSnapshot::~TimelineSnapshot(Scaleform::GFx::TimelineSnapshot *this)
{
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *pNext; // eax
  Scaleform::List<Scaleform::GFx::TimelineSnapshot::SnapshotElement,Scaleform::GFx::TimelineSnapshot::SnapshotElement> *p_SnapshotList; // ecx
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *v4; // edx
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *FirstPage; // eax
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *v6; // esi

  pNext = (Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *)this->SnapshotList.Root.pNext;
  p_SnapshotList = &this->SnapshotList;
  if ( pNext != (Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *)p_SnapshotList )
  {
    do
    {
      v4 = pNext[1].pNext;
      pNext->pNext = this->SnapshotHeap.FirstEmptySlot;
      this->SnapshotHeap.FirstEmptySlot = pNext;
      pNext = v4;
    }
    while ( v4 != (Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *)p_SnapshotList );
  }
  p_SnapshotList->Root.pPrev = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)p_SnapshotList;
  p_SnapshotList->Root.pNext = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)p_SnapshotList;
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->SnapshotSortedArray.Data.Data);
  FirstPage = this->SnapshotHeap.FirstPage;
  if ( this->SnapshotHeap.FirstPage )
  {
    do
    {
      v6 = FirstPage->pNext;
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, FirstPage);
      FirstPage = v6;
    }
    while ( v6 );
  }
}
