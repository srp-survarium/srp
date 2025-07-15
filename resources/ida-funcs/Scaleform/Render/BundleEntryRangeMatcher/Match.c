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
  Scaleform::Render::BundleEntry *v14; // [esp+8h] [ebp-2Ch]
  int v15; // [esp+Ch] [ebp-28h]
  Scaleform::Render::BundleEntryRangeMatcher *v16; // [esp+10h] [ebp-24h]
  unsigned int index; // [esp+14h] [ebp-20h]
  _DWORD v18[7]; // [esp+18h] [ebp-1Ch]

  v16 = this;
  if ( (other->Length & 0x7FFFFFFF) > (this->Length & 0x7FFFFFFF) )
    return 0;
  pFirst = this->pFirst;
  v5 = other->pFirst;
  v6 = 0;
  v14 = this->pFirst;
  if ( !this->pFirst || !v5 )
    return v5 == 0;
  v15 = 0;
  index = 0;
  v18[0] = this->pLastEntries;
  while ( 1 )
  {
    v7 = 0;
    if ( v15 == v6 && pFirst->Key.Data == v5->Key.Data )
    {
      pImpl = pFirst->Key.pImpl;
      if ( pImpl == v5->Key.pImpl && (pImpl->Flags & 0x2000) != 0 )
      {
        if ( mergeDepth )
        {
          if ( index >= this->LastEntryCount || (v9 = *(Scaleform::Render::BundleEntry **)v18[0]) == 0 )
            v9 = pFirst;
          for ( ; v9->pChain; v9 = v9->pChain )
            ;
          pSourceNode = v9->pSourceNode;
          v9->pChain = v5;
          v9->ChainHeight = pSourceNode->Depth - *(_WORD *)mergeDepth;
          Scaleform::Render::BundleEntryRangeMatcher::setLastEntry(this, index, v5);
          this = v16;
          pFirst = v14;
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
      v18[++v6] = p_Key;
      if ( v7 )
        ++v15;
    }
    else if ( v6 )
    {
      v12 = (*(int (__stdcall **)(_DWORD, Scaleform::Render::SortKey *))(**(_DWORD **)v18[v6] + 12))(
              *(_DWORD *)(v18[v6] + 4),
              p_Key);
      if ( v12 )
      {
        if ( v15 == v6 && !v7 )
          return 0;
        if ( v12 == 2 )
        {
          if ( v15 == v6 )
            --v15;
          --v6;
        }
        else
        {
          v18[v6] = p_Key;
        }
      }
      this = v16;
      pFirst = v14;
    }
    if ( pFirst == this->pLast )
      break;
    pNextPattern = pFirst->pNextPattern;
    ++index;
    v18[0] += 4;
    v14 = pNextPattern;
    if ( !v5 )
      break;
    pFirst = pNextPattern;
  }
  return v5 == 0;
}
