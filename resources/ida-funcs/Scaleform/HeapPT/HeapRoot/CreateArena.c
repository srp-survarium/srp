void __thiscall Scaleform::HeapPT::HeapRoot::CreateArena(
        Scaleform::HeapPT::HeapRoot *this,
        unsigned int arena,
        Scaleform::SysAllocPaged *sysAlloc)
{
  Scaleform::LockSafe *p_RootLock; // ebx
  unsigned int v5; // edi
  unsigned int v6; // edi
  Scaleform::SysAllocPaged **v7; // ebp
  Scaleform::SysAllocPaged **pArenas; // eax
  Scaleform::HeapPT::SysAllocWrapper *v9; // ecx
  Scaleform::SysAllocPaged *v10; // eax
  Scaleform::LockSafe *v11; // [esp+Ch] [ebp-4h]

  p_RootLock = &this->RootLock;
  v11 = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  v5 = arena;
  if ( this->NumArenas < arena )
  {
    v6 = (arena + 15) & 0xFFFFFFF0;
    v7 = (Scaleform::SysAllocPaged **)Scaleform::HeapPT::Bookkeeper::Alloc(
                                        &this->AllocBookkeeper,
                                        (Scaleform::Heap::HeapSegment *)(4 * v6));
    memset((int)v7, 0, 4 * v6);
    pArenas = this->pArenas;
    if ( pArenas )
    {
      memcpy((int)v7, (const __m128i *)pArenas, 4 * this->NumArenas);
      Scaleform::HeapPT::Bookkeeper::Free(&this->AllocBookkeeper, (unsigned int)this->pArenas, 4 * this->NumArenas);
    }
    p_RootLock = v11;
    this->pArenas = v7;
    this->NumArenas = v6;
    v5 = arena;
  }
  this->pArenas[v5 - 1] = (Scaleform::SysAllocPaged *)Scaleform::HeapPT::Bookkeeper::Alloc(
                                                        &this->AllocBookkeeper,
                                                        (Scaleform::Heap::HeapSegment *)0xB4);
  v9 = (Scaleform::HeapPT::SysAllocWrapper *)this->pArenas[v5 - 1];
  if ( v9 )
    Scaleform::HeapPT::SysAllocWrapper::SysAllocWrapper(v9, sysAlloc);
  else
    v10 = 0;
  this->pArenas[v5 - 1] = v10;
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}
