char __thiscall Scaleform::Render::DICommandQueue::AddCommand_NTS<Scaleform::Render::DICommand_GetPixel32>(
        Scaleform::Render::DICommandQueue *this,
        const Scaleform::Render::DICommand_GetPixel32 *src)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  Scaleform::Render::DrawableImage *pObject; // ecx

  v2 = Scaleform::Render::DICommandQueue::allocCommandFromPage(this, 0x14u, &this->QueueLock);
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
