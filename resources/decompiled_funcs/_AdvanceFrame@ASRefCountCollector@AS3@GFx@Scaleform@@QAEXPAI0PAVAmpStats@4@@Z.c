void __thiscall Scaleform::GFx::AS3::ASRefCountCollector::AdvanceFrame(
        Scaleform::GFx::AS3::ASRefCountCollector *this,
        unsigned int *movieFrameCnt,
        unsigned int *movieLastCollectFrame,
        Scaleform::GFx::Resource *ampStats)
{
  unsigned int LastCollectionFrameNum; // eax
  unsigned int FrameCnt; // ebp
  unsigned int v7; // ebx
  Scaleform::GFx::AS3::RefCountCollector<328> *v8; // ecx
  unsigned int RootsCount; // eax
  unsigned int v10; // edi
  unsigned int PeakRootCount; // eax
  bool v12; // zf
  unsigned int v13; // edx
  unsigned int MaxFramesBetweenCollections; // eax
  unsigned int PresetMaxRootCount; // eax
  unsigned int RootsFreedTotal; // ecx
  unsigned int MaxRootCount; // eax
  unsigned int v18; // eax
  Scaleform::AmpStats *pObject; // ecx
  unsigned int TotalFramesCount; // edx
  unsigned int v21; // eax
  unsigned int v22; // ecx
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *upgradeGen; // [esp+4h] [ebp-24h] BYREF
  __int64 v24; // [esp+8h] [ebp-20h]
  Scaleform::GFx::AS3::RefCountCollector<328>::Stats stats; // [esp+10h] [ebp-18h] BYREF

  LastCollectionFrameNum = this->LastCollectionFrameNum;
  if ( *movieLastCollectFrame == LastCollectionFrameNum )
  {
    FrameCnt = this->FrameCnt;
    if ( *movieFrameCnt >= FrameCnt )
    {
      LOBYTE(upgradeGen) = 0;
      v7 = Scaleform::GFx::AS3::ASRefCountCollector::CheckGenerations(this, (bool *)&upgradeGen);
      RootsCount = Scaleform::GFx::AS3::RefCountCollector<328>::GetRootsCount(v8, v7);
      ++this->TotalFramesCount;
      v10 = RootsCount;
      PeakRootCount = this->PeakRootCount;
      this->FrameCnt = FrameCnt + 1;
      if ( v10 >= PeakRootCount )
        PeakRootCount = v10;
      v12 = this->SuspendCnt == 0;
      this->PeakRootCount = PeakRootCount;
      if ( v12
        && ((v13 = this->PresetMaxRootCount) != 0 && v10 > this->MaxRootCount
         || (MaxFramesBetweenCollections = this->MaxFramesBetweenCollections) != 0
         && FrameCnt + 1 >= MaxFramesBetweenCollections
         && v10 > v13) )
      {
        Scaleform::GFx::AS3::RefCountCollector<328>::Stats::Stats(&stats, ampStats);
        Scaleform::GFx::AS3::RefCountCollector<328>::Collect(this, v7, upgradeGen, &stats);
        PresetMaxRootCount = this->PresetMaxRootCount;
        RootsFreedTotal = stats.RootsFreedTotal;
        ++this->RunsCnt;
        if ( RootsFreedTotal > PresetMaxRootCount )
        {
          this->PeakRootCount = v10;
          this->MaxRootCount = PresetMaxRootCount;
        }
        MaxRootCount = v10 - RootsFreedTotal;
        if ( v10 - RootsFreedTotal < this->MaxRootCount )
          MaxRootCount = this->MaxRootCount;
        this->MaxRootCount = MaxRootCount;
        v24 = (__int64)((double)MaxRootCount * 0.7);
        v18 = this->PeakRootCount;
        if ( v18 < (unsigned int)v24 )
          this->MaxRootCount = v24;
        pObject = stats.AdvanceStats.pObject;
        TotalFramesCount = this->TotalFramesCount;
        this->LastPeakRootCount = v18;
        v21 = stats.RootsFreedTotal;
        this->LastCollectionFrameNum = TotalFramesCount;
        this->FrameCnt = 0;
        this->LastCollectedRoots = v21;
        if ( pObject )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
      }
      v22 = this->FrameCnt;
      this->LastRootCount = v10;
      *movieFrameCnt = v22;
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
