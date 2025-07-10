void __thiscall Scaleform::Render::MaskPrimitive::EmitToHAL(
        Scaleform::Render::MaskPrimitive *this,
        Scaleform::Render::RenderQueueItem *__formal,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  if ( qp->QueueEmitFilter == QPF_All )
    qp->pHAL->PushMask_BeginSubmit(qp->pHAL, (Scaleform::Render::MaskPrimitive *)&this[-1].MaskAreas.Data.Size);
}
