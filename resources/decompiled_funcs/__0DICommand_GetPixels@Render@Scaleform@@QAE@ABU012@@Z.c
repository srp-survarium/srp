void __thiscall Scaleform::Render::DICommand_GetPixels::DICommand_GetPixels(
        Scaleform::Render::DICommand_GetPixels *this,
        const Scaleform::Render::DICommand_GetPixels *__that)
{
  Scaleform::Render::DrawableImage *pObject; // ecx
  int y2; // eax
  int x2; // ecx
  int y1; // edx

  this->__vftable = (Scaleform::Render::DICommand_GetPixels_vtbl *)&Scaleform::Render::DICommand::`vftable';
  pObject = __that->pImage.pObject;
  if ( pObject )
    pObject->AddRef(pObject);
  this->pImage.pObject = __that->pImage.pObject;
  this->__vftable = (Scaleform::Render::DICommand_GetPixels_vtbl *)&Scaleform::Render::DICommand_GetPixels::`vftable';
  y2 = __that->SourceRect.y2;
  x2 = __that->SourceRect.x2;
  y1 = __that->SourceRect.y1;
  this->SourceRect.x1 = __that->SourceRect.x1;
  this->SourceRect.y2 = y2;
  this->SourceRect.y1 = y1;
  this->SourceRect.x2 = x2;
  this->Provider = __that->Provider;
  this->Result = __that->Result;
}
