int __thiscall Scaleform::Mutex_AreadyLockedAcquireInterface::TryAcquireCancel(
        Scaleform::Mutex_AreadyLockedAcquireInterface *this)
{
  return ((int (__thiscall *)(Scaleform::AcquireInterface *))this->pMutex->TryAcquireCancel)(&this->pMutex->Scaleform::AcquireInterface);
}
