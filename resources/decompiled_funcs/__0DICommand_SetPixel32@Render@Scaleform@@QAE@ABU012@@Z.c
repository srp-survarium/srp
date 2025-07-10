void __thiscall Scaleform::Render::DICommand_SetPixel32::DICommand_SetPixel32(
        Scaleform::Render::DICommand_SetPixel32 *this,
        const Scaleform::Render::DICommand_SetPixel32 *__that)
{
  Scaleform::Render::DrawableImage *pObject; // ecx

  this->__vftable = (Scaleform::Render::DICommand_SetPixel32_vtbl *)&Scaleform::Render::DICommand::`vftable';
  pObject = __that->pImage.pObject;
  if ( pObject )
    pObject->AddRef(pObject);
  this->pImage.pObject = __that->pImage.pObject;
  this->__vftable = (Scaleform::Render::DICommand_SetPixel32_vtbl *)&Scaleform::Render::DICommand_SetPixel32::`vftable';
  this->X = __that->X;
  this->Y = __that->Y;
  this->Fill.Raw = __that->Fill.Raw;
  this->OverwriteAlpha = __that->OverwriteAlpha;
  this->Result = __that->Result;
}
