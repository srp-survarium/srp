void __thiscall Scaleform::GFx::FontManager::CleanCache(Scaleform::GFx::FontManager *this)
{
  Scaleform::HashSetLH<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *p_CreatedFonts; // edi
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *pTable; // ecx
  Scaleform::HashSetLH<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *v3; // esi
  unsigned int v4; // eax
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *v6; // ecx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *v7; // ecx
  unsigned int v8; // ecx
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> >::TableType *v9; // edx
  int v10; // ecx
  int v11; // edx

  p_CreatedFonts = &this->CreatedFonts;
  pTable = this->CreatedFonts.pTable;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v4 = 0;
    v6 = pTable + 1;
    do
    {
      if ( v6->EntryCount != -2 )
        break;
      ++v4;
      v6 += 2;
    }
    while ( v4 <= SizeMask );
    v3 = p_CreatedFonts;
  }
  else
  {
    v3 = 0;
    v4 = 0;
  }
  while ( v3 )
  {
    v7 = v3->pTable;
    if ( !v3->pTable || (signed int)v4 > (signed int)v7->SizeMask )
      break;
    *(_DWORD *)(v7[2 * v4 + 2].EntryCount + 8) = 0;
    v8 = v3->pTable->SizeMask;
    if ( (int)v4 <= (int)v8 && ++v4 <= v8 )
    {
      v9 = &v3->pTable[2 * v4 + 1];
      do
      {
        if ( v9->EntryCount != -2 )
          break;
        ++v4;
        v9 += 2;
      }
      while ( v4 <= v8 );
    }
  }
  if ( p_CreatedFonts->pTable )
  {
    v10 = 0;
    v11 = p_CreatedFonts->pTable->SizeMask + 1;
    do
    {
      if ( p_CreatedFonts->pTable[v10 + 1].EntryCount != -2 )
        p_CreatedFonts->pTable[v10 + 1].EntryCount = -2;
      v10 += 2;
      --v11;
    }
    while ( v11 );
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_CreatedFonts->pTable);
    p_CreatedFonts->pTable = 0;
  }
}
