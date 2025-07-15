void __thiscall Scaleform::MemoryHeapPT::MemoryHeapPT(Scaleform::MemoryHeapPT *this)
{
  Scaleform::MemoryHeap::MemoryHeap(this);
  this->pEngine = 0;
  this->pDebugStorage = 0;
  this->__vftable = (Scaleform::MemoryHeapPT_vtbl *)&Scaleform::MemoryHeapPT::`vftable';
}
