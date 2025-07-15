void __thiscall Scaleform::Render::SKI_MaskEnd::RQII_EndMask::EmitToHAL(
        Scaleform::Render::SKI_MaskEnd::RQII_EndMask *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  Scaleform::Render::HAL *pHAL; // ecx
  void *Data; // eax

  if ( qp->QueueEmitFilter == QPF_All )
  {
    pHAL = qp->pHAL;
    Data = item->Data;
    if ( Data == (void *)2 )
    {
      pHAL->EndMaskSubmit(pHAL);
    }
    else if ( Data == (void *)3 )
    {
      pHAL->PopMask(pHAL);
    }
  }
}
