int __thiscall Scaleform::Thread::CanAcquire(Scaleform::Thread *this)
{
  return (*((int (__thiscall **)(void **))this[-1].ThreadHandle + 1))(&this[-1].ThreadHandle);
}
