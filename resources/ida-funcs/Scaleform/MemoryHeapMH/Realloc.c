char *__thiscall Scaleform::MemoryHeapMH::Realloc(Scaleform::MemoryHeapMH *this, void *oldPtr, unsigned int newSize)
{
  Scaleform::HeapMH::PageMH *v4; // eax
  Scaleform::HeapMH::PageMH *v5; // ebx
  Scaleform::MemoryHeapMH *pHeap; // esi
  char *v7; // eax
  char *v8; // esi
  Scaleform::HeapMH::NodeMH *GrEq; // ebp
  unsigned int v11; // esi
  Scaleform::HeapMH::NodeMH *v12; // esi
  _RTL_CRITICAL_SECTION *p_cs; // [esp-4h] [ebp-24h]
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+10h] [ebp-10h]
  Scaleform::HeapMH::PageInfoMH newInfo; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::LockSafe *addr; // [esp+24h] [ebp+4h]
  Scaleform::LockSafe *addra; // [esp+24h] [ebp+4h]
  Scaleform::LockSafe *addrb; // [esp+24h] [ebp+4h]

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
    addr = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    GrEq = (Scaleform::HeapMH::NodeMH *)Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
                                          &Scaleform::HeapMH::GlobalRootMH->HeapTree,
                                          (unsigned int)oldPtr);
    v11 = GrEq->pHeap & 0xFFFFFFFC;
    LeaveCriticalSection(&addr->mLock.cs);
    if ( *(_BYTE *)(v11 + 100) )
    {
      lpCriticalSection = (_RTL_CRITICAL_SECTION *)(v11 + 76);
      EnterCriticalSection((LPCRITICAL_SECTION)(v11 + 76));
      addra = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v12 = Scaleform::HeapMH::AllocEngineMH::ReallocInNode(
              *(Scaleform::HeapMH::AllocEngineMH **)(v11 + 104),
              GrEq,
              (char *)oldPtr,
              newSize,
              &newInfo,
              1);
      LeaveCriticalSection(&addra->mLock.cs);
      LeaveCriticalSection(lpCriticalSection);
    }
    else
    {
      addrb = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v12 = Scaleform::HeapMH::AllocEngineMH::ReallocInNode(
              *(Scaleform::HeapMH::AllocEngineMH **)(v11 + 104),
              GrEq,
              (char *)oldPtr,
              newSize,
              &newInfo,
              1);
      LeaveCriticalSection(&addrb->mLock.cs);
    }
    return (char *)v12;
  }
}
