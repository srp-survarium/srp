unsigned int __thiscall Scaleform::HeapPT::SysAllocGranulator::GetUsedSpace(
        Scaleform::HeapPT::SysAllocGranulator *this)
{
  return this->SysDirectFootprint
       + this->pGranulator->Footprint
       - (this->pGranulator->Allocator.FreeBlocks << this->pGranulator->Allocator.MinShift);
}
