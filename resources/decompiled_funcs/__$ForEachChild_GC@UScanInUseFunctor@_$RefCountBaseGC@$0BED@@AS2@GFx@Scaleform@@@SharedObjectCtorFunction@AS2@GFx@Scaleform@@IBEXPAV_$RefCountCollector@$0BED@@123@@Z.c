void __thiscall Scaleform::GFx::AS2::SharedObjectCtorFunction::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        Scaleform::GFx::AS2::SharedObjectCtorFunction *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // ecx
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::SharedObjectPtr> *p_SharedObjects; // esi
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::SharedObjectPtr> *v5; // edx
  unsigned int v6; // eax
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v8; // ecx
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::SharedObjectPtr> *v9; // edi
  signed int v10; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v11; // eax
  unsigned int v12; // eax
  int v13; // esi
  unsigned int v14; // esi
  unsigned int v15; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v16; // edx

  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(this, prcc);
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
    v13 = ++*(_DWORD *)(v12 + 12);
    if ( (v13 & 0x70000000) != 0 )
    {
      v14 = v13 & 0x8FFFFFFF;
      *(_DWORD *)(v12 + 12) = v14;
      if ( (v14 & 0x8000000) != 0 )
      {
        *(_DWORD *)(*(_DWORD *)(v12 + 8) + 4) = *(_DWORD *)(v12 + 4);
        *(_DWORD *)(*(_DWORD *)(v12 + 4) + 8) = *(_DWORD *)(v12 + 8);
        *(_DWORD *)(v12 + 8) = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
        *(_DWORD *)(v12 + 4) = prcc->pLastPtr->pRCC;
        *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = v12;
        prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v12;
      }
    }
    v15 = v9->mHash.pTable->SizeMask;
    if ( v10 <= (int)v15 && ++v10 <= v15 )
    {
      v16 = &v9->mHash.pTable[2 * v10 + 1];
      do
      {
        if ( v16->EntryCount != -2 )
          break;
        ++v10;
        v16 += 2;
      }
      while ( v10 <= v15 );
    }
  }
}
