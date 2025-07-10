void __thiscall Scaleform::Render::RenderQueueProcessor::BeginFrame(Scaleform::Render::RenderQueueProcessor *this)
{
  Scaleform::Render::MeshCache *v2; // edi
  Scaleform::Render::RenderQueue *Queue; // eax
  unsigned int QueueTail; // ecx

  v2 = this->pHAL->GetMeshCache(this->pHAL);
  this->QueueMode = v2->GetQueueMode(v2);
  Scaleform::Render::MeshCache::SetRQCacheInterface(v2, &this->Caches);
  Queue = this->Queue;
  QueueTail = Queue->QueueTail;
  this->CurrentItem.pQueue = Queue;
  this->CurrentItem.QueuePos = QueueTail;
}
