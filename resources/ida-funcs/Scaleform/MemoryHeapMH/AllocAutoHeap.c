char *__thiscall Scaleform::MemoryHeapMH::AllocAutoHeap(
        Scaleform::MemoryHeapMH *this,
        unsigned int thisPtr,
        unsigned int size,
        unsigned int align,
        const Scaleform::AllocInfo *info)
{
  Scaleform::HeapMH::PageMH *v5; // eax
  Scaleform::MemoryHeapMH *pHeap; // esi
  char *v7; // eax
  char *v8; // esi
  Scaleform::LockSafe *p_RootLock; // ebx
  unsigned int v11; // esi
  Scaleform::LockSafe *v12; // ebp
  char *v13; // esi
  _RTL_CRITICAL_SECTION *p_cs; // [esp-4h] [ebp-18h]
  Scaleform::HeapMH::PageInfoMH infoa; // [esp+8h] [ebp-Ch] BYREF
  Scaleform::LockSafe *addr; // [esp+18h] [ebp+4h]

  v5 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, thisPtr);
  if ( v5 )
  {
    pHeap = v5->pHeap;
    if ( pHeap->UseLocks )
    {
      EnterCriticalSection(&pHeap->HeapLock.cs);
      v7 = Scaleform::HeapMH::AllocEngineMH::Alloc(pHeap->pEngine, size, align, &infoa, 0);
      p_cs = &pHeap->HeapLock.cs;
      v8 = v7;
      LeaveCriticalSection(p_cs);
      return v8;
    }
    else
    {
      return Scaleform::HeapMH::AllocEngineMH::Alloc(pHeap->pEngine, size, align, &infoa, 0);
    }
  }
  else
  {
    p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    v11 = Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
            &Scaleform::HeapMH::GlobalRootMH->HeapTree,
            thisPtr)->pHeap
        & 0xFFFFFFFC;
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    if ( *(_BYTE *)(v11 + 100) )
    {
      v12 = (Scaleform::LockSafe *)(v11 + 76);
      EnterCriticalSection((LPCRITICAL_SECTION)(v11 + 76));
      addr = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v13 = Scaleform::HeapMH::AllocEngineMH::Alloc(
              *(Scaleform::HeapMH::AllocEngineMH **)(v11 + 104),
              size,
              align,
              &infoa,
              (Scaleform::LockSafe *)1);
      LeaveCriticalSection(&addr->mLock.cs);
    }
    else
    {
      v12 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v13 = Scaleform::HeapMH::AllocEngineMH::Alloc(
              *(Scaleform::HeapMH::AllocEngineMH **)(v11 + 104),
              size,
              align,
              &infoa,
              (Scaleform::LockSafe *)1);
    }
    LeaveCriticalSection(&v12->mLock.cs);
    return v13;
  }
}


char *__thiscall Scaleform::MemoryHeapMH::AllocAutoHeap(
        Scaleform::MemoryHeapMH *this,
        unsigned int thisPtr,
        unsigned int size,
        const Scaleform::AllocInfo *info)
{
  Scaleform::HeapMH::PageMH *v4; // eax
  Scaleform::MemoryHeapMH *pHeap; // esi
  char *v6; // eax
  char *v7; // esi
  Scaleform::LockSafe *p_RootLock; // ebx
  unsigned int v10; // esi
  Scaleform::LockSafe *v11; // ebp
  char *v12; // esi
  _RTL_CRITICAL_SECTION *p_cs; // [esp-4h] [ebp-18h]
  Scaleform::HeapMH::PageInfoMH infoa; // [esp+8h] [ebp-Ch] BYREF
  Scaleform::LockSafe *addr; // [esp+18h] [ebp+4h]

  v4 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, thisPtr);
  if ( v4 )
  {
    pHeap = v4->pHeap;
    if ( pHeap->UseLocks )
    {
      EnterCriticalSection(&pHeap->HeapLock.cs);
      v6 = Scaleform::HeapMH::AllocEngineMH::Alloc(pHeap->pEngine, size, &infoa, 0);
      p_cs = &pHeap->HeapLock.cs;
      v7 = v6;
      LeaveCriticalSection(p_cs);
      return v7;
    }
    else
    {
      return Scaleform::HeapMH::AllocEngineMH::Alloc(pHeap->pEngine, size, &infoa, 0);
    }
  }
  else
  {
    p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    v10 = Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
            &Scaleform::HeapMH::GlobalRootMH->HeapTree,
            thisPtr)->pHeap
        & 0xFFFFFFFC;
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    if ( *(_BYTE *)(v10 + 100) )
    {
      v11 = (Scaleform::LockSafe *)(v10 + 76);
      EnterCriticalSection((LPCRITICAL_SECTION)(v10 + 76));
      addr = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v12 = Scaleform::HeapMH::AllocEngineMH::Alloc(
              *(Scaleform::HeapMH::AllocEngineMH **)(v10 + 104),
              size,
              &infoa,
              (Scaleform::LockSafe *)1);
      LeaveCriticalSection(&addr->mLock.cs);
    }
    else
    {
      v11 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v12 = Scaleform::HeapMH::AllocEngineMH::Alloc(
              *(Scaleform::HeapMH::AllocEngineMH **)(v10 + 104),
              size,
              &infoa,
              (Scaleform::LockSafe *)1);
    }
    LeaveCriticalSection(&v11->mLock.cs);
    return v12;
  }
}
