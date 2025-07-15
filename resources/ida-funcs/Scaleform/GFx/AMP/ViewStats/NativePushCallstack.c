void __thiscall Scaleform::GFx::AMP::ViewStats::NativePushCallstack(
        Scaleform::GFx::AMP::ViewStats *this,
        Scaleform::String functionName,
        unsigned int functionId,
        unsigned __int64 funcTime)
{
  Scaleform::Lock *p_ViewLock; // esi
  unsigned int SizeMask; // edi
  Scaleform::String::DataDesc *pData; // edi
  void *v8; // esi
  void *v9; // esi
  const Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *pHash; // ebp
  int Index; // edi
  void *v12; // esi
  Scaleform::Lock *lpCriticalSection; // [esp+Ch] [ebp-14h]
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::Iterator result; // [esp+10h] [ebp-10h] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator it; // [esp+18h] [ebp-8h] BYREF

  p_ViewLock = &this->ViewLock;
  lpCriticalSection = &this->ViewLock;
  EnterCriticalSection(&this->ViewLock.cs);
  SizeMask = functionId;
  if ( functionId == -1 )
  {
    pData = functionName.pData;
    Scaleform::String::String(&functionName, (const __m128i *)functionName.pData);
    Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::FindAlt<Scaleform::String>(
      &this->NativeFunctionIdMap.mHash,
      &result,
      &functionName);
    v8 = (void *)(functionName.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((functionName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
    it.pHash = 0;
    it.Index = 0;
    if ( Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>>::ConstIterator::operator==(
           (Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator *)&result,
           &it) )
    {
      Scaleform::GFx::AMP::ViewStats::RegisterScriptFunction(
        this,
        (Scaleform::RefCountVImpl *)1,
        this->NextNativeFunctionId,
        (const __m128i *)pData,
        0,
        0,
        0);
      Scaleform::String::String(&functionName, (const __m128i *)pData);
      Scaleform::StringHashLH<unsigned long,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Add(
        &this->NativeFunctionIdMap,
        &functionName,
        &this->NextNativeFunctionId);
      v9 = (void *)(functionName.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((functionName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
      Scaleform::String::String(&functionName, (const __m128i *)pData);
      Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::GFx::AMP::BaseMessageTypeDescriptor>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::FindAlt<Scaleform::String>(
        &this->NativeFunctionIdMap.mHash,
        (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::Iterator *)&it,
        &functionName);
      pHash = it.pHash;
      Index = it.Index;
      v12 = (void *)(functionName.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((functionName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
      ++this->NextNativeFunctionId;
      p_ViewLock = lpCriticalSection;
      SizeMask = pHash->pTable[2 * Index + 2].SizeMask;
    }
    else
    {
      p_ViewLock = lpCriticalSection;
      SizeMask = result.pHash->pTable[2 * result.Index + 2].SizeMask;
    }
  }
  else
  {
    Scaleform::GFx::AMP::ViewStats::RegisterScriptFunction(
      this,
      (Scaleform::RefCountVImpl *)1,
      functionId,
      (const __m128i *)functionName.pData,
      0,
      0,
      0);
  }
  Scaleform::GFx::AMP::ViewStats::PushCallstack(this, 1u, SizeMask, funcTime);
  LeaveCriticalSection(&p_ViewLock->cs);
}
