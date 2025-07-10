void __thiscall Scaleform::Render::RenderQueue::Shutdown(Scaleform::Render::RenderQueue *this)
{
  Scaleform::Render::RenderQueueItem *pQueue; // eax

  pQueue = this->pQueue;
  if ( pQueue )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pQueue);
    this->pQueue = 0;
  }
}
