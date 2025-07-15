char __thiscall Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit::OnExceedLimit(
        Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit *this,
        Scaleform::MemoryHeap *heap,
        unsigned int overLimit)
{
  unsigned int v4; // ebx
  unsigned int UserLevelLimit; // eax
  Scaleform::Render::Text::Allocator *pObject; // ecx
  unsigned int v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // eax
  __int64 v11; // [esp+10h] [ebp-10h]
  unsigned int v12; // [esp+18h] [ebp-8h]
  unsigned int Limit; // [esp+1Ch] [ebp-4h]

  v12 = heap->GetFootprint(heap);
  Limit = heap->Info.Desc.Limit;
  v11 = (__int64)(this->HeapLimitMultiplier * (double)v12);
  v4 = overLimit + Limit + v11;
  if ( (int)(v12 - this->LastCollectionFootprint) < (int)v11 )
  {
    UserLevelLimit = this->UserLevelLimit;
    if ( !UserLevelLimit || v4 <= UserLevelLimit )
    {
      heap->SetLimit(heap, v4);
      this->CurrentLimit = heap->Info.Desc.Limit;
      return 1;
    }
  }
  pObject = this->MemContext->TextAllocator.pObject;
  if ( pObject )
  {
    Scaleform::Render::Text::Allocator::FlushTextFormatCache(pObject, 1);
    Scaleform::Render::Text::Allocator::FlushParagraphFormatCache(this->MemContext->TextAllocator.pObject, 1);
  }
  Scaleform::GFx::AS2::ASRefCountCollector::ForceEmergencyCollect(this->MemContext->ASGC.pObject);
  v8 = heap->GetFootprint(heap);
  v9 = this->UserLevelLimit;
  this->LastCollectionFootprint = v8;
  if ( v9 && v4 > v9 )
  {
    if ( overLimit > v12 - v8 )
    {
      v10 = overLimit + Limit + v8 - v12;
      this->CurrentLimit = v10;
      heap->SetLimit(heap, v10);
      this->CurrentLimit = heap->Info.Desc.Limit;
      return 1;
    }
    heap->SetLimit(heap, this->CurrentLimit);
    this->CurrentLimit = heap->Info.Desc.Limit;
  }
  return 1;
}
