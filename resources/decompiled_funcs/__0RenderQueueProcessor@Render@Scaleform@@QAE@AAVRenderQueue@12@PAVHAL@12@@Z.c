void __thiscall Scaleform::Render::RenderQueueProcessor::RenderQueueProcessor(
        Scaleform::Render::RenderQueueProcessor *this,
        Scaleform::Render::RenderQueue *queue,
        Scaleform::Render::HAL *hal)
{
  this->pHAL = hal;
  this->Caches.LockFlags = 0;
  this->Caches.pCaches[0] = 0;
  this->Caches.pCaches[1] = 0;
  this->Queue = queue;
  this->QueueMode = QM_WaitForFences;
  this->QueuePrepareFilter = QPF_All;
  this->QueueEmitFilter = QPF_All;
  this->CurrentItem.pQueue = 0;
  this->CurrentItem.QueuePos = 0;
  this->PrepareItemBuffer.pItem = 0;
  this->EmitItemBuffer.pItem = 0;
}
