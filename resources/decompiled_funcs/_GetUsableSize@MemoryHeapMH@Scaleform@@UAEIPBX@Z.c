unsigned int __thiscall Scaleform::MemoryHeapMH::GetUsableSize(Scaleform::MemoryHeapMH *this, const void *ptr)
{
  Scaleform::HeapMH::PageMH *v2; // eax
  Scaleform::LockSafe *p_RootLock; // esi
  Scaleform::HeapMH::NodeMH *GrEq; // eax
  unsigned int UsableSize; // edi
  Scaleform::HeapMH::PageInfoMH pageInfo; // [esp+4h] [ebp-Ch] BYREF

  v2 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, (unsigned int)ptr);
  if ( v2 )
  {
    Scaleform::HeapMH::AllocEngineMH::GetPageInfoWithSize(v2->pHeap->pEngine, v2, ptr, &pageInfo);
    return pageInfo.UsableSize;
  }
  else
  {
    p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    GrEq = (Scaleform::HeapMH::NodeMH *)Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
                                          &Scaleform::HeapMH::GlobalRootMH->HeapTree,
                                          (unsigned int)ptr);
    Scaleform::HeapMH::AllocEngineMH::GetPageInfoWithSize(
      *(Scaleform::HeapMH::AllocEngineMH **)((GrEq->pHeap & 0xFFFFFFFC) + 104),
      GrEq,
      ptr,
      &pageInfo);
    UsableSize = pageInfo.UsableSize;
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    return UsableSize;
  }
}
