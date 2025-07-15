void __thiscall Scaleform::Render::FilterPrimitive::EmitToHAL(
        Scaleform::Render::FilterPrimitive *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  Scaleform::Render::HAL *pHAL; // eax
  Scaleform::Render::HAL_vtbl *v4; // edx

  if ( item != qp->EmitItemBuffer.pItem )
  {
    *(_QWORD *)&qp->EmitItemBuffer.pItem = (unsigned int)item;
    pHAL = qp->pHAL;
    v4 = qp->pHAL->__vftable;
    if ( this->Scaleform::Render::RenderQueueItem::Interface::__vftable )
      v4->PushFilters(pHAL, (Scaleform::Render::FilterPrimitive *)((char *)this - 8));
    else
      v4->PopFilters(pHAL);
  }
}
