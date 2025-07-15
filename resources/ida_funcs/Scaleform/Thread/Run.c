int __thiscall Scaleform::Thread::Run(Scaleform::Thread *this)
{
  int (__cdecl *ThreadFunction)(Scaleform::Thread *, void *); // eax

  ThreadFunction = this->ThreadFunction;
  if ( ThreadFunction )
    return ThreadFunction(this, this->UserHandle);
  else
    return 0;
}
