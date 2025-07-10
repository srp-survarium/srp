void __thiscall Scaleform::MemoryHeapMH::Free(Scaleform::MemoryHeapMH *this, void *ptr)
{
  Scaleform::HeapMH::PageMH *v3; // eax
  Scaleform::HeapMH::PageMH *v4; // ebx
  unsigned int pHeap; // esi
  Scaleform::HeapMH::NodeMH *GrEq; // ebx
  Scaleform::LockSafe *locker2; // [esp+8h] [ebp+4h]
  Scaleform::LockSafe *locker2a; // [esp+8h] [ebp+4h]
  Scaleform::LockSafe *locker2b; // [esp+8h] [ebp+4h]

  if ( ptr )
  {
    v3 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, (unsigned int)ptr);
    v4 = v3;
    if ( v3 )
    {
      pHeap = (unsigned int)v3->pHeap;
      if ( *(_BYTE *)(pHeap + 100) )
      {
        EnterCriticalSection((LPCRITICAL_SECTION)(pHeap + 76));
        Scaleform::HeapMH::AllocEngineMH::Free(*(Scaleform::HeapMH::AllocEngineMH **)(pHeap + 104), v4, ptr, 0);
        LeaveCriticalSection((LPCRITICAL_SECTION)(pHeap + 76));
      }
      else
      {
        Scaleform::HeapMH::AllocEngineMH::Free(*(Scaleform::HeapMH::AllocEngineMH **)(pHeap + 104), v3, ptr, 0);
      }
    }
    else
    {
      locker2 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      GrEq = (Scaleform::HeapMH::NodeMH *)Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
                                            &Scaleform::HeapMH::GlobalRootMH->HeapTree,
                                            (unsigned int)ptr);
      pHeap = GrEq->pHeap & 0xFFFFFFFC;
      LeaveCriticalSection(&locker2->mLock.cs);
      if ( *(_BYTE *)(pHeap + 100) )
      {
        EnterCriticalSection((LPCRITICAL_SECTION)(pHeap + 76));
        locker2a = &Scaleform::HeapMH::GlobalRootMH->RootLock;
        EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
        Scaleform::HeapMH::AllocEngineMH::Free(*(Scaleform::HeapMH::AllocEngineMH **)(pHeap + 104), GrEq, ptr, 1);
        LeaveCriticalSection(&locker2a->mLock.cs);
        LeaveCriticalSection((LPCRITICAL_SECTION)(pHeap + 76));
      }
      else
      {
        locker2b = &Scaleform::HeapMH::GlobalRootMH->RootLock;
        EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
        Scaleform::HeapMH::AllocEngineMH::Free(*(Scaleform::HeapMH::AllocEngineMH **)(pHeap + 104), GrEq, ptr, 1);
        LeaveCriticalSection(&locker2b->mLock.cs);
      }
    }
    if ( ptr == *(void **)(pHeap + 24) )
      (*(void (__thiscall **)(unsigned int))(*(_DWORD *)pHeap + 32))(pHeap);
  }
}
