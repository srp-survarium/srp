Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *__thiscall Scaleform::GFx::TimelineSnapshot::Add(
        Scaleform::GFx::TimelineSnapshot *this,
        int depth)
{
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *v3; // eax
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *v4; // esi
  Scaleform::ArrayDH_POD<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,2,Scaleform::ArrayDefaultPolicy> *p_SnapshotSortedArray; // edi
  unsigned int v6; // eax
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *v8; // [esp+8h] [ebp-4h] BYREF

  v3 = Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2>>::allocate(&this->SnapshotHeap);
  v4 = v3;
  if ( v3 )
  {
    v3->Data[0].CreateFrame = -1;
    v3->Data[0].Tags.pMainTag = 0;
    v3->Data[0].Tags.pMatrixTag = 0;
    v3->Data[0].Tags.pCxFormTag = 0;
    v3->Data[0].Tags.pFiltersTag = 0;
    v3->Data[0].Tags.pBlendModeTag = 0;
    v3->Data[0].Tags.pDepthTag = 0;
    v3->Data[0].Tags.pClipDepthTag = 0;
    v3->Data[0].Tags.pRatioTag = 0;
    v3->Data[0].Tags.pCharIdTag = 0;
    v3->Data[0].Tags.pClassNameTag = 0;
    v3->Data[0].PlaceType = -1;
    v3->Data[0].Flags = 0;
  }
  v8 = v3;
  if ( !v3 )
    return 0;
  v3->Data[0].pPrev = this->SnapshotList.Root.pPrev;
  v3->Data[0].pNext = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)&this->SnapshotList;
  this->SnapshotList.Root.pPrev->pNext = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)v3;
  this->SnapshotList.Root.pPrev = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)v3;
  p_SnapshotSortedArray = &this->SnapshotSortedArray;
  v3->Data[0].Depth = depth;
  v6 = Scaleform::Alg::UpperBoundSliced<Scaleform::ArrayDH_POD<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,2,Scaleform::ArrayDefaultPolicy>,int,int (__cdecl *)(int,Scaleform::GFx::TimelineSnapshot::SnapshotElement const *)>(
         p_SnapshotSortedArray,
         0,
         p_SnapshotSortedArray->Data.Size,
         &depth,
         Scaleform::GFx::TimelineSnapshot::DepthLess);
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,Scaleform::AllocatorDH_POD<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    p_SnapshotSortedArray,
    v6,
    (Scaleform::GFx::TimelineSnapshot::SnapshotElement **)&v8);
  return v4;
}
