void *__thiscall Scaleform::MemoryHeapMH::Realloc(Scaleform::MemoryHeapMH *this, void *oldPtr, unsigned int newSize)
{
  Scaleform::HeapMH::PageMH *v4; // eax
  Scaleform::HeapMH::PageMH *v5; // ebx
  Scaleform::MemoryHeapMH *pHeap; // esi
  void *v7; // eax
  void *v8; // esi
  Scaleform::HeapMH::NodeMH *GrEq; // ebp
  unsigned int v11; // esi
  void *v12; // esi
  _RTL_CRITICAL_SECTION *p_cs; // [esp-4h] [ebp-24h]
  _RTL_CRITICAL_SECTION *locker1; // [esp+10h] [ebp-10h]
  Scaleform::HeapMH::PageInfoMH newInfo; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::LockSafe *locker2; // [esp+24h] [ebp+4h]
  Scaleform::LockSafe *locker2a; // [esp+24h] [ebp+4h]
  Scaleform::LockSafe *locker2b; // [esp+24h] [ebp+4h]

  v4 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, (unsigned int)oldPtr);
  v5 = v4;
  if ( v4 )
  {
    pHeap = v4->pHeap;
    if ( pHeap->UseLocks )
    {
      EnterCriticalSection(&pHeap->HeapLock.cs);
      v7 = Scaleform::MemoryHeapMH::reallocMem(pHeap, v5, oldPtr, newSize, 0);
      p_cs = &pHeap->HeapLock.cs;
      v8 = v7;
      LeaveCriticalSection(p_cs);
      return v8;
    }
    else
    {
      return Scaleform::MemoryHeapMH::reallocMem(pHeap, v4, oldPtr, newSize, 0);
    }
  }
  else
  {
    locker2 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    GrEq = (Scaleform::HeapMH::NodeMH *)Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
                                          &Scaleform::HeapMH::GlobalRootMH->HeapTree,
                                          (unsigned int)oldPtr);
    v11 = GrEq->pHeap & 0xFFFFFFFC;
    LeaveCriticalSection(&locker2->mLock.cs);
    if ( *(_BYTE *)(v11 + 100) )
    {
      locker1 = (_RTL_CRITICAL_SECTION *)(v11 + 76);
      EnterCriticalSection((LPCRITICAL_SECTION)(v11 + 76));
      locker2a = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v12 = Scaleform::HeapMH::AllocEngineMH::ReallocInNode(
              *(Scaleform::HeapMH::AllocEngineMH **)(v11 + 104),
              GrEq,
              oldPtr,
              newSize,
              &newInfo,
              1);
      LeaveCriticalSection(&locker2a->mLock.cs);
      LeaveCriticalSection(locker1);
    }
    else
    {
      locker2b = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v12 = Scaleform::HeapMH::AllocEngineMH::ReallocInNode(
              *(Scaleform::HeapMH::AllocEngineMH **)(v11 + 104),
              GrEq,
              oldPtr,
              newSize,
              &newInfo,
              1);
      LeaveCriticalSection(&locker2b->mLock.cs);
    }
    return v12;
  }
}
