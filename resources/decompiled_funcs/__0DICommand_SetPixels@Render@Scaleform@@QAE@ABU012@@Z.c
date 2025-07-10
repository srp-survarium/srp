void __thiscall Scaleform::Render::DICommand_SetPixels::DICommand_SetPixels(
        Scaleform::Render::DICommand_SetPixels *this,
        const Scaleform::Render::DICommand_SetPixels *__that)
{
  Scaleform::Render::DrawableImage *pObject; // ecx
  int y2; // eax
  int x2; // ecx
  int y1; // edx

  this->__vftable = (Scaleform::Render::DICommand_SetPixels_vtbl *)&Scaleform::Render::DICommand::`vftable';
  pObject = __that->pImage.pObject;
  if ( pObject )
    pObject->AddRef(pObject);
  this->pImage.pObject = __that->pImage.pObject;
  this->__vftable = (Scaleform::Render::DICommand_SetPixels_vtbl *)&Scaleform::Render::DICommand_SetPixels::`vftable';
  y2 = __that->DestRect.y2;
  x2 = __that->DestRect.x2;
  y1 = __that->DestRect.y1;
  this->DestRect.x1 = __that->DestRect.x1;
  this->DestRect.y2 = y2;
  this->DestRect.y1 = y1;
  this->DestRect.x2 = x2;
  this->Provider = __that->Provider;
  this->Result = __that->Result;
}
