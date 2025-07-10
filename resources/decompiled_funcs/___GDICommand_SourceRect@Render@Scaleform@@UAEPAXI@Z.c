Scaleform::Render::DICommand_Threshold *__thiscall Scaleform::Render::DICommand_SourceRect::`scalar deleting destructor'(
        Scaleform::Render::DICommand_Threshold *this,
        char a2)
{
  Scaleform::Render::DrawableImage *pObject; // ecx
  Scaleform::Render::DrawableImage *v4; // ecx

  pObject = this->pSource.pObject;
  if ( pObject )
    pObject->Release(pObject);
  this->__vftable = (Scaleform::Render::DICommand_Threshold_vtbl *)&Scaleform::Render::DICommand::`vftable';
  v4 = this->pImage.pObject;
  if ( v4 )
    v4->Release(v4);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
