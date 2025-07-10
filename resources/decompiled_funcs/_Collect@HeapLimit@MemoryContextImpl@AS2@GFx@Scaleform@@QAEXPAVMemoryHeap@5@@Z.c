void __thiscall Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit::Collect(
        Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::Render::Text::Allocator *pObject; // ecx

  pObject = this->MemContext->TextAllocator.pObject;
  if ( pObject )
  {
    Scaleform::Render::Text::Allocator::FlushTextFormatCache(pObject, 1);
    Scaleform::Render::Text::Allocator::FlushParagraphFormatCache(this->MemContext->TextAllocator.pObject, 1);
  }
  Scaleform::GFx::AS2::ASRefCountCollector::ForceEmergencyCollect(this->MemContext->ASGC.pObject);
  this->LastCollectionFootprint = heap->GetFootprint(heap);
}
