void __thiscall Scaleform::Render::SKI_BlendMode::RQII_BlendMode::EmitToHAL(
        Scaleform::Render::SKI_BlendMode::RQII_BlendMode *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  Scaleform::Render::HAL_vtbl *v3; // edx

  if ( qp->QueueEmitFilter == QPF_All )
  {
    v3 = qp->pHAL->__vftable;
    if ( item->Data == (void *)-1 )
      ((void (*)(void))v3->PopBlendMode)();
    else
      ((void (__stdcall *)(void *))v3->PushBlendMode)(item->Data);
  }
}
