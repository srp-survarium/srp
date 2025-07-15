void __thiscall Scaleform::GFx::PlaceObject2Tag::AddToTimelineSnapshot(
        Scaleform::GFx::PlaceObject2Tag *this,
        Scaleform::GFx::TimelineSnapshot *psnapshot,
        unsigned int frame)
{
  int v4; // eax
  unsigned __int16 v5; // dx
  char v6; // al
  Scaleform::ArrayDH_POD<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,2,Scaleform::ArrayDefaultPolicy> *p_SnapshotSortedArray; // edi
  int v8; // ebp
  unsigned int v9; // eax
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *v10; // edi
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // eax
  char v14; // al
  char v15; // al
  unsigned int Size; // [esp-Ch] [ebp-20h]
  char v17; // [esp+Ch] [ebp-8h]
  int val; // [esp+10h] [ebp-4h] BYREF

  this->Trace(this, "\n");
  v4 = 1;
  if ( (this->pData[0] & 0x80u) != 0 )
    v4 = 5;
  v5 = *(_WORD *)&this->pData[v4];
  v6 = this->pData[0] & 1;
  if ( (this->pData[0] & 2) == 0 )
  {
    v17 = 1;
    if ( v6 )
      goto LABEL_8;
LABEL_7:
    v17 = 0;
    goto LABEL_8;
  }
  if ( !v6 )
    goto LABEL_7;
  v17 = 2;
LABEL_8:
  p_SnapshotSortedArray = &psnapshot->SnapshotSortedArray;
  Size = psnapshot->SnapshotSortedArray.Data.Size;
  v8 = v5;
  val = v5;
  v9 = Scaleform::Alg::UpperBoundSliced<Scaleform::ArrayDH_POD<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,2,Scaleform::ArrayDefaultPolicy>,int,int (__cdecl *)(int,Scaleform::GFx::TimelineSnapshot::SnapshotElement const *)>(
         &psnapshot->SnapshotSortedArray,
         0,
         Size,
         &val,
         Scaleform::GFx::TimelineSnapshot::DepthLess);
  if ( v9 && (v10 = p_SnapshotSortedArray->Data.Data[v9 - 1], v10->Depth == v8) && v10 && (v10->Flags & 2) == 0 )
  {
    if ( v17 == 1 )
    {
      this->GetFlags(this, (Scaleform::GFx::CharPosInfoFlags *)&frame);
      v15 = frame;
      if ( (frame & 4) != 0 )
        v10->Tags.pMatrixTag = this;
      if ( (v15 & 8) != 0 )
        v10->Tags.pCxFormTag = this;
      if ( (v15 & 0x20) != 0 )
        v10->Tags.pFiltersTag = this;
      if ( v15 < 0 )
        v10->Tags.pBlendModeTag = this;
      if ( (v15 & 1) != 0 )
        v10->Tags.pDepthTag = this;
      if ( (v15 & 0x40) != 0 )
        v10->Tags.pClipDepthTag = this;
      if ( (v15 & 0x10) != 0 )
        v10->Tags.pRatioTag = this;
      if ( (v15 & 2) != 0 )
        v10->Tags.pCharIdTag = this;
      if ( (frame & 0x100) != 0 )
        v10->Tags.pClassNameTag = this;
    }
    else if ( v17 == 2 )
    {
      if ( v10->PlaceType )
        v10->PlaceType = 2;
      this->GetFlags(this, (Scaleform::GFx::CharPosInfoFlags *)&psnapshot);
      v14 = (char)psnapshot;
      if ( ((unsigned __int8)psnapshot & 4) != 0 )
        v10->Tags.pMatrixTag = this;
      if ( (v14 & 8) != 0 )
        v10->Tags.pCxFormTag = this;
      if ( (v14 & 0x20) != 0 )
        v10->Tags.pFiltersTag = this;
      if ( v14 < 0 )
        v10->Tags.pBlendModeTag = this;
      if ( (v14 & 1) != 0 )
        v10->Tags.pDepthTag = this;
      if ( (v14 & 0x40) != 0 )
        v10->Tags.pClipDepthTag = this;
      if ( (v14 & 0x10) != 0 )
        v10->Tags.pRatioTag = this;
      if ( (v14 & 2) != 0 )
        v10->Tags.pCharIdTag = this;
      if ( (BYTE1(psnapshot) & 1) != 0 )
        v10->Tags.pClassNameTag = this;
      v10->CreateFrame = frame;
    }
    else
    {
      v13 = frame;
      v10->Tags.pClassNameTag = this;
      v10->Tags.pCharIdTag = this;
      v10->Tags.pRatioTag = this;
      v10->Tags.pClipDepthTag = this;
      v10->Tags.pDepthTag = this;
      v10->Tags.pBlendModeTag = this;
      v10->Tags.pFiltersTag = this;
      v10->Tags.pCxFormTag = this;
      v10->Tags.pMatrixTag = this;
      v10->Tags.pMainTag = this;
      v10->CreateFrame = v13;
    }
  }
  else
  {
    v11 = Scaleform::GFx::TimelineSnapshot::Add(psnapshot, v8);
    v12 = frame;
    v11->Data[0].PlaceType = v17;
    v11->Data[0].Tags.pClassNameTag = this;
    v11->Data[0].Tags.pCharIdTag = this;
    v11->Data[0].Tags.pRatioTag = this;
    v11->Data[0].Tags.pClipDepthTag = this;
    v11->Data[0].Tags.pDepthTag = this;
    v11->Data[0].Tags.pBlendModeTag = this;
    v11->Data[0].Tags.pFiltersTag = this;
    v11->Data[0].Tags.pCxFormTag = this;
    v11->Data[0].Tags.pMatrixTag = this;
    v11->Data[0].Tags.pMainTag = this;
    v11->Data[0].CreateFrame = v12;
  }
}
