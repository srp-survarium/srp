void __thiscall Scaleform::Render::Text::Allocator::VisitTextFormatCache(
        Scaleform::Render::Text::Allocator *this,
        Scaleform::Render::Text::Allocator::TextFormatVisitor *visitor)
{
  Scaleform::HashSetBase<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,78>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor> >::TableType *pTable; // eax
  Scaleform::HashSetLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,78,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor> > *p_TextFormatStorage; // edx
  const Scaleform::HashSetBase<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,78>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor> > *pHash; // ebx
  unsigned int Index; // esi
  unsigned int SizeMask; // ecx
  Scaleform::HashSetBase<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,78>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor> >::TableType *v7; // eax
  const Scaleform::Render::Text::TextFormat *v8; // eax
  Scaleform::HashSetBase<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,78>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor> > v9; // ecx
  unsigned int v10; // eax
  unsigned int *v11; // ecx
  Scaleform::HashSetBase<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,78>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor> >::Iterator v12; // [esp+10h] [ebp-8h] BYREF

  pTable = this->TextFormatStorage.pTable;
  p_TextFormatStorage = &this->TextFormatStorage;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    Index = 0;
    v7 = pTable + 1;
    do
    {
      if ( v7->EntryCount != -2 )
        break;
      ++Index;
      v7 = (Scaleform::HashSetBase<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,78>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor> >::TableType *)((char *)v7 + 12);
    }
    while ( Index <= SizeMask );
    pHash = p_TextFormatStorage;
  }
  else
  {
    pHash = 0;
    Index = 0;
  }
  v12.Index = Index;
  v12.pHash = pHash;
  while ( pHash && pHash->pTable && (signed int)Index <= (signed int)pHash->pTable->SizeMask )
  {
    v8 = (const Scaleform::Render::Text::TextFormat *)*(&pHash->pTable[2].EntryCount + 3 * Index);
    if ( !v8 || !visitor->Visit(visitor, v8) )
    {
      Scaleform::HashSetBase<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,78>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor>>::Iterator::RemoveAlt<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>>(
        &v12,
        (const Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat> *)&pHash->pTable[2]
      + 3 * Index);
      Index = v12.Index;
      pHash = v12.pHash;
    }
    v9.pTable = pHash->pTable;
    v10 = pHash->pTable->SizeMask;
    if ( (int)Index <= (int)v10 )
    {
      v12.Index = ++Index;
      if ( Index <= v10 )
      {
        v11 = &v9.pTable[1].EntryCount + 3 * Index;
        do
        {
          if ( *v11 != -2 )
            break;
          ++Index;
          v11 += 3;
          v12.Index = Index;
        }
        while ( Index <= v10 );
      }
    }
  }
}
