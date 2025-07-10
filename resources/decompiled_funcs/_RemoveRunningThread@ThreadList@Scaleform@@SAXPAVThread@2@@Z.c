void __cdecl Scaleform::ThreadList::RemoveRunningThread(Scaleform::Thread *pthread)
{
  Scaleform::ThreadList *volatile v1; // esi
  Scaleform::MutexImpl *pImpl; // edi
  Scaleform::Mutex *p_ThreadMutex; // ebx

  v1 = Scaleform::ThreadList::pRunningThreads;
  pImpl = Scaleform::ThreadList::pRunningThreads->ThreadMutex.pImpl;
  p_ThreadMutex = &Scaleform::ThreadList::pRunningThreads->ThreadMutex;
  if ( !WaitForSingleObject(pImpl->hMutexOrSemaphore, 0xFFFFFFFF) )
    ++pImpl->LockCount;
  Scaleform::HashSetBase<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp,Scaleform::ThreadList::ThreadHashOp,Scaleform::AllocatorGH<Scaleform::Thread *,2>,Scaleform::HashsetCachedEntry<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp>>::RemoveAlt<Scaleform::Thread *>(
    &v1->ThreadSet,
    &pthread);
  if ( !v1->ThreadSet.pTable || !v1->ThreadSet.pTable->EntryCount )
    Scaleform::WaitConditionImpl::Notify(v1->ThreadsEmpty.pImpl);
  Scaleform::MutexImpl::Unlock(p_ThreadMutex->pImpl, p_ThreadMutex);
}
