void __thiscall Scaleform::GFx::AS3::ASRefCountCollector::SetParams(
        Scaleform::GFx::AS3::ASRefCountCollector *this,
        unsigned int frameBetweenCollections,
        unsigned int maxRootCount,
        unsigned int runsToUpgradeGen,
        unsigned int runsToCollectYoung,
        unsigned int runsToCollectOld)
{
  unsigned int v6; // eax

  v6 = maxRootCount;
  this->MaxFramesBetweenCollections = frameBetweenCollections != -1 ? frameBetweenCollections : 0;
  if ( maxRootCount == -1 )
    v6 = 1000;
  this->PresetMaxRootCount = v6;
  this->MaxRootCount = v6;
  if ( runsToUpgradeGen == -1 )
    this->RunsToUpgradeGen = 5;
  else
    this->RunsToUpgradeGen = runsToUpgradeGen;
  if ( runsToCollectYoung == -1 )
    this->RunsToCollectYoung = 5;
  else
    this->RunsToCollectYoung = runsToCollectYoung;
  if ( runsToCollectOld == -1 )
    this->RunsToCollectOld = 10;
  else
    this->RunsToCollectOld = runsToCollectOld;
}
