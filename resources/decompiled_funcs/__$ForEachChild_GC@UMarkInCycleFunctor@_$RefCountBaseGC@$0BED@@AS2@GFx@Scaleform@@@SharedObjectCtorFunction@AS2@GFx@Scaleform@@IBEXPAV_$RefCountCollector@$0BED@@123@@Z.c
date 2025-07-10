void __thiscall Scaleform::GFx::AS2::SharedObjectCtorFunction::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        Scaleform::GFx::AS2::SharedObjectCtorFunction *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // ecx
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::SharedObjectPtr> *p_SharedObjects; // esi
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::SharedObjectPtr> *v5; // edx
  unsigned int v6; // eax
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v8; // ecx
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::SharedObjectPtr> *v9; // esi
  signed int v10; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v14; // edx

  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(this, prcc);
  pTable = this->SharedObjects.mHash.pTable;
  p_SharedObjects = &this->SharedObjects;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v6 = 0;
    v8 = pTable + 1;
    do
    {
      if ( v8->EntryCount != -2 )
        break;
      ++v6;
      v8 += 2;
    }
    while ( v6 <= SizeMask );
    v5 = p_SharedObjects;
  }
  else
  {
    v5 = 0;
    v6 = 0;
  }
  v9 = v5;
  v10 = v6;
  while ( v9 )
  {
    v11 = v9->mHash.pTable;
    if ( !v9->mHash.pTable || v10 > (signed int)v11->SizeMask )
      break;
    v12 = v11[2 * v10 + 2].SizeMask;
    if ( (--*(_DWORD *)(v12 + 12) & 0x8000000) == 0 )
    {
      *(_DWORD *)(v12 + 8) = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
      *(_DWORD *)(v12 + 4) = prcc->pLastPtr->pRCC;
      *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = v12;
      prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v12;
      prcc->pLastPtr = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v12;
      *(_DWORD *)(v12 + 12) |= 0x8000000u;
    }
    v13 = v9->mHash.pTable->SizeMask;
    if ( v10 <= (int)v13 && ++v10 <= v13 )
    {
      v14 = &v9->mHash.pTable[2 * v10 + 1];
      do
      {
        if ( v14->EntryCount != -2 )
          break;
        ++v10;
        v14 += 2;
      }
      while ( v10 <= v13 );
    }
  }
}
