void __thiscall Scaleform::MemoryHeapMH::MemoryHeapMH(Scaleform::MemoryHeapMH *this)
{
  Scaleform::MemoryHeap::MemoryHeap(this);
  this->pEngine = 0;
  this->pDebugStorage = 0;
  this->__vftable = (Scaleform::MemoryHeapMH_vtbl *)&Scaleform::MemoryHeapMH::`vftable';
}
