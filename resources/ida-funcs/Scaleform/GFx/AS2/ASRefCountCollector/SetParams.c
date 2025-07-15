void __thiscall Scaleform::GFx::AS2::ASRefCountCollector::SetParams(
        Scaleform::GFx::AS2::ASRefCountCollector *this,
        unsigned int frameBetweenCollections,
        unsigned int maxRootCount)
{
  unsigned int v3; // eax

  v3 = maxRootCount;
  this->MaxFramesBetweenCollections = frameBetweenCollections != -1 ? frameBetweenCollections : 0;
  if ( maxRootCount == -1 )
    v3 = 1000;
  this->PresetMaxRootCount = v3;
  this->MaxRootCount = v3;
}
