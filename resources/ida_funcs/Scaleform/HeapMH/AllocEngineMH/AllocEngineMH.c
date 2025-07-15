void __thiscall Scaleform::HeapMH::AllocEngineMH::AllocEngineMH(
        Scaleform::HeapMH::AllocEngineMH *this,
        Scaleform::SysAlloc *sysAlloc,
        Scaleform::MemoryHeapMH *heap,
        unsigned int minAlignSize,
        unsigned int limit)
{
  unsigned int v6; // eax

  this->pSysAlloc = sysAlloc;
  v6 = minAlignSize;
  this->pHeap = heap;
  if ( minAlignSize < 4 )
    v6 = 4;
  this->MinAlignSize = v6;
  Scaleform::HeapMH::AllocBitSet2MH::AllocBitSet2MH(&this->Allocator);
  this->Pages.Root.pPrev = (Scaleform::HeapMH::PageMH *)&this->Pages;
  this->Pages.Root.pNext = (Scaleform::HeapMH::PageMH *)&this->Pages;
  this->Footprint = 0;
  this->UsedSpace = 0;
  this->pLimHandler = 0;
  this->UseCount = 0;
  this->Limit = limit;
}
