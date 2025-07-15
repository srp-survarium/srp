bool __thiscall Scaleform::HeapPT::HeapRoot::ArenaIsEmpty(Scaleform::HeapPT::HeapRoot *this, unsigned int arena)
{
  Scaleform::HeapPT::HeapRoot *v2; // edi
  Scaleform::LockSafe *p_RootLock; // esi
  bool v4; // bl

  v2 = this;
  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  EnterCriticalSection(&p_RootLock->mLock.cs);
  if ( arena )
    v2 = (Scaleform::HeapPT::HeapRoot *)v2->pArenas[arena - 1];
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  v4 = v2->AllocWrapper.GetUsedSpace(&v2->AllocWrapper) == 0;
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return v4;
}
