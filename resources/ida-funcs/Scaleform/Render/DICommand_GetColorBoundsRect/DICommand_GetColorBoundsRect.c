void __thiscall Scaleform::Render::DICommand_GetColorBoundsRect::DICommand_GetColorBoundsRect(
        Scaleform::Render::DICommand_GetColorBoundsRect *this,
        const Scaleform::Render::DICommand_GetColorBoundsRect *__that)
{
  Scaleform::Render::DrawableImage *pObject; // ecx

  this->__vftable = (Scaleform::Render::DICommand_GetColorBoundsRect_vtbl *)&Scaleform::Render::DICommand::`vftable';
  pObject = __that->pImage.pObject;
  if ( pObject )
    pObject->AddRef(pObject);
  this->pImage.pObject = __that->pImage.pObject;
  this->__vftable = (Scaleform::Render::DICommand_GetColorBoundsRect_vtbl *)&Scaleform::Render::DICommand_GetColorBoundsRect::`vftable';
  this->Mask = __that->Mask;
  this->SearchColor = __that->SearchColor;
  this->FindColor = __that->FindColor;
  this->Result = __that->Result;
}
