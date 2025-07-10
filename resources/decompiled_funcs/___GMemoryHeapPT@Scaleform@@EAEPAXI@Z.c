Scaleform::MemoryHeapMH *__thiscall Scaleform::MemoryHeapPT::`scalar deleting destructor'(
        Scaleform::MemoryHeapMH *this,
        char a2)
{
  this->__vftable = (Scaleform::MemoryHeapMH_vtbl *)&Scaleform::MemoryHeap::`vftable';
  Scaleform::Lock::~Lock(&this->HeapLock);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
