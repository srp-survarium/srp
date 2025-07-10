Scaleform::Render::RenderQueueItem::QIPrepareResult __thiscall Scaleform::Render::Primitive::prepare(
        Scaleform::Render::Primitive *this,
        void *item,
        Scaleform::Render::PrimitivePrepareBuffer *prepareBuffer,
        Scaleform::Render::PrimitiveEmitBuffer *emitBuffer,
        Scaleform::Render::HAL *hal,
        Scaleform::Render::MeshCache *cache,
        BOOL waitForCache)
{
  if ( item != prepareBuffer->pItem )
    Scaleform::Render::PrimitivePrepareBuffer::StartPrimitive(prepareBuffer, item, this, emitBuffer, hal, cache);
  return Scaleform::Render::PrimitivePrepareBuffer::ProcessPrimitive(prepareBuffer, waitForCache);
}
