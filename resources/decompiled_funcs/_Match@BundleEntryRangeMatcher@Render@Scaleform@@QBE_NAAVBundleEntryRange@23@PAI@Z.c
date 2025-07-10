bool __thiscall Scaleform::Render::BundleEntryRangeMatcher::Match(
        Scaleform::Render::BundleEntryRangeMatcher *this,
        Scaleform::Render::BundleEntryRange *other,
        unsigned int *mergeDepth)
{
  Scaleform::Render::BundleEntry *pFirst; // edx
  Scaleform::Render::BundleEntry *v5; // ebp
  int v6; // edi
  char v7; // bl
  Scaleform::Render::SortKeyInterface *pImpl; // eax
  Scaleform::Render::BundleEntry *v9; // eax
  Scaleform::Render::TreeCacheNode *pSourceNode; // edx
  Scaleform::Render::SortKey *p_Key; // esi
  int v12; // eax
  Scaleform::Render::BundleEntry *pNextPattern; // eax
  Scaleform::Render::BundleEntry *p0; // [esp+8h] [ebp-2Ch]
  unsigned int matchTop; // [esp+Ch] [ebp-28h]
  Scaleform::Render::BundleEntryRangeMatcher *v16; // [esp+10h] [ebp-24h]
  unsigned int chainIndex; // [esp+14h] [ebp-20h]
  Scaleform::Render::BundleEntry **pLastEntries; // [esp+18h] [ebp-1Ch]
  Scaleform::Render::SortKey *keyStack[6]; // [esp+1Ch] [ebp-18h]

  v16 = this;
  if ( (other->Length & 0x7FFFFFFF) > (this->Length & 0x7FFFFFFF) )
    return 0;
  pFirst = this->pFirst;
  v5 = other->pFirst;
  v6 = 0;
  p0 = this->pFirst;
  if ( !this->pFirst || !v5 )
    return v5 == 0;
  matchTop = 0;
  chainIndex = 0;
  pLastEntries = this->pLastEntries;
  while ( 1 )
  {
    v7 = 0;
    if ( matchTop == v6 && pFirst->Key.Data == v5->Key.Data )
    {
      pImpl = pFirst->Key.pImpl;
      if ( pImpl == v5->Key.pImpl && (pImpl->Flags & 0x2000) != 0 )
      {
        if ( mergeDepth )
        {
          if ( chainIndex >= this->LastEntryCount || (v9 = *pLastEntries) == 0 )
            v9 = pFirst;
          for ( ; v9->pChain; v9 = v9->pChain )
            ;
          pSourceNode = v9->pSourceNode;
          v9->pChain = v5;
          v9->ChainHeight = pSourceNode->Depth - *(_WORD *)mergeDepth;
          Scaleform::Render::BundleEntryRangeMatcher::setLastEntry(this, chainIndex, v5);
          this = v16;
          pFirst = p0;
        }
        if ( v5 == other->pLast )
          v5 = 0;
        else
          v5 = v5->pNextPattern;
        v7 = 1;
      }
    }
    p_Key = &pFirst->Key;
    if ( (pFirst->Key.pImpl->Flags & 0x1000) != 0 )
    {
      if ( v6 == 6 )
        return 0;
      keyStack[v6++] = p_Key;
      if ( v7 )
        ++matchTop;
    }
    else if ( v6 )
    {
      v12 = ((int (__stdcall *)(void *, Scaleform::Render::SortKey *))keyStack[v6 - 1]->pImpl->GetRangeTransition)(
              keyStack[v6 - 1]->Data,
              p_Key);
      if ( v12 )
      {
        if ( matchTop == v6 && !v7 )
          return 0;
        if ( v12 == 2 )
        {
          if ( matchTop == v6 )
            --matchTop;
          --v6;
        }
        else
        {
          keyStack[v6 - 1] = p_Key;
        }
      }
      this = v16;
      pFirst = p0;
    }
    if ( pFirst == this->pLast )
      break;
    pNextPattern = pFirst->pNextPattern;
    ++chainIndex;
    ++pLastEntries;
    p0 = pNextPattern;
    if ( !v5 )
      break;
    pFirst = pNextPattern;
  }
  return v5 == 0;
}
