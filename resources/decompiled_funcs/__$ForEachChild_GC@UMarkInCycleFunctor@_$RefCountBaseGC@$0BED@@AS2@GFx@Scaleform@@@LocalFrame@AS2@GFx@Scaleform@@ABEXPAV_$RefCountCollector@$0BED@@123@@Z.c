void __thiscall Scaleform::GFx::AS2::LocalFrame::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        Scaleform::GFx::AS2::LocalFrame *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *p_Variables; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // ecx
  unsigned int v4; // eax
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v6; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v7; // ebx
  signed int v8; // esi
  unsigned int EntryCount; // eax
  char v10; // dl
  int v11; // ecx
  int v12; // eax
  unsigned int v13; // eax
  _DWORD *v14; // ecx
  Scaleform::GFx::AS2::LocalFrame *pObject; // eax

  p_Variables = &this->Variables;
  pTable = this->Variables.mHash.pTable;
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
    pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)p_Variables;
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
  pObject = this->PrevFrame.pObject;
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
  Scaleform::GFx::AS2::Value::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
    &this->Callee,
    prcc);
  Scaleform::GFx::AS2::Value::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
    &this->Caller,
    prcc);
}
