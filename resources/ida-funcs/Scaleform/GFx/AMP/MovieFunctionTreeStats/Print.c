void __thiscall Scaleform::GFx::AMP::MovieFunctionTreeStats::Print(
        Scaleform::GFx::AMP::MovieFunctionTreeStats *this,
        Scaleform::Log *log)
{
  int v3; // ebp
  Scaleform::RefCountVImpl *v4; // ebx
  const unsigned __int64 *v5; // ecx
  int v6; // eax
  int v7; // edx
  int v8; // edi
  signed int Index; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > v10; // ecx
  Scaleform::String::DataDesc *pData; // eax
  Scaleform::RefCountVImpl_vtbl *v12; // ecx
  void *v13; // esi
  void *v14; // esi
  Scaleform::HashLH<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_FunctionInfo; // [esp+Ch] [ebp-28h]
  Scaleform::String v16; // [esp+10h] [ebp-24h] BYREF
  Scaleform::String v17; // [esp+14h] [ebp-20h] BYREF
  volatile unsigned int v18; // [esp+18h] [ebp-1Ch]
  const char *v19; // [esp+1Ch] [ebp-18h] BYREF
  unsigned __int64 v20; // [esp+20h] [ebp-14h] BYREF
  Scaleform::MsgFormat::Sink v21; // [esp+28h] [ebp-Ch] BYREF

  v3 = 0;
  v4 = (Scaleform::RefCountVImpl *)Scaleform::GFx::AMP::MovieFunctionTreeStats::Accumulate(this, 1);
  v18 = 0;
  if ( v4[1].RefCount )
  {
    p_FunctionInfo = &this->FunctionInfo;
    do
    {
      Scaleform::String::String(&v17);
      Scaleform::String::String(&v16);
      v5 = (const unsigned __int64 *)((char *)v4[1].__vftable + v3);
      if ( p_FunctionInfo->mHash.pTable )
      {
        v6 = 8;
        v7 = 5381;
        do
        {
          v8 = *((unsigned __int8 *)v5 + --v6);
          v7 = v8 + 65599 * v7;
        }
        while ( v6 );
        Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexCore<unsigned __int64>(
                  (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)p_FunctionInfo,
                  v5,
                  v7 & p_FunctionInfo->mHash.pTable->SizeMask);
        if ( Index >= 0 )
        {
          v10.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)p_FunctionInfo->mHash.pTable;
          if ( p_FunctionInfo->mHash.pTable )
          {
            if ( Index <= (signed int)v10.pTable->SizeMask )
              Scaleform::String::operator=(&v16, (const Scaleform::String *)(v10.pTable[3 * Index + 3].EntryCount + 8));
          }
        }
      }
      pData = v16.pData;
      if ( (*(_DWORD *)(v16.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
      {
        v12 = v4[1].__vftable;
        v20 = *(_QWORD *)((char *)&v12[2].~Scaleform::RefCountVImpl + v3) / 0x3E8uLL;
        v21.SinkData.pStr = &v17;
        v19 = (const char *)((v16.HeapTypeBits & 0xFFFFFFFC) + 8);
        v21.Type = tStr;
        Scaleform::Format<char const *,unsigned __int64,unsigned long>(
          &v21,
          "{0}: {1} ms ({2} times)\n",
          &v19,
          &v20,
          (unsigned int *)((char *)&v12[1].AddRef + v3));
        Scaleform::Log::LogMessage(log, (const char *)&stru_7F9BE8.allocator, (v17.HeapTypeBits & 0xFFFFFFFC) + 8);
        pData = v16.pData;
      }
      v13 = (void *)((unsigned int)pData & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)pData & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
      v14 = (void *)(v17.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((v17.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
      v3 += 32;
      ++v18;
    }
    while ( v18 < v4[1].RefCount );
  }
  Scaleform::RefCountImpl::Release(v4);
}
