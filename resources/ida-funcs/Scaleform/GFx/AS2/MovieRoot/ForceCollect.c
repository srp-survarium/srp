void __thiscall Scaleform::GFx::AS2::MovieRoot::ForceCollect(
        Scaleform::GFx::AS2::MovieRoot *this,
        unsigned int __formal)
{
  Scaleform::GFx::AS2::ASRefCountCollector *pObject; // esi
  unsigned int Size; // edi
  unsigned int PeakRootCount; // eax
  Scaleform::GFx::AS2::RefCountCollector<323>::Stats v5; // [esp+8h] [ebp-8h] BYREF

  pObject = this->MemContext.pObject->ASGC.pObject;
  Size = pObject->Roots.Size;
  v5.RootsFreedTotal = 0;
  v5.RootsNumber = 0;
  Scaleform::GFx::AS2::RefCountCollector<323>::Collect(pObject, &v5);
  PeakRootCount = pObject->PeakRootCount;
  pObject->FrameCnt = 0;
  pObject->LastRootCount = Size;
  if ( Size >= PeakRootCount )
    pObject->PeakRootCount = Size;
  else
    pObject->PeakRootCount = PeakRootCount;
}
