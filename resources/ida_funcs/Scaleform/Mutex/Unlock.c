void __thiscall Scaleform::Mutex::Unlock(Scaleform::Mutex *this)
{
  Scaleform::MutexImpl::Unlock(this->pImpl, this);
}
