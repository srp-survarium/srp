void __thiscall Scaleform::GFx::AS3::MovieRoot::ForceEmergencyCollect(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::ASRefCountCollector *pObject; // esi
  unsigned int PresetMaxRootCount; // edx

  pObject = this->MemContext.pObject->ASGC.pObject;
  if ( pObject->SuspendCnt )
  {
    pObject->CollectionScheduledFlags = 10;
  }
  else
  {
    Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(
      pObject,
      (Scaleform::GFx::Resource *)this->pMovieImpl->AdvanceStats.pObject,
      2u);
    PresetMaxRootCount = pObject->PresetMaxRootCount;
    pObject->PeakRootCount = 0;
    pObject->MaxRootCount = PresetMaxRootCount;
  }
}
