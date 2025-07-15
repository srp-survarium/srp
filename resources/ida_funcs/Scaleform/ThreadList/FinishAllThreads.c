void __thiscall Scaleform::ThreadList::finishAllThreads(Scaleform::ThreadList *this)
{
  Scaleform::MutexImpl *pImpl; // ebx
  Scaleform::Mutex *p_ThreadMutex; // edi

  pImpl = this->ThreadMutex.pImpl;
  p_ThreadMutex = &this->ThreadMutex;
  if ( !WaitForSingleObject(pImpl->hMutexOrSemaphore, 0xFFFFFFFF) )
    ++pImpl->LockCount;
  while ( Scaleform::HashSetBase<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp,Scaleform::ThreadList::ThreadHashOp,Scaleform::AllocatorGH<Scaleform::Thread *,2>,Scaleform::HashsetCachedEntry<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp>>::GetSize(&this->ThreadSet) )
    Scaleform::WaitConditionImpl::Wait(this->ThreadsEmpty.pImpl, p_ThreadMutex, 0xFFFFFFFF);
  Scaleform::MutexImpl::Unlock(p_ThreadMutex->pImpl, p_ThreadMutex);
}
