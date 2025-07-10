void __thiscall Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::Object *v2; // ebp
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // ecx
  unsigned int v4; // eax
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v6; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v7; // ebx
  signed int v8; // esi
  unsigned int EntryCount; // eax
  char v10; // dl
  int v11; // ecx
  int v12; // eax
  unsigned int v13; // eax
  _DWORD *v14; // ecx
  Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > > *pWatchpoints; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *v16; // eax
  const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *pHash; // ebp
  int Index; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v19; // eax
  int v20; // ebx
  char v21; // cl
  int v22; // eax
  unsigned int v23; // eax
  unsigned int *v24; // ecx
  Scaleform::GFx::AS2::Object *pObject; // eax
  Scaleform::GFx::AS2::Object *v26; // [esp+10h] [ebp-Ch]
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator result; // [esp+14h] [ebp-8h] BYREF

  v2 = this;
  pTable = this->Members.mHash.pTable;
  v26 = v2;
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
      v6 += 3;
    }
    while ( v4 <= SizeMask );
    pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)&v2->Members;
  }
  else
  {
    v4 = 0;
  }
  v7 = pTable;
  v8 = v4;
  while ( v7 )
  {
    EntryCount = v7->EntryCount;
    if ( !v7->EntryCount || v8 > *(_DWORD *)(EntryCount + 4) )
      break;
    v10 = *(_BYTE *)(EntryCount + 24 * v8 + 16);
    v11 = EntryCount + 24 * v8 + 16;
    if ( v10 == 8 )
    {
      Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        (Scaleform::GFx::AS2::FunctionRefBase *)(EntryCount + 24 * v8 + 20),
        prcc);
      goto LABEL_21;
    }
    if ( v10 == 6 && (v12 = *(_DWORD *)(EntryCount + 24 * v8 + 20)) != 0 )
    {
      if ( (--*(_DWORD *)(v12 + 12) & 0x8000000) != 0 )
        goto LABEL_21;
      *(_DWORD *)(v12 + 8) = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
      *(_DWORD *)(v12 + 4) = prcc->pLastPtr->pRCC;
      *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = v12;
      prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v12;
    }
    else
    {
      if ( v10 != 9 )
        goto LABEL_21;
      v12 = *(_DWORD *)(v11 + 4);
      if ( (--*(_DWORD *)(v12 + 12) & 0x8000000) != 0 )
        goto LABEL_21;
      *(_DWORD *)(v12 + 8) = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
      *(_DWORD *)(v12 + 4) = prcc->pLastPtr->pRCC;
      *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = v12;
      prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v12;
    }
    prcc->pLastPtr = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v12;
    *(_DWORD *)(v12 + 12) |= 0x8000000u;
LABEL_21:
    v13 = *(_DWORD *)(v7->EntryCount + 4);
    if ( v8 <= (int)v13 && ++v8 <= v13 )
    {
      v14 = (_DWORD *)(v7->EntryCount + 24 * v8 + 8);
      do
      {
        if ( *v14 != -2 )
          break;
        ++v8;
        v14 += 6;
      }
      while ( v8 <= v13 );
    }
  }
  Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
    &v2->ResolveHandler,
    prcc);
  pWatchpoints = v2->pWatchpoints;
  if ( pWatchpoints )
  {
    v16 = Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Begin(
            pWatchpoints,
            &result);
    pHash = v16->pHash;
    Index = v16->Index;
    while ( 1 )
    {
      if ( !pHash || (v19 = pHash->pTable) == 0 || Index > (signed int)v19->SizeMask )
      {
        v2 = v26;
        break;
      }
      v20 = (int)&v19[2] + 36 * Index;
      Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        (Scaleform::GFx::AS2::FunctionRefBase *)v20,
        prcc);
      v21 = *(_BYTE *)(v20 + 12);
      if ( v21 == 8 )
      {
        Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
          (Scaleform::GFx::AS2::FunctionRefBase *)(v20 + 16),
          prcc);
        goto LABEL_42;
      }
      if ( v21 == 6 && (v22 = *(_DWORD *)(v20 + 16)) != 0 )
      {
        if ( (--*(_DWORD *)(v22 + 12) & 0x8000000) != 0 )
          goto LABEL_42;
        *(_DWORD *)(v22 + 8) = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
        *(_DWORD *)(v22 + 4) = prcc->pLastPtr->pRCC;
        *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = v22;
        prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v22;
      }
      else
      {
        if ( v21 != 9 )
          goto LABEL_42;
        v22 = *(_DWORD *)(v20 + 16);
        if ( (--*(_DWORD *)(v22 + 12) & 0x8000000) != 0 )
          goto LABEL_42;
        *(_DWORD *)(v22 + 8) = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
        *(_DWORD *)(v22 + 4) = prcc->pLastPtr->pRCC;
        *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = v22;
        prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v22;
      }
      prcc->pLastPtr = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v22;
      *(_DWORD *)(v22 + 12) |= 0x8000000u;
LABEL_42:
      v23 = pHash->pTable->SizeMask;
      if ( Index <= (int)v23 && ++Index <= v23 )
      {
        v24 = &pHash->pTable[1].EntryCount + 9 * Index;
        do
        {
          if ( *v24 != -2 )
            break;
          ++Index;
          v24 += 9;
        }
        while ( Index <= v23 );
      }
    }
  }
  pObject = v2->pProto.pObject;
  if ( pObject )
  {
    if ( (--pObject->RefCount & 0x8000000) == 0 )
    {
      pObject->RootIndex = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
      pObject->pRCC = prcc->pLastPtr->pRCC;
      *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = pObject;
      prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)pObject;
      prcc->pLastPtr = pObject;
      pObject->RefCount |= 0x8000000u;
    }
  }
}
