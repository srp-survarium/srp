Scaleform::Render::RenderQueueItem *__thiscall Scaleform::Render::RenderQueue::ReserveHead(
        Scaleform::Render::RenderQueue *this)
{
  unsigned int QueueHead; // edx
  unsigned int QueueTail; // eax

  QueueHead = this->QueueHead;
  QueueTail = this->QueueTail;
  if ( QueueHead > QueueTail )
  {
    if ( QueueTail + this->QueueSize == QueueHead + 1 )
      return 0;
  }
  else if ( QueueTail - QueueHead == 1 )
  {
    return 0;
  }
  this->HeadReserved = 1;
  return &this->pQueue[QueueHead];
}
