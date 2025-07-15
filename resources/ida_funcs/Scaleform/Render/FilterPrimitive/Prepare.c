Scaleform::Render::RenderQueueItem::QIPrepareResult __thiscall Scaleform::Render::FilterPrimitive::Prepare(
        Scaleform::Render::FilterPrimitive *this,
        Scaleform::Render::RenderQueueItem *__formal,
        Scaleform::Render::RenderQueueProcessor *qp,
        bool a4)
{
  qp->pHAL->PrepareFilters(qp->pHAL, (Scaleform::Render::FilterPrimitive *)&this[-1].CacheResults[1]);
  return 0;
}
