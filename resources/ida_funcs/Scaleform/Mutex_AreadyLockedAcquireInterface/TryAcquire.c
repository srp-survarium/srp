int __thiscall Scaleform::Mutex_AreadyLockedAcquireInterface::TryAcquire(
        Scaleform::Mutex_AreadyLockedAcquireInterface *this)
{
  return ((int (__thiscall *)(Scaleform::AcquireInterface *))this->pMutex->TryAcquire)(&this->pMutex->Scaleform::AcquireInterface);
}
