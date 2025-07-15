Scaleform::ArrayLH<unsigned __int64,2,Scaleform::ArrayDefaultPolicy> *__thiscall Scaleform::GFx::AMP::ViewStats::LockBufferInstructionTimes(
        Scaleform::GFx::AMP::ViewStats *this,
        unsigned int swdHandle,
        unsigned int swfBufferOffset,
        unsigned int bufferLength)
{
  Scaleform::HashLH<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_InstructionTimingsMap; // esi
  signed int Index; // eax
  Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes *v7; // eax
  Scaleform::RefCountVImpl *v8; // eax
  unsigned __int64 key; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef v11; // [esp+14h] [ebp-8h] BYREF

  Scaleform::Mutex::DoLock(&this->InstructionTimingMutex);
  p_InstructionTimingsMap = &this->InstructionTimingsMap;
  key = swfBufferOffset + ((unsigned __int64)swdHandle << 32);
  Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
            &this->InstructionTimingsMap.mHash,
            &key);
  if ( Index < 0
    || this == (Scaleform::GFx::AMP::ViewStats *)-92
    || !p_InstructionTimingsMap->mHash.pTable
    || Index > (signed int)p_InstructionTimingsMap->mHash.pTable->SizeMask )
  {
    swdHandle = 582;
    v7 = (Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                     Scaleform::Memory::pGlobalHeap,
                                                                     this,
                                                                     20,
                                                                     &swdHandle);
    if ( v7 )
      Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes::BufferInstructionTimes(v7, bufferLength);
    else
      v8 = 0;
    swdHandle = (unsigned int)v8;
    v11.pFirst = &key;
    v11.pSecond = (const Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes> *)&swdHandle;
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
      &this->InstructionTimingsMap.mHash,
      &this->InstructionTimingsMap,
      &v11);
    if ( swdHandle )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)swdHandle);
    Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
              &this->InstructionTimingsMap.mHash,
              &key);
    if ( Index < 0 )
    {
      p_InstructionTimingsMap = 0;
      Index = 0;
    }
  }
  return (Scaleform::ArrayLH<unsigned __int64,2,Scaleform::ArrayDefaultPolicy> *)(p_InstructionTimingsMap->mHash.pTable[3 * Index + 3].EntryCount
                                                                                + 8);
}
