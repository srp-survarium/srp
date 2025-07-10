BOOL __thiscall Scaleform::Semaphore::CanAcquire(Scaleform::Semaphore *this)
{
  return (signed int)(this->RefCount - (unsigned int)this->pHandlers) > 0;
}
