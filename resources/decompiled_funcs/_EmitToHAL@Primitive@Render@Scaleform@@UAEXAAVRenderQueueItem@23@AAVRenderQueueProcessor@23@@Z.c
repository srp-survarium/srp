void __thiscall Scaleform::Render::Primitive::EmitToHAL(
        Scaleform::Render::Primitive *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  if ( qp->QueueEmitFilter == QPF_All )
    Scaleform::Render::Primitive::emitToHAL(
      (Scaleform::Render::Primitive *)((char *)this - 8),
      item,
      (Scaleform::Render::PrimitivePrepareBuffer *)&qp->40,
      (Scaleform::Render::PrimitiveEmitBuffer *)&qp->136,
      qp->pHAL);
}
