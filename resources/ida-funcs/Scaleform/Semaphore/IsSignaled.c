BOOL __thiscall Scaleform::Semaphore::IsSignaled(Scaleform::Semaphore *this)
{
  return this->MaxValue - this->Value > 0;
}
