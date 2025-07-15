void __thiscall Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(
        Scaleform::GFx::AS3::ASRefCountCollector *this,
        Scaleform::GFx::Resource *ampStats,
        unsigned int collectFlags)
{
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // ecx
  unsigned int v5; // edi
  unsigned int PeakRootCount; // eax
  unsigned int v7; // ecx
  bool v8; // zf
  BOOL upgradeGen; // [esp+4h] [ebp-20h] BYREF
  unsigned int curRootCount; // [esp+8h] [ebp-1Ch]
  Scaleform::GFx::AS3::RefCountCollector<328>::Stats stats; // [esp+Ch] [ebp-18h] BYREF

  if ( !this->SuspendCnt )
  {
    LOBYTE(upgradeGen) = 0;
    v5 = Scaleform::GFx::AS3::ASRefCountCollector::CheckGenerations(this, (bool *)&upgradeGen);
    if ( (collectFlags & 3) != 0 )
    {
      this->Flags |= 0x20u;
      v5 = 2;
    }
    else
    {
      LOBYTE(upgradeGen) = 0;
      if ( (collectFlags & 0x20) != 0 )
      {
        v5 = 2;
      }
      else if ( (collectFlags & 0x10) != 0 )
      {
        v5 = 1;
      }
      else if ( (collectFlags & 8) != 0 )
      {
        v5 = 0;
      }
    }
    curRootCount = Scaleform::GFx::AS3::RefCountCollector<328>::GetRootsCount(v4, v5);
    if ( ampStats )
      Scaleform::RefCountImpl::AddRef(ampStats);
    stats.AdvanceStats.pObject = (Scaleform::AmpStats *)ampStats;
    memset(&stats.RootsNumber, 0, 20);
    Scaleform::GFx::AS3::RefCountCollector<328>::Collect(this, v5, upgradeGen, &stats);
    if ( (collectFlags & 3) != 0 )
      ++this->RunsCnt;
    PeakRootCount = this->PeakRootCount;
    v7 = curRootCount;
    this->FrameCnt = 0;
    if ( v7 >= PeakRootCount )
      PeakRootCount = v7;
    v8 = (this->Flags & 0x10) == 0;
    this->PeakRootCount = PeakRootCount;
    this->LastRootCount = v7;
    if ( !v8 )
      this->CollectionScheduledFlags = collectFlags & 0xFFFFFFF0 | 8;
    if ( stats.AdvanceStats.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)stats.AdvanceStats.pObject);
  }
}
