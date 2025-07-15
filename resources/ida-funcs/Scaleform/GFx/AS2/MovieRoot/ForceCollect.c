void __thiscall Scaleform::GFx::AS2::MovieRoot::ForceCollect(
        Scaleform::GFx::AS2::MovieRoot *this,
        unsigned int __formal)
{
  Scaleform::GFx::AS2::ASRefCountCollector *pObject; // esi
  unsigned int Size; // edi
  unsigned int PeakRootCount; // eax
  Scaleform::GFx::AS2::RefCountCollector<323>::Stats pstat; // [esp+8h] [ebp-8h] BYREF

  pObject = this->MemContext.pObject->ASGC.pObject;
  Size = pObject->Roots.Size;
  pstat.RootsFreedTotal = 0;
  pstat.RootsNumber = 0;
  Scaleform::GFx::AS2::RefCountCollector<323>::Collect(pObject, &pstat);
  PeakRootCount = pObject->PeakRootCount;
  pObject->FrameCnt = 0;
  pObject->LastRootCount = Size;
  if ( Size >= PeakRootCount )
    pObject->PeakRootCount = Size;
  else
    pObject->PeakRootCount = PeakRootCount;
}
