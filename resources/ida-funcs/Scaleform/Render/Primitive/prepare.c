Scaleform::Render::RenderQueueItem::QIPrepareResult __thiscall Scaleform::Render::Primitive::Prepare(
        Scaleform::Render::Primitive *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp,
        BOOL waitForCache)
{
  $2E77AADB348E850F7026E464A107CF04 *v5; // esi

  if ( qp->QueuePrepareFilter )
    return 0;
  v5 = &qp->40;
  if ( item != qp->PrepareItemBuffer.pItem )
    Scaleform::Render::PrimitivePrepareBuffer::StartPrimitive(
      (Scaleform::Render::PrimitivePrepareBuffer *)v5,
      item,
      (Scaleform::Render::Primitive *)((char *)this - 8),
      (Scaleform::Render::PrimitiveEmitBuffer *)&qp->136,
      qp->pHAL,
      (Scaleform::Render::MeshCache *)qp->Caches.pCaches[0]);
  return Scaleform::Render::PrimitivePrepareBuffer::ProcessPrimitive(
           (Scaleform::Render::PrimitivePrepareBuffer *)v5,
           waitForCache);
}
