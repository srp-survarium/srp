void __thiscall Scaleform::MemoryHeapPT::destroyItself(Scaleform::MemoryHeapPT *this)
{
  Scaleform::MemoryHeap *i; // ecx
  char **v3; // eax
  Scaleform::MemoryHeap *pNext; // esi

  for ( i = this->ChildHeaps.Root.pNext; ; i = pNext )
  {
    v3 = this == (Scaleform::MemoryHeapPT *)-68 ? 0 : &this->Info.pName;
    if ( i == (Scaleform::MemoryHeap *)v3 )
      break;
    pNext = i->pNext;
    ((void (*)(void))i->destroyItself)();
  }
  Scaleform::HeapPT::HeapRoot::DestroyHeap(Scaleform::HeapPT::GlobalRoot, this);
}
