void *__thiscall Scaleform::MemoryHeapMH::AllocAutoHeap(
        Scaleform::MemoryHeapMH *this,
        Scaleform::LockSafe::Locker thisPtr,
        unsigned int size,
        const Scaleform::AllocInfo *info)
{
  Scaleform::HeapMH::PageMH *v4; // eax
  Scaleform::MemoryHeapMH *pHeap; // esi
  void *v6; // eax
  void *v7; // esi
  Scaleform::LockSafe *p_RootLock; // ebx
  unsigned int v10; // esi
  Scaleform::LockSafe *v11; // ebp
  void *v12; // esi
  _RTL_CRITICAL_SECTION *p_cs; // [esp-4h] [ebp-18h]
  Scaleform::HeapMH::PageInfoMH v14; // [esp+8h] [ebp-Ch] BYREF
  Scaleform::LockSafe *locker2; // [esp+18h] [ebp+4h]

  v4 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, (unsigned int)thisPtr.pLock);
  if ( v4 )
  {
    pHeap = v4->pHeap;
    if ( pHeap->UseLocks )
    {
      EnterCriticalSection(&pHeap->HeapLock.cs);
      v6 = Scaleform::HeapMH::AllocEngineMH::Alloc(pHeap->pEngine, size, &v14, 0);
      p_cs = &pHeap->HeapLock.cs;
      v7 = v6;
      LeaveCriticalSection(p_cs);
      return v7;
    }
    else
    {
      return Scaleform::HeapMH::AllocEngineMH::Alloc(pHeap->pEngine, size, &v14, 0);
    }
  }
  else
  {
    p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    v10 = Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
            &Scaleform::HeapMH::GlobalRootMH->HeapTree,
            (unsigned int)thisPtr.pLock)->pHeap
        & 0xFFFFFFFC;
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    if ( *(_BYTE *)(v10 + 100) )
    {
      v11 = (Scaleform::LockSafe *)(v10 + 76);
      EnterCriticalSection((LPCRITICAL_SECTION)(v10 + 76));
      locker2 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v12 = Scaleform::HeapMH::AllocEngineMH::Alloc(*(Scaleform::HeapMH::AllocEngineMH **)(v10 + 104), size, &v14, 1);
      LeaveCriticalSection(&locker2->mLock.cs);
    }
    else
    {
      v11 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v12 = Scaleform::HeapMH::AllocEngineMH::Alloc(*(Scaleform::HeapMH::AllocEngineMH **)(v10 + 104), size, &v14, 1);
    }
    LeaveCriticalSection(&v11->mLock.cs);
    return v12;
  }
}
