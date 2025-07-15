Scaleform::GFx::Resource *__thiscall Scaleform::GFx::MovieDefImpl::GetResource(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::Resource *pexportName)
{
  Scaleform::GFx::Resource *v2; // eax
  Scaleform::GFx::MovieDataDef *pObject; // ecx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // eax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v6; // ebx
  const Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *pHash; // ebp
  int Index; // esi
  void *v9; // esi
  Scaleform::GFx::Resource *Resource; // esi
  void *v11; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator key; // [esp+4h] [ebp-10h] BYREF
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::Iterator result; // [esp+Ch] [ebp-8h] BYREF

  v2 = pexportName;
  if ( pexportName )
  {
    Scaleform::String::String((Scaleform::String *)&pexportName, (const __m128i *)pexportName);
    pObject = this->pBindData.pObject->pDataDef.pObject;
    v5 = pObject->pData.pObject;
    v6 = 0;
    if ( v5->LoadState < LS_LoadFinished )
    {
      v6 = pObject->pData.pObject;
      EnterCriticalSection(&v5->ResourceLock.cs);
    }
    key.pHash = (const Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)&pexportName;
    Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::FindAlt<Scaleform::String::NoCaseKey>(
      &this->pBindData.pObject->pDataDef.pObject->pData.pObject->Exports.mHash,
      &result,
      (const Scaleform::String::NoCaseKey *)&key);
    pHash = result.pHash;
    Index = result.Index;
    key = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator)result;
    result.pHash = 0;
    result.Index = 0;
    if ( Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>>::ConstIterator::operator==(
           &key,
           (const Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator *)&result) )
    {
      if ( v6 )
        LeaveCriticalSection(&v6->ResourceLock.cs);
      v9 = (void *)((unsigned int)pexportName & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)pexportName & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
      return 0;
    }
    else
    {
      Resource = Scaleform::GFx::ResourceHandle::GetResource(
                   (Scaleform::GFx::ResourceHandle *)(&pHash->pTable[2].SizeMask + 5 * Index),
                   &this->pBindData.pObject->ResourceBinding);
      if ( v6 )
        LeaveCriticalSection(&v6->ResourceLock.cs);
      v11 = (void *)((unsigned int)pexportName & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)pexportName & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
      return Resource;
    }
  }
  return v2;
}
