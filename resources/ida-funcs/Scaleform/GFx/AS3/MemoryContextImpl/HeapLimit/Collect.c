void __thiscall Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit::Collect(
        Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::Render::Text::Allocator *pObject; // ecx
  Scaleform::GFx::AS3::ASRefCountCollector *v4; // esi

  pObject = this->MemContext->TextAllocator.pObject;
  if ( pObject )
  {
    Scaleform::Render::Text::Allocator::FlushTextFormatCache(pObject, 1);
    Scaleform::Render::Text::Allocator::FlushParagraphFormatCache(this->MemContext->TextAllocator.pObject, 1);
  }
  v4 = this->MemContext->ASGC.pObject;
  if ( v4->SuspendCnt )
  {
    v4->CollectionScheduledFlags = 10;
  }
  else
  {
    Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(v4, 0, 2u);
    v4->MaxRootCount = v4->PresetMaxRootCount;
    v4->PeakRootCount = 0;
  }
  this->LastCollectionFootprint = heap->GetFootprint(heap);
}
