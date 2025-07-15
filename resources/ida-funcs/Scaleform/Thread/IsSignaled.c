unsigned int __thiscall Scaleform::Thread::IsSignaled(Scaleform::Thread *this)
{
  return (this->ThreadFlags.Value >> 1) & 1;
}
