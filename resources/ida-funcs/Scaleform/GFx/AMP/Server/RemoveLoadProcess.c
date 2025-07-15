void __thiscall Scaleform::GFx::AMP::Server::RemoveLoadProcess(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::GFx::LoadProcess *loadProcess)
{
  unsigned int *p_Size; // ebp
  unsigned int SpinCount; // ecx
  unsigned int v5; // eax
  Scaleform::GFx::LoadProcess **LockSemaphore; // edx

  p_Size = &this->LoadProcesses.Data.Size;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->LoadProcesses.Data.Size);
  SpinCount = this->ImageLock.cs.SpinCount;
  v5 = 0;
  if ( !SpinCount )
    goto LABEL_13;
  LockSemaphore = (Scaleform::GFx::LoadProcess **)this->ImageLock.cs.LockSemaphore;
  while ( *LockSemaphore != loadProcess )
  {
    ++v5;
    ++LockSemaphore;
    if ( v5 >= SpinCount )
      goto LABEL_13;
  }
  if ( SpinCount != 1 )
  {
    memmove(
      (int)this->ImageLock.cs.LockSemaphore + 4 * v5,
      (const __m128i *)((char *)this->ImageLock.cs.LockSemaphore + 4 * v5 + 4),
      4 * (SpinCount - v5) - 4);
    --this->ImageLock.cs.SpinCount;
LABEL_13:
    LeaveCriticalSection((LPCRITICAL_SECTION)p_Size);
    return;
  }
  if ( ((int)this->LoadProcesses.Data.Data & 0xFFFFFFFE) != 0 )
  {
    if ( this->ImageLock.cs.LockSemaphore )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->ImageLock.cs.LockSemaphore);
      this->ImageLock.cs.LockSemaphore = 0;
    }
    this->LoadProcesses.Data.Data = 0;
  }
  this->ImageLock.cs.SpinCount = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)p_Size);
}
