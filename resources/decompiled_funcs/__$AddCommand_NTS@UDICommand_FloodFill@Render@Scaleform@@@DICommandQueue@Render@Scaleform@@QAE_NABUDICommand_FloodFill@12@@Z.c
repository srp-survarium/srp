char __thiscall Scaleform::Render::DICommandQueue::AddCommand_NTS<Scaleform::Render::DICommand_FloodFill>(
        Scaleform::Render::DICommandQueue *this,
        const Scaleform::Render::DICommand_FloodFill *src)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  Scaleform::Render::DrawableImage *pObject; // ecx
  int x; // edx

  v2 = Scaleform::Render::DICommandQueue::allocCommandFromPage(this, 0x14u, &this->QueueLock);
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
