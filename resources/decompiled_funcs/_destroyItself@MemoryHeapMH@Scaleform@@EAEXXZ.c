void __thiscall Scaleform::MemoryHeapMH::destroyItself(Scaleform::MemoryHeapMH *this)
{
  Scaleform::MemoryHeap *i; // ecx
  char **v3; // eax
  Scaleform::MemoryHeap *pNext; // esi

  for ( i = this->ChildHeaps.Root.pNext; ; i = pNext )
  {
    v3 = this == (Scaleform::MemoryHeapMH *)-68 ? 0 : &this->Info.pName;
    if ( i == (Scaleform::MemoryHeap *)v3 )
      break;
    pNext = i->pNext;
    ((void (*)(void))i->destroyItself)();
  }
  Scaleform::HeapMH::RootMH::DestroyHeap(Scaleform::HeapMH::GlobalRootMH, this);
}
