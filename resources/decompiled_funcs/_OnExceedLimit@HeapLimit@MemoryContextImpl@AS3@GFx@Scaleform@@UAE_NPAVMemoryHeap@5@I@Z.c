char __thiscall Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit::OnExceedLimit(
        Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit *this,
        Scaleform::MemoryHeap *heap,
        unsigned int overLimit)
{
  unsigned int v4; // ebx
  unsigned int UserLevelLimit; // eax
  unsigned int v7; // eax
  unsigned int LastCollectionFootprint; // eax
  unsigned int v9; // eax
  __int64 v10; // [esp+10h] [ebp-10h]
  unsigned int footprint; // [esp+18h] [ebp-8h]
  unsigned int heapLimit; // [esp+1Ch] [ebp-4h]

  footprint = heap->GetFootprint(heap);
  heapLimit = heap->Info.Desc.Limit;
  v10 = (__int64)(this->HeapLimitMultiplier * (double)footprint);
  v4 = overLimit + heapLimit + v10;
  if ( (int)(footprint - this->LastCollectionFootprint) < (int)v10 )
  {
    UserLevelLimit = this->UserLevelLimit;
    if ( !UserLevelLimit || v4 <= UserLevelLimit )
    {
      heap->SetLimit(heap, v4);
      this->CurrentLimit = heap->Info.Desc.Limit;
      return 1;
    }
  }
  Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit::Collect(this, heap);
  v7 = this->UserLevelLimit;
  if ( v7 && v4 > v7 )
  {
    LastCollectionFootprint = this->LastCollectionFootprint;
    if ( overLimit > footprint - LastCollectionFootprint )
    {
      v9 = overLimit + heapLimit + LastCollectionFootprint - footprint;
      this->CurrentLimit = v9;
      heap->SetLimit(heap, v9);
      this->CurrentLimit = heap->Info.Desc.Limit;
      return 1;
    }
    heap->SetLimit(heap, this->CurrentLimit);
    this->CurrentLimit = heap->Info.Desc.Limit;
  }
  return 1;
}
