bool __thiscall Scaleform::WaitCondition::Wait(Scaleform::WaitCondition *this, Scaleform::Mutex *pmutex, DWORD delay)
{
  return Scaleform::WaitConditionImpl::Wait(this->pImpl, pmutex, delay);
}
