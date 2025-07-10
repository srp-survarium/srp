int __thiscall Scaleform::Render::ComplexPrimitiveBundle::Prepare(
        Scaleform::Render::ComplexPrimitiveBundle *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp,
        bool waitForCache)
{
  if ( qp->QueuePrepareFilter )
    return 0;
  if ( Scaleform::Render::MeshCache::PrepareComplexMesh(
         (Scaleform::Render::MeshCache *)qp->Caches.pCaches[0],
         *(Scaleform::Render::ComplexMesh **)(this->RefCount + 8 * (int)item->Data + 4),
         waitForCache)
    || item == qp->PrepareItemBuffer.pItem )
  {
    qp->PrepareItemBuffer.pItem = 0;
    return 0;
  }
  else
  {
    qp->PrepareItemBuffer.pItem = item;
    return 1;
  }
}
