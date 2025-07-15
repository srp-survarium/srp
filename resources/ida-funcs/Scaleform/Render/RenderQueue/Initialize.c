char __thiscall Scaleform::Render::RenderQueue::Initialize(
        Scaleform::Render::RenderQueue *this,
        unsigned int itemCount)
{
  Scaleform::Render::RenderQueueItem *v4; // eax
  unsigned int v5; // eax
  Scaleform::Render::RenderQueueItem *v6; // ecx

  if ( itemCount < 2 )
    return 0;
  v4 = (Scaleform::Render::RenderQueueItem *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                               Scaleform::Memory::pGlobalHeap,
                                               this,
                                               8 * itemCount,
                                               0);
  this->pQueue = v4;
  this->QueueSize = itemCount;
  if ( !v4 )
    return 0;
  v5 = 0;
  do
  {
    v6 = &this->pQueue[v5++];
    v6->pImpl = 0;
    v6->Data = 0;
  }
  while ( v5 < this->QueueSize );
  return 1;
}
