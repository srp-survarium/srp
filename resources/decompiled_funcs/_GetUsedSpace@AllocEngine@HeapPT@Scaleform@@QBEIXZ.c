unsigned int __thiscall Scaleform::HeapPT::AllocEngine::GetUsedSpace(Scaleform::HeapPT::AllocEngine *this)
{
  return this->Footprint - (this->Allocator.Bin.FreeBlocks << this->Allocator.MinAlignShift) - this->TinyFreeSpace;
}
