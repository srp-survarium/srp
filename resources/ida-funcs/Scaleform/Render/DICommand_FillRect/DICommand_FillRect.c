void __thiscall Scaleform::Render::DICommand_FillRect::DICommand_FillRect(
        Scaleform::Render::DICommand_FillRect *this,
        const Scaleform::Render::DICommand_FillRect *__that)
{
  Scaleform::Render::DrawableImage *pObject; // ecx
  int y2; // eax
  int x2; // ecx
  int y1; // edx

  this->__vftable = (Scaleform::Render::DICommand_FillRect_vtbl *)&Scaleform::Render::DICommand::`vftable';
  pObject = __that->pImage.pObject;
  if ( pObject )
    pObject->AddRef(pObject);
  this->pImage.pObject = __that->pImage.pObject;
  this->__vftable = (Scaleform::Render::DICommand_FillRect_vtbl *)&Scaleform::Render::DICommand_FillRect::`vftable';
  y2 = __that->ApplyRect.y2;
  x2 = __that->ApplyRect.x2;
  y1 = __that->ApplyRect.y1;
  this->ApplyRect.x1 = __that->ApplyRect.x1;
  this->ApplyRect.y2 = y2;
  this->ApplyRect.y1 = y1;
  this->ApplyRect.x2 = x2;
  this->FillColor.Raw = __that->FillColor.Raw;
}
