void __thiscall Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit::Collect(
        Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::Render::Text::Allocator *pObject; // ecx
  Scaleform::AmpServer *Instance; // eax
  Scaleform::GFx::AS3::ASRefCountCollector *v5; // esi
  unsigned int PresetMaxRootCount; // edx
  Scaleform::GFx::AS3::ASRefCountCollector *v7; // esi
  Scaleform::GFx::MovieImpl *movie; // [esp+Ch] [ebp-4h] BYREF

  pObject = this->MemContext->TextAllocator.pObject;
  if ( pObject )
  {
    Scaleform::Render::Text::Allocator::FlushTextFormatCache(pObject, 1);
    Scaleform::Render::Text::Allocator::FlushParagraphFormatCache(this->MemContext->TextAllocator.pObject, 1);
  }
  Instance = Scaleform::AmpServer::GetInstance();
  if ( Instance->FindMovieByHeap(Instance, heap, &movie) )
  {
    v5 = this->MemContext->ASGC.pObject;
    if ( v5->SuspendCnt )
    {
      v5->CollectionScheduledFlags = 10;
    }
    else
    {
      Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(
        v5,
        (Scaleform::GFx::Resource *)movie->AdvanceStats.pObject,
        2u);
      PresetMaxRootCount = v5->PresetMaxRootCount;
      v5->PeakRootCount = 0;
      v5->MaxRootCount = PresetMaxRootCount;
    }
    Scaleform::GFx::Movie::Release(movie, (int)this);
    this->LastCollectionFootprint = heap->GetFootprint(heap);
  }
  else
  {
    v7 = this->MemContext->ASGC.pObject;
    if ( v7->SuspendCnt )
    {
      v7->CollectionScheduledFlags = 10;
    }
    else
    {
      Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(v7, 0, 2u);
      v7->MaxRootCount = v7->PresetMaxRootCount;
      v7->PeakRootCount = 0;
    }
    this->LastCollectionFootprint = heap->GetFootprint(heap);
  }
}
