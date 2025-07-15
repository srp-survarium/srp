int __thiscall Scaleform::HeapPT::HeapRoot::DestroyArena(Scaleform::HeapPT::HeapRoot *this, unsigned int arena)
{
  Scaleform::LockSafe *p_RootLock; // esi
  Scaleform::HeapPT::HeapRoot *v5; // ecx
  Scaleform::SysAllocPaged *v6; // ecx
  int v8; // edi
  Scaleform::SysAllocPaged *v9; // [esp+14h] [ebp+4h]
  bool v10; // [esp+14h] [ebp+4h]

  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  EnterCriticalSection(&p_RootLock->mLock.cs);
  EnterCriticalSection(&p_RootLock->mLock.cs);
  if ( arena )
  {
    v9 = this->pArenas[arena - 1];
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    v5 = (Scaleform::HeapPT::HeapRoot *)v9;
  }
  else
  {
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    v5 = this;
  }
  v10 = v5->AllocWrapper.GetUsedSpace(&v5->AllocWrapper) == 0;
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  if ( v10 )
  {
    v6 = this->pArenas[arena - 1];
    ((void (__thiscall *)(Scaleform::SysAllocPaged *, _DWORD))v6->~Scaleform::SysAllocPaged)(v6, 0);
    Scaleform::HeapPT::Bookkeeper::Free(&this->AllocBookkeeper, (unsigned int)this->pArenas[arena - 1], 0xB4u);
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
