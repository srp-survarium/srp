int __thiscall Scaleform::HeapPT::HeapRoot::DestroyArena(Scaleform::HeapPT::HeapRoot *this, unsigned int arena)
{
  Scaleform::LockSafe *p_RootLock; // esi
  Scaleform::HeapPT::HeapRoot *v5; // ecx
  Scaleform::SysAllocPaged *v6; // ecx
  int v8; // edi
  Scaleform::SysAllocPaged *arenaa; // [esp+14h] [ebp+4h]
  bool arenab; // [esp+14h] [ebp+4h]

  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  EnterCriticalSection(&p_RootLock->mLock.cs);
  EnterCriticalSection(&p_RootLock->mLock.cs);
  if ( arena )
  {
    arenaa = this->pArenas[arena - 1];
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    v5 = (Scaleform::HeapPT::HeapRoot *)arenaa;
  }
  else
  {
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    v5 = this;
  }
  arenab = v5->AllocWrapper.GetUsedSpace(&v5->AllocWrapper) == 0;
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  if ( arenab )
  {
    v6 = this->pArenas[arena - 1];
    ((void (__thiscall *)(Scaleform::SysAllocPaged *, _DWORD))v6->~Scaleform::SysAllocPaged)(v6, 0);
    Scaleform::HeapPT::Bookkeeper::Free(&this->AllocBookkeeper, this->pArenas[arena - 1], 0xB4u);
    this->pArenas[arena - 1] = 0;
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    return 0;
  }
  else
  {
    v8 = MEMORY[0];
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    return v8;
  }
}
