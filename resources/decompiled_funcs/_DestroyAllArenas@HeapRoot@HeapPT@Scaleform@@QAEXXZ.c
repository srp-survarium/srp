void __thiscall Scaleform::HeapPT::HeapRoot::DestroyAllArenas(Scaleform::HeapPT::HeapRoot *this)
{
  Scaleform::LockSafe *p_RootLock; // ebp
  unsigned int i; // edi

  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  if ( this->pArenas )
  {
    for ( i = this->NumArenas; i; --i )
    {
      if ( this->pArenas[i - 1] )
        Scaleform::HeapPT::HeapRoot::DestroyArena(this, i);
    }
    Scaleform::HeapPT::Bookkeeper::Free(&this->AllocBookkeeper, this->pArenas, 4 * this->NumArenas);
    this->pArenas = 0;
    this->NumArenas = 0;
  }
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}
