Scaleform::Render::DICommand_SetPixels *__thiscall Scaleform::Render::DICommand_Clear::`vector deleting destructor'(
        Scaleform::Render::DICommand_SetPixels *this,
        char a2)
{
  Scaleform::Render::DrawableImage *pObject; // ecx

  this->__vftable = (Scaleform::Render::DICommand_SetPixels_vtbl *)&Scaleform::Render::DICommand::`vftable';
  pObject = this->pImage.pObject;
  if ( pObject )
    pObject->Release(pObject);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
