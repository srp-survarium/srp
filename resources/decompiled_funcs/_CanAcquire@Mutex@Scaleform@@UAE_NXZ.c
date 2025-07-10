char __thiscall Scaleform::Mutex::CanAcquire(Scaleform::Mutex *this)
{
  Scaleform::MutexImpl *RefCount; // esi
  Scaleform::Mutex *v2; // edi

  RefCount = (Scaleform::MutexImpl *)this->RefCount;
  v2 = (Scaleform::Mutex *)((char *)this - 12);
  if ( !RefCount->LockCount )
    return 1;
  if ( !WaitForSingleObject(RefCount->hMutexOrSemaphore, 0) )
  {
    ++RefCount->LockCount;
    Scaleform::MutexImpl::Unlock(RefCount, v2);
    return 1;
  }
  return 0;
}
