void __thiscall Scaleform::MemoryHeapMH::GetRootStats(
        Scaleform::MemoryHeapMH *this,
        Scaleform::MemoryHeap::RootStats *stats)
{
  unsigned int v3; // eax

  stats->UserDebugFootprint = 0;
  stats->UserDebugUsedSpace = 0;
  this->getUserDebugStats(this, stats);
  stats->DebugInfoFootprint = 0;
  stats->DebugInfoUsedSpace = 0;
  stats->SysMemFootprint = stats->UserDebugFootprint + stats->DebugInfoFootprint + this->GetTotalFootprint(this);
  v3 = stats->UserDebugFootprint + stats->DebugInfoFootprint + this->GetTotalUsedSpace(this);
  stats->PageMapFootprint = 0;
  stats->PageMapUsedSpace = 0;
  stats->BookkeepingFootprint = 0;
  stats->BookkeepingUsedSpace = 0;
  stats->SysMemUsedSpace = v3;
}
