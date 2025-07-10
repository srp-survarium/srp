void __thiscall Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(
        Scaleform::Render::DICommand_SourceRect *this,
        const Scaleform::Render::DICommand_SourceRect *__that)
{
  Scaleform::Render::DrawableImage *pObject; // ecx
  Scaleform::Render::DrawableImage *v4; // ecx
  int y2; // eax
  int y1; // edx
  int x2; // ecx
  int x; // edx

  this->__vftable = (Scaleform::Render::DICommand_SourceRect_vtbl *)&Scaleform::Render::DICommand::`vftable';
  pObject = __that->pImage.pObject;
  if ( pObject )
    pObject->AddRef(pObject);
  this->pImage.pObject = __that->pImage.pObject;
  this->__vftable = (Scaleform::Render::DICommand_SourceRect_vtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable';
  v4 = __that->pSource.pObject;
  if ( v4 )
    v4->AddRef(v4);
  this->pSource.pObject = __that->pSource.pObject;
  y2 = __that->SourceRect.y2;
  y1 = __that->SourceRect.y1;
  x2 = __that->SourceRect.x2;
  this->SourceRect.x1 = __that->SourceRect.x1;
  this->SourceRect.y2 = y2;
  this->SourceRect.y1 = y1;
  this->SourceRect.x2 = x2;
  x = __that->DestPoint.x;
  this->DestPoint.y = __that->DestPoint.y;
  this->DestPoint.x = x;
}
