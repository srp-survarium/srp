void __thiscall Scaleform::Render::RenderQueueProcessor::ProcessQueue(
        Scaleform::Render::RenderQueueProcessor *this,
        Scaleform::Render::RenderQueueProcessor::QueueProcessMode mode)
{
  Scaleform::Render::RenderQueueItem *v3; // edi
  int i; // eax
  int v5; // [esp+18h] [ebp-4h]

  LOBYTE(v5) = 0;
  if ( mode )
  {
    if ( this->QueueMode )
    {
      if ( this->Caches.LockFlags )
        Scaleform::Render::RQCacheInterface::UnlockCaches(&this->Caches);
    }
    else
    {
      LOBYTE(v5) = 1;
    }
  }
  while ( this->CurrentItem.QueuePos != this->Queue->QueueHead )
  {
    v3 = &this->CurrentItem.pQueue->pQueue[this->CurrentItem.QueuePos];
    for ( i = ((int (__stdcall *)(Scaleform::Render::RenderQueueItem *, Scaleform::Render::RenderQueueProcessor *, int))v3->pImpl->Prepare)(
                v3,
                this,
                v5);
          i;
          i = ((int (__stdcall *)(Scaleform::Render::RenderQueueItem *, Scaleform::Render::RenderQueueProcessor *, int))v3->pImpl->Prepare)(
                v3,
                this,
                v5) )
    {
      if ( i == 1 )
        LOBYTE(v5) = 1;
      Scaleform::Render::RenderQueueProcessor::drawProcessedPrimitives(this);
    }
    if ( mode == QPM_One )
      LOBYTE(v5) = 0;
    if ( ++this->CurrentItem.QueuePos == this->CurrentItem.pQueue->QueueSize )
      this->CurrentItem.QueuePos = 0;
  }
  if ( this->QueueMode != QM_ExtendLocks || !this->Caches.LockFlags )
    Scaleform::Render::RenderQueueProcessor::drawProcessedPrimitives(this);
}
