void __thiscall Scaleform::GFx::AS3::ASRefCountCollector::ASRefCountCollector(
        Scaleform::GFx::AS3::ASRefCountCollector *this)
{
  Scaleform::GFx::AS3::RefCountCollector<328>::RefCountCollector<328>(this);
  this->FrameCnt = 0;
  this->PeakRootCount = 0;
  this->LastRootCount = 0;
  this->LastCollectedRoots = 0;
  this->LastPeakRootCount = 0;
  this->TotalFramesCount = 0;
  this->LastCollectionFrameNum = 0;
  this->CollectionScheduledFlags = 0;
  this->SuspendCnt = 0;
  this->RunsCnt = 0;
  this->MaxFramesBetweenCollections = 0;
  this->MaxRootCount = 1000;
  this->PresetMaxRootCount = 1000;
  this->RunsToUpgradeGen = 5;
  this->RunsToCollectYoung = 5;
  this->__vftable = (Scaleform::GFx::AS3::ASRefCountCollector_vtbl *)&Scaleform::GFx::AS3::ASRefCountCollector::`vftable';
  this->RunsToCollectOld = 10;
}
