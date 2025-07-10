void __thiscall Scaleform::GFx::AS2::ASRefCountCollector::AdvanceFrame(
        Scaleform::GFx::AS2::ASRefCountCollector *this,
        unsigned int *movieFrameCnt,
        unsigned int *movieLastCollectFrame)
{
  unsigned int LastCollectionFrameNum; // eax
  unsigned int FrameCnt; // eax
  unsigned int v6; // edx
  unsigned int PeakRootCount; // eax
  unsigned int Size; // edi
  unsigned int PresetMaxRootCount; // ecx
  unsigned int MaxFramesBetweenCollections; // eax
  unsigned int v11; // eax
  unsigned int RootsFreedTotal; // ecx
  unsigned int MaxRootCount; // eax
  unsigned int v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // eax
  unsigned int v17; // ecx
  Scaleform::GFx::AS2::RefCountCollector<323>::Stats stats; // [esp+Ch] [ebp-8h] BYREF

  LastCollectionFrameNum = this->LastCollectionFrameNum;
  if ( *movieLastCollectFrame == LastCollectionFrameNum )
  {
    FrameCnt = this->FrameCnt;
    if ( *movieFrameCnt >= FrameCnt )
    {
      ++this->TotalFramesCount;
      v6 = FrameCnt + 1;
      PeakRootCount = this->PeakRootCount;
      Size = this->Roots.Size;
      this->FrameCnt = v6;
      if ( Size >= PeakRootCount )
        PeakRootCount = Size;
      PresetMaxRootCount = this->PresetMaxRootCount;
      this->PeakRootCount = PeakRootCount;
      if ( PresetMaxRootCount && Size > this->MaxRootCount
        || (MaxFramesBetweenCollections = this->MaxFramesBetweenCollections) != 0
        && v6 >= MaxFramesBetweenCollections
        && Size > PresetMaxRootCount )
      {
        stats.RootsFreedTotal = 0;
        stats.RootsNumber = 0;
        Scaleform::GFx::AS2::RefCountCollector<323>::Collect(this, &stats);
        v11 = this->PresetMaxRootCount;
        RootsFreedTotal = stats.RootsFreedTotal;
        if ( stats.RootsFreedTotal > v11 )
        {
          this->PeakRootCount = Size;
          this->MaxRootCount = v11;
        }
        MaxRootCount = Size - RootsFreedTotal;
        if ( Size - RootsFreedTotal < this->MaxRootCount )
          MaxRootCount = this->MaxRootCount;
        this->MaxRootCount = MaxRootCount;
        v14 = (__int64)((double)MaxRootCount * 0.7);
        v15 = this->PeakRootCount;
        if ( v15 < v14 )
          this->MaxRootCount = v14;
        v16 = stats.RootsFreedTotal;
        this->LastCollectionFrameNum = this->TotalFramesCount;
        this->FrameCnt = 0;
        this->LastPeakRootCount = v15;
        this->LastCollectedRoots = v16;
      }
      v17 = this->FrameCnt;
      this->LastRootCount = Size;
      *movieFrameCnt = v17;
      *movieLastCollectFrame = this->LastCollectionFrameNum;
    }
    else
    {
      ++*movieFrameCnt;
    }
  }
  else
  {
    *movieLastCollectFrame = LastCollectionFrameNum;
    *movieFrameCnt = 1;
  }
}
