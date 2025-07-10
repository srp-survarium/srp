void __thiscall Scaleform::Render::RenderQueueProcessor::drawProcessedPrimitives(
        Scaleform::Render::RenderQueueProcessor *this)
{
  Scaleform::Render::RenderQueue *Queue; // esi
  Scaleform::Render::RenderQueueItem *v3; // eax
  Scaleform::Render::RenderQueueItem *v4; // eax

  Queue = this->Queue;
  if ( this->Caches.LockFlags )
    Scaleform::Render::RQCacheInterface::UnlockCaches(&this->Caches);
  while ( Queue->QueueTail != this->CurrentItem.QueuePos )
  {
    v3 = &Queue->pQueue[Queue->QueueTail];
    v3->pImpl->EmitToHAL(v3->pImpl, v3, this);
    v4 = &Queue->pQueue[Queue->QueueTail];
    v4->pImpl = 0;
    v4->Data = 0;
    if ( ++Queue->QueueTail == Queue->QueueSize )
      Queue->QueueTail = 0;
  }
  if ( this->CurrentItem.QueuePos != Queue->QueueHead )
    Queue->pQueue[Queue->QueueTail].pImpl->EmitToHAL(
      Queue->pQueue[Queue->QueueTail].pImpl,
      &Queue->pQueue[Queue->QueueTail],
      this);
}
