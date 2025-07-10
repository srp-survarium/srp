char __thiscall Scaleform::Render::DICommandQueue::AddCommand_NTS<Scaleform::Render::DICommand_CopyPixels>(
        Scaleform::Render::DICommandQueue *this,
        const Scaleform::Render::DICommand_CopyPixels *src)
{
  Scaleform::Render::DICommand_SourceRect *v2; // eax
  Scaleform::Render::DICommand_SourceRect *v3; // esi
  Scaleform::Render::DrawableImage *pObject; // ecx
  int x; // edx

  v2 = (Scaleform::Render::DICommand_SourceRect *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                    this,
                                                    0x34u,
                                                    &this->QueueLock);
  v3 = v2;
  if ( !v2 )
    return 0;
  Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(v2, src);
  v3->__vftable = (Scaleform::Render::DICommand_SourceRect_vtbl *)&Scaleform::Render::DICommand_CopyPixels::`vftable';
  pObject = src->pAlphaSource.pObject;
  if ( pObject )
    pObject->AddRef(pObject);
  v3[1].__vftable = (Scaleform::Render::DICommand_SourceRect_vtbl *)src->pAlphaSource.pObject;
  x = src->AlphaPoint.x;
  v3[1].pSource.pObject = (Scaleform::Render::DrawableImage *)src->AlphaPoint.y;
  v3[1].pImage.pObject = (Scaleform::Render::DrawableImage *)x;
  LOBYTE(v3[1].SourceRect.x1) = src->MergeAlpha;
  return 1;
}
