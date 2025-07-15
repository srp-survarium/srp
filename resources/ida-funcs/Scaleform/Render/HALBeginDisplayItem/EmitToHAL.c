void __thiscall Scaleform::Render::HALBeginDisplayItem::EmitToHAL(
        Scaleform::Render::HALBeginDisplayItem *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  qp->pHAL->beginDisplay(qp->pHAL, (Scaleform::Render::BeginDisplayData *)item->Data);
}
