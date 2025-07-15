void __thiscall Scaleform::HeapPT::HeapRoot::FreeSysDirect(
        Scaleform::HeapPT::HeapRoot *this,
        void *ptr,
        unsigned int size)
{
  Scaleform::LockSafe *p_RootLock; // edi
  unsigned int v5; // eax

  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  v5 = this->AllocWrapper.SysGranularity
     * ((this->AllocWrapper.SysGranularity + size - 1)
      / this->AllocWrapper.SysGranularity);
  this->AllocWrapper.UsedSpace -= v5;
  this->AllocWrapper.pSrcAlloc->Free(this->AllocWrapper.pSrcAlloc, ptr, v5, this->AllocWrapper.MinAlign);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}
