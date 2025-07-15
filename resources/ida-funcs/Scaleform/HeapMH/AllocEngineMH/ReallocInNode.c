Scaleform::HeapMH::NodeMH *__thiscall Scaleform::HeapMH::AllocEngineMH::ReallocInNode(
        Scaleform::HeapMH::AllocEngineMH *this,
        Scaleform::HeapMH::NodeMH *node,
        char *oldPtr,
        unsigned int newSize,
        Scaleform::HeapMH::PageInfoMH *newInfo,
        bool globalLocked)
{
  Scaleform::LockSafe *p_RootLock; // edi
  Scaleform::HeapMH::NodeMH *v8; // esi

  if ( globalLocked )
    return Scaleform::HeapMH::AllocEngineMH::reallocInNodeNoLock(
             this,
             node,
             oldPtr,
             (newSize + 3) & 0xFFFFFFFC,
             newInfo);
  p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  v8 = Scaleform::HeapMH::AllocEngineMH::reallocInNodeNoLock(this, node, oldPtr, (newSize + 3) & 0xFFFFFFFC, newInfo);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return v8;
}
