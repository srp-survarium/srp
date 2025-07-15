void __thiscall Scaleform::GFx::AS2::MovieRoot::SetMemoryParams(
        Scaleform::GFx::AS2::MovieRoot *this,
        unsigned int frameBetweenCollections,
        unsigned int maxRootCount)
{
  Scaleform::GFx::AS2::ASRefCountCollector *pObject; // eax
  unsigned int v4; // ecx

  pObject = this->MemContext.pObject->ASGC.pObject;
  v4 = maxRootCount;
  pObject->MaxFramesBetweenCollections = frameBetweenCollections != -1 ? frameBetweenCollections : 0;
  if ( maxRootCount == -1 )
    v4 = 1000;
  pObject->PresetMaxRootCount = v4;
  pObject->MaxRootCount = v4;
}
