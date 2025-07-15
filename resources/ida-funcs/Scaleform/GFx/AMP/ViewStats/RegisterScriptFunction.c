void __thiscall Scaleform::GFx::AMP::ViewStats::RegisterScriptFunction(
        Scaleform::GFx::AMP::ViewStats *this,
        Scaleform::RefCountVImpl *swdHandle,
        unsigned int swfOffset,
        const __m128i *name,
        unsigned int byteCodeLength,
        unsigned int asVersion,
        bool updateSource)
{
  Scaleform::HashLH<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_FunctionInfoMap; // ebx
  signed int Index; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > v10; // ecx
  Scaleform::StringLH *v11; // eax
  Scaleform::StringLH *v12; // edi
  bool v13; // zf
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // ecx
  unsigned int v17; // eax
  Scaleform::Lock *v18; // ebp
  unsigned int ActiveLineNumber; // esi
  unsigned int v20; // eax
  _DWORD *EntryCount; // ebx
  Scaleform::Lock *p_ActiveLock; // edi
  int ActiveFileId; // ebp
  int ActiveFileId_high; // esi
  Scaleform::RefCountVImpl *v25; // eax
  Scaleform::RefCountVImpl *v26; // ecx
  Scaleform::HashLH<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *v27; // [esp+10h] [ebp-1Ch]
  unsigned __int64 key; // [esp+14h] [ebp-18h] BYREF
  Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef v29; // [esp+1Ch] [ebp-10h] BYREF
  unsigned int v30; // [esp+28h] [ebp-4h]

  p_FunctionInfoMap = &this->FunctionInfoMap;
  key = swfOffset + ((unsigned __int64)(unsigned int)swdHandle << 32);
  v27 = &this->FunctionInfoMap;
  Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
            (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&this->FunctionInfoMap,
            &key);
  if ( Index >= 0
    && this != (Scaleform::GFx::AMP::ViewStats *)-12
    && (v10.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)p_FunctionInfoMap->mHash.pTable) != 0
    && Index <= (signed int)v10.pTable->SizeMask )
  {
    EntryCount = (_DWORD *)v10.pTable[3 * Index + 3].EntryCount;
    p_ActiveLock = &this->ActiveLock;
    EnterCriticalSection(&this->ActiveLock.cs);
    swdHandle = (Scaleform::RefCountVImpl *)this->ActiveLineNumber;
    LeaveCriticalSection(&this->ActiveLock.cs);
    if ( updateSource && swdHandle )
    {
      EnterCriticalSection(&this->ActiveLock.cs);
      ActiveFileId = this->ActiveFileId;
      ActiveFileId_high = HIDWORD(this->ActiveFileId);
      LeaveCriticalSection(&p_ActiveLock->cs);
      v25 = (Scaleform::RefCountVImpl *)EntryCount[6];
      v26 = swdHandle;
      EntryCount[4] = ActiveFileId;
      EntryCount[5] = ActiveFileId_high;
      if ( v25 )
      {
        if ( v25 >= v26 )
          v25 = v26;
        EntryCount[6] = v25;
      }
      else
      {
        EntryCount[6] = v26;
      }
    }
  }
  else
  {
    swfOffset = 578;
    v11 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                   Scaleform::Memory::pGlobalHeap,
                                   this,
                                   32,
                                   &swfOffset);
    v12 = v11;
    if ( v11 )
    {
      v11->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
      v11[1].HeapTypeBits = 1;
      v11->HeapTypeBits = (unsigned int)&Scaleform::GFx::AMP::Server::SourceFileInfo::`vftable';
      Scaleform::StringLH::StringLH(v11 + 2);
    }
    else
    {
      v12 = 0;
    }
    Scaleform::String::operator=(v12 + 2, name);
    v13 = !updateSource;
    v14 = asVersion;
    v12[3].HeapTypeBits = byteCodeLength;
    v12[7].HeapTypeBits = v14;
    if ( v13 )
    {
      v17 = 0;
      v16 = 0;
    }
    else
    {
      EnterCriticalSection(&this->ActiveLock.cs);
      v15 = this->ActiveFileId;
      v30 = HIDWORD(this->ActiveFileId);
      LeaveCriticalSection(&this->ActiveLock.cs);
      v16 = v30;
      v17 = v15;
      p_FunctionInfoMap = v27;
    }
    v13 = !updateSource;
    v12[4].HeapTypeBits = v17;
    v12[5].HeapTypeBits = v16;
    if ( v13 )
    {
      v20 = 0;
    }
    else
    {
      v18 = &this->ActiveLock;
      EnterCriticalSection(&this->ActiveLock.cs);
      ActiveLineNumber = this->ActiveLineNumber;
      LeaveCriticalSection(&v18->cs);
      v20 = ActiveLineNumber;
    }
    v12[6].HeapTypeBits = v20;
    swdHandle = (Scaleform::RefCountVImpl *)v12;
    v29.pFirst = &key;
    v29.pSecond = (const Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes> *)&swdHandle;
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)p_FunctionInfoMap,
      p_FunctionInfoMap,
      &v29);
    if ( swdHandle )
      Scaleform::RefCountImpl::Release(swdHandle);
  }
}
