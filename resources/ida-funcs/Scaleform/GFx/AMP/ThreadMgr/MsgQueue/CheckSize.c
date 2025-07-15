void __thiscall Scaleform::GFx::AMP::ThreadMgr::MsgQueue::CheckSize(
        Scaleform::GFx::AMP::ThreadMgr::MsgQueue *this,
        Scaleform::MemoryHeap *heap)
{
  unsigned int Limit; // ebp
  bool v4; // bl
  bool v5; // al
  bool v6; // dl
  unsigned int MaxSize; // ecx
  bool v8; // al

  if ( this->SizeEvent )
  {
    Limit = heap->Info.Desc.Limit;
    v4 = Limit && heap->GetFootprint(heap) > Limit;
    v5 = this->MaxSize && this->QueueSize.Value > this->MaxSize;
    if ( v4 || v5 )
    {
      Scaleform::Event::ResetEvent(this->SizeEvent);
      if ( v4 && this->QueueSize.Value < 2 )
        heap->SetLimit(heap, 2 * Limit);
    }
    else
    {
      v6 = !Limit || 100 * (int)heap->GetFootprint(heap) < Limit * this->SizeCheckHysterisisPercent;
      MaxSize = this->MaxSize;
      v8 = !MaxSize || 100 * this->QueueSize.Value < MaxSize * this->SizeCheckHysterisisPercent;
      if ( v6 && v8 )
        Scaleform::Event::SetEvent(this->SizeEvent);
    }
  }
}
