void __thiscall Scaleform::HeapPT::HeapRoot::GetStats(
        Scaleform::HeapPT::HeapRoot *this,
        Scaleform::MemoryHeap::RootStats *stats)
{
  Scaleform::LockSafe *p_RootLock; // ebx

  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  stats->SysMemFootprint = this->AllocWrapper.GetFootprint((struct Scaleform::HeapPT::SysAllocWrapper *)this);
  stats->SysMemUsedSpace = this->AllocWrapper.GetUsedSpace((struct Scaleform::HeapPT::SysAllocWrapper *)this);
  stats->PageMapFootprint = this->AllocStarter.Allocator.Footprint;
  stats->PageMapUsedSpace = this->AllocStarter.Allocator.Footprint
                          - (this->AllocStarter.Allocator.Allocator.FreeBlocks << this->AllocStarter.Allocator.Allocator.MinShift);
  stats->BookkeepingFootprint = this->AllocBookkeeper.Footprint;
  stats->BookkeepingUsedSpace = this->AllocBookkeeper.Footprint
                              - (this->AllocBookkeeper.Allocator.Bin.FreeBlocks << this->AllocBookkeeper.Allocator.MinAlignShift);
  stats->DebugInfoFootprint = 0;
  stats->DebugInfoUsedSpace = 0;
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}
