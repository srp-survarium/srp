void __thiscall Scaleform::Render::HAL::Draw(
        Scaleform::Render::HAL *this,
        const Scaleform::Render::RenderQueueItem *item)
{
  Scaleform::Render::RenderQueue *p_Queue; // esi
  Scaleform::Render::RenderQueueProcessor *v3; // ebp
  Scaleform::Render::RenderQueueItem *v4; // eax
  unsigned int v5; // eax

  if ( item->pImpl == &Scaleform::Render::HALBeginDisplayItem::Instance || (this->HALState & 8) != 0 )
  {
    p_Queue = &this->Queue;
    v3 = this->GetRQProcessor(this);
    v4 = Scaleform::Render::RenderQueue::ReserveHead(p_Queue);
    if ( !v4 )
    {
      Scaleform::Render::RenderQueueProcessor::ProcessQueue(v3, QPM_One);
      v4 = Scaleform::Render::RenderQueue::ReserveHead(p_Queue);
    }
    *v4 = *item;
    v5 = ++p_Queue->QueueHead;
    p_Queue->HeadReserved = 0;
    if ( v5 == p_Queue->QueueSize )
      p_Queue->QueueHead = 0;
    Scaleform::Render::RenderQueueProcessor::ProcessQueue(v3, QPM_Any);
  }
}
