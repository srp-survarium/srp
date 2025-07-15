void __thiscall Scaleform::Render::TextPrimitiveBundle::EmitToHAL(
        Scaleform::Render::TextPrimitiveBundle *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  if ( qp->QueueEmitFilter == QPF_All )
  {
    if ( item != qp->EmitItemBuffer.pItem )
    {
      qp->EmitItemBuffer.pItem = item;
      *(_QWORD *)&qp->EmitItemBufferBytes[4] = (unsigned int)&this[-1].pTop;
      *(_QWORD *)&qp->EmitItemBufferBytes[12] = 0;
    }
    Scaleform::Render::TextEmitBuffer::EmitPrimitive(
      (Scaleform::Render::TextEmitBuffer *)&qp->136,
      (Scaleform::Render::PrimitivePrepareBuffer *)&qp->40,
      qp->pHAL);
  }
}
