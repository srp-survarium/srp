Scaleform::Mutex_AreadyLockedAcquireInterface *__thiscall Scaleform::Mutex::GetAcquireInterface(Scaleform::Mutex *this)
{
  Scaleform::MutexImpl *pImpl; // esi

  pImpl = this->pImpl;
  if ( !pImpl->LockCount || WaitForSingleObject(pImpl->hMutexOrSemaphore, 0) )
    return (Scaleform::Mutex_AreadyLockedAcquireInterface *)&this->Scaleform::AcquireInterface;
  ++pImpl->LockCount;
  Scaleform::MutexImpl::Unlock(pImpl, this);
  return &pImpl->AreadyLockedAcquire;
}
