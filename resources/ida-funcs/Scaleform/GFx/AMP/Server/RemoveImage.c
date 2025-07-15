void __thiscall Scaleform::GFx::AMP::Server::RemoveImage(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::GFx::ImageResource *image)
{
  unsigned int SpinCount; // ecx
  unsigned int v4; // eax
  Scaleform::GFx::ImageResource **LockSemaphore; // edx

  if ( (Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, image)->Info.Desc.Flags & 0x1000) != 0 )
    return;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->Images.Data.Size);
  SpinCount = this->MovieLock.cs.SpinCount;
  v4 = 0;
  if ( !SpinCount )
  {
LABEL_14:
    LeaveCriticalSection((LPCRITICAL_SECTION)&this->Images.Data.Size);
    return;
  }
  LockSemaphore = (Scaleform::GFx::ImageResource **)this->MovieLock.cs.LockSemaphore;
  while ( *LockSemaphore != image )
  {
    ++v4;
    ++LockSemaphore;
    if ( v4 >= SpinCount )
      goto LABEL_14;
  }
  if ( SpinCount != 1 )
  {
    memmove(
      (int)this->MovieLock.cs.LockSemaphore + 4 * v4,
      (const __m128i *)((char *)this->MovieLock.cs.LockSemaphore + 4 * v4 + 4),
      4 * (SpinCount - v4) - 4);
    --this->MovieLock.cs.SpinCount;
    goto LABEL_14;
  }
  if ( ((int)this->Images.Data.Data & 0xFFFFFFFE) != 0 )
  {
    if ( this->MovieLock.cs.LockSemaphore )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->MovieLock.cs.LockSemaphore);
      this->MovieLock.cs.LockSemaphore = 0;
    }
    this->Images.Data.Data = 0;
  }
  this->MovieLock.cs.SpinCount = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&this->Images.Data.Size);
}
