void *__thiscall Scaleform::HeapPT::HeapRoot::AllocSysDirect(Scaleform::HeapPT::HeapRoot *this, unsigned int size)
{
  Scaleform::LockSafe *p_RootLock; // edi
  unsigned int v4; // eax
  void *v5; // esi

  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  v4 = this->AllocWrapper.SysGranularity
     * ((this->AllocWrapper.SysGranularity + size - 1)
      / this->AllocWrapper.SysGranularity);
  this->AllocWrapper.UsedSpace += v4;
  v5 = this->AllocWrapper.pSrcAlloc->Alloc(this->AllocWrapper.pSrcAlloc, v4, this->AllocWrapper.MinAlign);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return v5;
}
