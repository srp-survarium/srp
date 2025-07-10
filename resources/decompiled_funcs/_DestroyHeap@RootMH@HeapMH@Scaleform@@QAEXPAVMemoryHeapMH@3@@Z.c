void __thiscall Scaleform::HeapMH::RootMH::DestroyHeap(Scaleform::HeapMH::RootMH *this, Scaleform::MemoryHeapMH *heap)
{
  unsigned int SelfSize; // ebx

  SelfSize = heap->SelfSize;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)heap->pEngine);
  ((void (__thiscall *)(Scaleform::MemoryHeapMH *, _DWORD))heap->~Scaleform::MemoryHeapMH)(heap, 0);
  this->pSysAlloc->Free(this->pSysAlloc, heap, SelfSize, 4u);
}
