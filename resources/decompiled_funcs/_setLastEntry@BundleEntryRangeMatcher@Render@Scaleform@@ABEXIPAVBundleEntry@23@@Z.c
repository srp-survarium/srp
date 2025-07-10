void __thiscall Scaleform::Render::BundleEntryRangeMatcher::setLastEntry(
        Scaleform::Render::BundleEntryRangeMatcher *this,
        unsigned int index,
        Scaleform::Render::BundleEntry *entry)
{
  unsigned int LastEntryCount; // edx

  LastEntryCount = this->LastEntryCount;
  if ( index >= LastEntryCount )
  {
    if ( index >= 8 )
      return;
    if ( LastEntryCount < index )
    {
      do
        this->pLastEntries[this->LastEntryCount++] = 0;
      while ( this->LastEntryCount < index );
    }
    ++this->LastEntryCount;
  }
  this->pLastEntries[index] = entry;
}
