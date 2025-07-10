void __thiscall Scaleform::MemoryHeap::ReleaseOnFree(Scaleform::MemoryHeap *this, void *ptr)
{
  this->pAutoRelease = ptr;
}
