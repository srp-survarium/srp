void __thiscall Scaleform::MemoryHeap::VisitChildHeaps(
        Scaleform::MemoryHeap *this,
        Scaleform::MemoryHeap::HeapVisitor *visitor)
{
  Scaleform::MemoryHeap *i; // esi
  char **v4; // eax
  Scaleform::Lock *p_HeapLock; // [esp+10h] [ebp-4h]

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  for ( i = this->ChildHeaps.Root.pNext; ; i = i->pNext )
  {
    v4 = this == (Scaleform::MemoryHeap *)-68 ? 0 : &this->Info.pName;
    if ( i == (Scaleform::MemoryHeap *)v4 )
      break;
    visitor->Visit(visitor, this, i);
  }
  LeaveCriticalSection(&p_HeapLock->cs);
}
