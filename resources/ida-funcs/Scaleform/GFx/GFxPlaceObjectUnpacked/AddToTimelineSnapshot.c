void __thiscall Scaleform::GFx::GFxPlaceObjectUnpacked::AddToTimelineSnapshot(
        Scaleform::GFx::GFxPlaceObjectUnpacked *this,
        Scaleform::GFx::TimelineSnapshot *psnapshot,
        unsigned int frame)
{
  int Depth; // ebp
  unsigned int v5; // eax
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v6; // eax
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *v7; // eax
  unsigned int Size; // [esp-Ch] [ebp-20h]
  int v9; // [esp+10h] [ebp-4h] BYREF

  this->Trace(this, "\n");
  Depth = this->Pos.Depth;
  Size = psnapshot->SnapshotSortedArray.Data.Size;
  v9 = Depth;
  v5 = Scaleform::Alg::UpperBoundSliced<Scaleform::ArrayDH_POD<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,2,Scaleform::ArrayDefaultPolicy>,int,int (__cdecl *)(int,Scaleform::GFx::TimelineSnapshot::SnapshotElement const *)>(
         &psnapshot->SnapshotSortedArray,
         0,
         Size,
         &v9,
         Scaleform::GFx::TimelineSnapshot::DepthLess);
  if ( v5 && (v6 = psnapshot->SnapshotSortedArray.Data.Data[v5 - 1], v6->Depth == Depth) && v6 && (v6->Flags & 2) == 0 )
  {
    v6->Tags.pClassNameTag = this;
    v6->Tags.pCharIdTag = this;
    v6->Tags.pRatioTag = this;
    v6->Tags.pClipDepthTag = this;
    v6->Tags.pDepthTag = this;
    v6->Tags.pBlendModeTag = this;
    v6->Tags.pFiltersTag = this;
    v6->Tags.pCxFormTag = this;
    v6->Tags.pMatrixTag = this;
    v6->Tags.pMainTag = this;
    v6->CreateFrame = frame;
    v6->Flags |= 1u;
  }
  else
  {
    v7 = Scaleform::GFx::TimelineSnapshot::Add(psnapshot, this->Pos.Depth);
    v7->Data[0].Tags.pClassNameTag = this;
    v7->Data[0].Tags.pCharIdTag = this;
    v7->Data[0].Tags.pRatioTag = this;
    v7->Data[0].Tags.pClipDepthTag = this;
    v7->Data[0].Tags.pDepthTag = this;
    v7->Data[0].Tags.pBlendModeTag = this;
    v7->Data[0].Tags.pFiltersTag = this;
    v7->Data[0].Tags.pCxFormTag = this;
    v7->Data[0].Tags.pMatrixTag = this;
    v7->Data[0].Tags.pMainTag = this;
    v7->Data[0].PlaceType = 0;
    v7->Data[0].CreateFrame = frame;
    v7->Data[0].Flags |= 1u;
  }
}
