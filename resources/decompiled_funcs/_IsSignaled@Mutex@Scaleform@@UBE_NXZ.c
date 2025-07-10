BOOL __thiscall Scaleform::Mutex::IsSignaled(Scaleform::Mutex *this)
{
  return this->pImpl->LockCount == 0;
}
