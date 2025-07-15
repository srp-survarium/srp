void __thiscall Scaleform::GFx::AMP::Server::AddSourceFile(
        Scaleform::GFx::AMP::Server *this,
        unsigned __int64 fileHandle,
        const __m128i *fileName)
{
  unsigned int *p_SpinCount; // ebx
  Scaleform::StringLH *v5; // eax
  Scaleform::StringLH *v6; // esi
  Scaleform::RefCountVImpl *v7; // [esp+Ch] [ebp-10h] BYREF
  int v8; // [esp+10h] [ebp-Ch] BYREF
  Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [esp+14h] [ebp-8h] BYREF

  p_SpinCount = &this->SwfLock.cs.SpinCount;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->SwfLock.cs.SpinCount);
  v8 = 579;
  v5 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                Scaleform::Memory::pGlobalHeap,
                                &this[-1].RecordingStateLock.cs.LockSemaphore,
                                12,
                                &v8);
  v6 = v5;
  if ( v5 )
  {
    v5->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
    v5[1].HeapTypeBits = 1;
    v5->HeapTypeBits = (unsigned int)&Scaleform::GFx::AMP::Server::SourceFileInfo::`vftable';
    Scaleform::StringLH::StringLH(v5 + 2);
  }
  else
  {
    v6 = 0;
  }
  v7 = (Scaleform::RefCountVImpl *)v6;
  Scaleform::String::operator=(v6 + 2, fileName);
  key.pFirst = &fileHandle;
  key.pSecond = (const Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes> *)&v7;
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&this->SwfLock.cs.LockSemaphore,
    &this->SwfLock.cs.LockSemaphore,
    &key);
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  LeaveCriticalSection((LPCRITICAL_SECTION)p_SpinCount);
}
