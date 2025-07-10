void __thiscall Scaleform::Render::HALEndDisplayItem::EmitToHAL(
        Scaleform::Render::HALEndDisplayItem *this,
        Scaleform::Render::RenderQueueItem *__formal,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  qp->pHAL->endDisplay(qp->pHAL);
}
