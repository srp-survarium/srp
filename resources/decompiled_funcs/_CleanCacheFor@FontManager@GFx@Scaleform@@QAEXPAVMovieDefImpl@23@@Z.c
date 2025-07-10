void __thiscall Scaleform::GFx::FontManager::CleanCacheFor(
        Scaleform::GFx::FontManager *this,
        Scaleform::GFx::MovieDefImpl *pdefImpl)
{
  Scaleform::HashSetLH<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *p_CreatedFonts; // esi
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *pTable; // ecx
  unsigned int Index; // eax
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *v6; // ecx
  unsigned int EntryCount; // edx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > v8; // edx
  unsigned int v9; // ecx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *v10; // edx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::Iterator it; // [esp+Ch] [ebp-8h] BYREF

  p_CreatedFonts = &this->CreatedFonts;
  pTable = this->CreatedFonts.pTable;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    Index = 0;
    v6 = pTable + 1;
    do
    {
      if ( v6->EntryCount != -2 )
        break;
      ++Index;
      v6 += 2;
    }
    while ( Index <= SizeMask );
  }
  else
  {
    p_CreatedFonts = 0;
    Index = 0;
  }
  it.Index = Index;
  it.pHash = p_CreatedFonts;
  while ( p_CreatedFonts && p_CreatedFonts->pTable && (signed int)Index <= (signed int)p_CreatedFonts->pTable->SizeMask )
  {
    EntryCount = p_CreatedFonts->pTable[2 * Index + 2].EntryCount;
    if ( *(Scaleform::GFx::MovieDefImpl **)(EntryCount + 28) == pdefImpl )
    {
      *(_DWORD *)(EntryCount + 8) = 0;
      Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Iterator::RemoveAlt<Scaleform::GFx::FontManager::NodePtr>(
        &it,
        (const Scaleform::GFx::FontManager::NodePtr *)&p_CreatedFonts->pTable[2 * Index + 2]);
      Index = it.Index;
      p_CreatedFonts = (Scaleform::HashSetLH<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)it.pHash;
    }
    v8.pTable = p_CreatedFonts->pTable;
    v9 = p_CreatedFonts->pTable->SizeMask;
    if ( (int)Index <= (int)v9 )
    {
      it.Index = ++Index;
      if ( Index <= v9 )
      {
        v10 = &v8.pTable[2 * Index + 1];
        do
        {
          if ( v10->EntryCount != -2 )
            break;
          ++Index;
          v10 += 2;
          it.Index = Index;
        }
        while ( Index <= v9 );
      }
    }
  }
}
