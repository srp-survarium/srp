int __thiscall Scaleform::Mutex_AreadyLockedAcquireInterface::TryAcquireCommit(
        Scaleform::Mutex_AreadyLockedAcquireInterface *this)
{
  return ((int (__thiscall *)(Scaleform::AcquireInterface *))this->pMutex->TryAcquireCommit)(&this->pMutex->Scaleform::AcquireInterface);
}
