char __thiscall Scaleform::Semaphore::TryAcquireCancel(Scaleform::Semaphore *this)
{
  return Scaleform::Semaphore::ReleaseSemaphore(
           (Scaleform::Semaphore *)((char *)this - 12),
           (Scaleform::Waitable::HandlerArray *)1);
}
