char __thiscall Scaleform::Render::DICommandQueue::AddCommand_NTS<Scaleform::Render::DICommand_Threshold>(
        Scaleform::Render::DICommandQueue *this,
        const Scaleform::Render::DICommand_Threshold *src)
{
  Scaleform::Render::DICommand_SourceRect *v2; // eax
  Scaleform::Render::DICommand_SourceRect *v3; // esi

  v2 = (Scaleform::Render::DICommand_SourceRect *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                    this,
                                                    0x38u,
                                                    &this->QueueLock);
  v3 = v2;
  if ( !v2 )
    return 0;
  Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(v2, src);
  v3->__vftable = (Scaleform::Render::DICommand_SourceRect_vtbl *)&Scaleform::Render::DICommand_Threshold::`vftable';
  v3[1].__vftable = (Scaleform::Render::DICommand_SourceRect_vtbl *)src->Operation;
  v3[1].pImage.pObject = (Scaleform::Render::DrawableImage *)src->Threshold;
  v3[1].pSource.pObject = (Scaleform::Render::DrawableImage *)src->ThresholdColor;
  v3[1].SourceRect.x1 = src->Mask;
  LOBYTE(v3[1].SourceRect.y1) = src->CopySource;
  return 1;
}
