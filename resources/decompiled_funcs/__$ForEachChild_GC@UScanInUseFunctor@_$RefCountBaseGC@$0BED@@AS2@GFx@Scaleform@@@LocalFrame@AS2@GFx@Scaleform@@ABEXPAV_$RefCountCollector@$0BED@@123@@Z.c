void __thiscall Scaleform::GFx::AS2::LocalFrame::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        Scaleform::GFx::AS2::LocalFrame *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *p_Variables; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // ecx
  unsigned int v4; // eax
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v6; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v7; // ebp
  signed int v8; // esi
  unsigned int EntryCount; // eax
  int v10; // edx
  char v11; // cl
  int v12; // eax
  int v13; // ecx
  unsigned int v14; // ecx
  int v15; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v16; // eax
  unsigned int v17; // ecx
  int v18; // ecx
  unsigned int v19; // ecx
  unsigned int v20; // eax
  _DWORD *v21; // ecx
  Scaleform::GFx::AS2::LocalFrame *pObject; // eax
  unsigned int v23; // ecx
  unsigned __int8 Type; // cl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObjectValue; // eax
  unsigned int v26; // ecx
  unsigned __int8 v27; // cl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v28; // eax
  unsigned int v29; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *it; // [esp+10h] [ebp-8h]

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
  it = pTable;
  v8 = v4;
  while ( v7 )
  {
    EntryCount = v7->EntryCount;
    if ( !v7->EntryCount || v8 > *(_DWORD *)(EntryCount + 4) )
      break;
    v10 = EntryCount + 24 * v8 + 16;
    v11 = *(_BYTE *)v10;
    if ( *(_BYTE *)v10 == 8 )
    {
      v12 = *(_DWORD *)(EntryCount + 24 * v8 + 20);
      if ( v12 )
      {
        v13 = ++*(_DWORD *)(v12 + 12);
        if ( (v13 & 0x70000000) != 0 )
        {
          v14 = v13 & 0x8FFFFFFF;
          *(_DWORD *)(v12 + 12) = v14;
          if ( (v14 & 0x8000000) != 0 )
          {
            *(_DWORD *)(*(_DWORD *)(v12 + 8) + 4) = *(_DWORD *)(v12 + 4);
            *(_DWORD *)(*(_DWORD *)(v12 + 4) + 8) = *(_DWORD *)(v12 + 8);
            v7 = it;
            *(_DWORD *)(v12 + 8) = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
            *(_DWORD *)(v12 + 4) = prcc->pLastPtr->pRCC;
            *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = v12;
            prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v12;
          }
        }
      }
      v15 = *(_DWORD *)(v10 + 8);
      if ( v15 )
        goto LABEL_24;
    }
    else
    {
      if ( v11 != 6 || (v16 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(EntryCount + 24 * v8 + 20)) == 0 )
      {
        if ( v11 != 9 )
          goto LABEL_27;
        v15 = *(_DWORD *)(v10 + 4);
LABEL_24:
        v18 = ++*(_DWORD *)(v15 + 12);
        if ( (v18 & 0x70000000) != 0 )
        {
          v19 = v18 & 0x8FFFFFFF;
          *(_DWORD *)(v15 + 12) = v19;
          if ( (v19 & 0x8000000) != 0 )
          {
            *(_DWORD *)(*(_DWORD *)(v15 + 8) + 4) = *(_DWORD *)(v15 + 4);
            *(_DWORD *)(*(_DWORD *)(v15 + 4) + 8) = *(_DWORD *)(v15 + 8);
            *(_DWORD *)(v15 + 8) = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
            *(_DWORD *)(v15 + 4) = prcc->pLastPtr->pRCC;
            *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = v15;
            prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v15;
          }
        }
        goto LABEL_27;
      }
      v17 = ++v16->RefCount;
      if ( (v17 & 0x70000000) != 0 )
      {
        v16->RefCount = v17 & 0x8FFFFFFF;
        Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, v16);
      }
    }
LABEL_27:
    v20 = *(_DWORD *)(v7->EntryCount + 4);
    if ( v8 <= (int)v20 && ++v8 <= v20 )
    {
      v21 = (_DWORD *)(v7->EntryCount + 24 * v8 + 8);
      do
      {
        if ( *v21 != -2 )
          break;
        ++v8;
        v21 += 6;
      }
      while ( v8 <= v20 );
    }
  }
  pObject = this->PrevFrame.pObject;
  if ( pObject )
  {
    v23 = ++pObject->RefCount;
    if ( (v23 & 0x70000000) != 0 )
    {
      pObject->RefCount = v23 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, pObject);
    }
  }
  Type = this->Callee.T.Type;
  if ( Type == 8 )
  {
    Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
      &this->Callee.V.FunctionValue,
      prcc);
    goto LABEL_44;
  }
  if ( Type == 6 && (pObjectValue = this->Callee.V.pObjectValue) != 0 )
  {
LABEL_42:
    v26 = ++pObjectValue->RefCount;
    if ( (v26 & 0x70000000) != 0 )
    {
      pObjectValue->RefCount = v26 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, pObjectValue);
    }
  }
  else if ( Type == 9 )
  {
    pObjectValue = this->Callee.V.pObjectValue;
    goto LABEL_42;
  }
LABEL_44:
  v27 = this->Caller.T.Type;
  if ( v27 == 8 )
  {
    Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
      &this->Caller.V.FunctionValue,
      prcc);
    return;
  }
  if ( v27 == 6 && (v28 = this->Caller.V.pObjectValue) != 0 )
  {
LABEL_50:
    v29 = ++v28->RefCount;
    if ( (v29 & 0x70000000) != 0 )
    {
      v28->RefCount = v29 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, v28);
    }
  }
  else if ( v27 == 9 )
  {
    v28 = this->Caller.V.pObjectValue;
    goto LABEL_50;
  }
}
