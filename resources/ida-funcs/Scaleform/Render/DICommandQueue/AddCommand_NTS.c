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


char __thiscall Scaleform::Render::DICommandQueue::AddCommand_NTS<Scaleform::Render::DICommand_FloodFill>(
        Scaleform::Render::DICommandQueue *this,
        const Scaleform::Render::DICommand_FloodFill *src)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  Scaleform::Render::DrawableImage *pObject; // ecx
  int x; // edx

  v2 = (_DWORD *)Scaleform::Render::DICommandQueue::allocCommandFromPage(this, 0x14u, &this->QueueLock);
  v3 = v2;
  if ( !v2 )
    return 0;
  *v2 = &Scaleform::Render::DICommand::`vftable';
  pObject = src->pImage.pObject;
  if ( pObject )
    pObject->AddRef(pObject);
  v3[1] = src->pImage.pObject;
  *v3 = &Scaleform::Render::DICommand_FloodFill::`vftable';
  x = src->Pt.x;
  v3[3] = src->Pt.y;
  v3[2] = x;
  v3[4] = src->FillColor.Raw;
  return 1;
}


char __thiscall Scaleform::Render::DICommandQueue::AddCommand_NTS<Scaleform::Render::DICommand_GetPixel32>(
        Scaleform::Render::DICommandQueue *this,
        const Scaleform::Render::DICommand_GetPixel32 *src)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  Scaleform::Render::DrawableImage *pObject; // ecx

  v2 = (_DWORD *)Scaleform::Render::DICommandQueue::allocCommandFromPage(this, 0x14u, &this->QueueLock);
  v3 = v2;
  if ( !v2 )
    return 0;
  *v2 = &Scaleform::Render::DICommand::`vftable';
  pObject = src->pImage.pObject;
  if ( pObject )
    pObject->AddRef(pObject);
  v3[1] = src->pImage.pObject;
  *v3 = &Scaleform::Render::DICommand_GetPixel32::`vftable';
  v3[2] = src->X;
  v3[3] = src->Y;
  v3[4] = src->Result;
  return 1;
}


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
