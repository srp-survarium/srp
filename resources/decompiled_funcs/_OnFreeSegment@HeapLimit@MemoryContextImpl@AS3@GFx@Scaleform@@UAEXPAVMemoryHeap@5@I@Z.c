void __thiscall Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit::OnFreeSegment(
        Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit *this,
        Scaleform::MemoryHeap *heap,
        unsigned int freeingSize)
{
  unsigned int CurrentLimit; // eax
  unsigned int v4; // eax

  CurrentLimit = this->CurrentLimit;
  if ( CurrentLimit > this->UserLevelLimit && CurrentLimit > freeingSize )
  {
    v4 = CurrentLimit - freeingSize;
    this->CurrentLimit = v4;
    heap->SetLimit(heap, v4);
  }
}
