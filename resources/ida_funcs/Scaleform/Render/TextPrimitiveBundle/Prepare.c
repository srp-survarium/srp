int __thiscall Scaleform::Render::TextPrimitiveBundle::Prepare(
        Scaleform::Render::TextPrimitiveBundle *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp,
        BOOL waitForCache)
{
  if ( qp->QueuePrepareFilter )
    return 0;
  if ( item != qp->PrepareItemBuffer.pItem )
    Scaleform::Render::TextPrimitiveBundle::startPrimitive(
      (Scaleform::Render::TextPrimitiveBundle *)((char *)this - 32),
      item,
      (Scaleform::Render::TextPrepareBuffer *)&qp->40,
      qp);
  return Scaleform::Render::TextPrepareBuffer::ProcessPrimitive(
           (Scaleform::Render::TextPrepareBuffer *)&qp->40,
           waitForCache);
}
