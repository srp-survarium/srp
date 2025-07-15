void __cdecl Scaleform::ThreadList::AddRunningThread(Scaleform::Thread *pthread)
{
  Scaleform::Thread *v1; // ecx
  Scaleform::ThreadList *v2; // eax
  Scaleform::ThreadList *v3; // eax
  Scaleform::ThreadList *volatile v4; // esi
  Scaleform::MutexImpl *pImpl; // ebx
  Scaleform::Mutex *p_ThreadMutex; // edi
  void *hMutexOrSemaphore; // [esp-10h] [ebp-1Ch]
  Scaleform::Thread *v8; // [esp+8h] [ebp-4h] BYREF

  v8 = v1;
  if ( !Scaleform::ThreadList::pRunningThreads )
  {
    v2 = (Scaleform::ThreadList *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 32, 0);
    if ( v2 )
      Scaleform::ThreadList::ThreadList(v2);
    else
      v3 = 0;
    Scaleform::ThreadList::pRunningThreads = v3;
  }
  v4 = Scaleform::ThreadList::pRunningThreads;
  pImpl = Scaleform::ThreadList::pRunningThreads->ThreadMutex.pImpl;
  p_ThreadMutex = &Scaleform::ThreadList::pRunningThreads->ThreadMutex;
  hMutexOrSemaphore = pImpl->hMutexOrSemaphore;
  v8 = pthread;
  if ( !WaitForSingleObject(hMutexOrSemaphore, 0xFFFFFFFF) )
    ++pImpl->LockCount;
  Scaleform::HashSetBase<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp,Scaleform::ThreadList::ThreadHashOp,Scaleform::AllocatorGH<Scaleform::Thread *,2>,Scaleform::HashsetCachedEntry<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp>>::add<Scaleform::Thread *>(
    &v4->ThreadSet,
    v4,
    &v8,
    (unsigned int)pthread ^ ((unsigned int)pthread >> 6));
  Scaleform::MutexImpl::Unlock(p_ThreadMutex->pImpl, p_ThreadMutex);
}
