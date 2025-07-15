void __thiscall Scaleform::GFx::RemoveObject2Tag::AddToTimelineSnapshot(
        Scaleform::GFx::RemoveObject2Tag *this,
        Scaleform::GFx::TimelineSnapshot *psnapshot,
        unsigned int __formal)
{
  int Depth; // ebx
  unsigned int v5; // eax
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v6; // ecx
  Scaleform::GFx::TimelineSnapshot *v7; // eax
  Scaleform::GFx::TimelineSnapshot *v8; // esi
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v9; // eax
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v10; // eax
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *v11; // eax
  int v12; // ecx
  unsigned int Size; // [esp-Ch] [ebp-24h]
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *v14; // [esp+10h] [ebp-8h] BYREF
  int v15; // [esp+14h] [ebp-4h] BYREF

  this->Trace(this, "\n");
  Depth = this->Depth;
  Size = psnapshot->SnapshotSortedArray.Data.Size;
  v15 = Depth;
  v5 = Scaleform::Alg::UpperBoundSliced<Scaleform::ArrayDH_POD<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,2,Scaleform::ArrayDefaultPolicy>,int,int (__cdecl *)(int,Scaleform::GFx::TimelineSnapshot::SnapshotElement const *)>(
         &psnapshot->SnapshotSortedArray,
         0,
         Size,
         &v15,
         Scaleform::GFx::TimelineSnapshot::DepthLess);
  if ( v5
    && (v6 = psnapshot->SnapshotSortedArray.Data.Data[v5 - 1],
        v7 = (Scaleform::GFx::TimelineSnapshot *)(v5 - 1),
        v6->Depth == Depth) )
  {
    v8 = v7;
    v9 = v6;
  }
  else
  {
    v8 = psnapshot;
    v9 = 0;
  }
  v14 = (Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *)v9;
  if ( !v9 )
    goto LABEL_14;
  if ( v9->PlaceType )
  {
    Scaleform::GFx::TimelineSnapshot::RemoveAtIndex(psnapshot, (unsigned int)v8);
    v14 = 0;
LABEL_14:
    if ( psnapshot->Direction == Direction_Forward )
    {
      v11 = Scaleform::GFx::TimelineSnapshot::Add(psnapshot, this->Depth);
      v12 = this->Depth;
      v14 = v11;
      v11->Data[0].Depth = v12;
      v14->Data[0].PlaceType = 3;
      v14->Data[0].Flags |= 2u;
    }
    return;
  }
  if ( v9->Tags.pMainTag )
  {
    if ( psnapshot->Direction == Direction_Forward )
    {
      v10 = v9->Tags.pMainTag->UnpackEventHandlers(v9->Tags.pMainTag);
      if ( v10 )
        this->CheckEventHandlers(this, (void **)&v14, v10);
    }
  }
  if ( !v14 )
    goto LABEL_14;
  Scaleform::GFx::TimelineSnapshot::RemoveAtIndex(psnapshot, (unsigned int)v8);
  if ( !v14 )
    goto LABEL_14;
}
