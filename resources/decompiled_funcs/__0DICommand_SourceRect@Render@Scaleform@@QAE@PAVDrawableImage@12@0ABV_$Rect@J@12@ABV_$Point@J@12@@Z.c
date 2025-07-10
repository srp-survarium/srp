void __thiscall Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(
        Scaleform::Render::DICommand_SourceRect *this,
        Scaleform::Render::DrawableImage *image,
        Scaleform::Render::DrawableImage *source,
        const Scaleform::Render::Rect<long> *sr,
        const Scaleform::Render::Point<long> *dp)
{
  int y2; // ecx
  int x2; // edx
  int y1; // edi
  int y; // ecx

  this->__vftable = (Scaleform::Render::DICommand_SourceRect_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( image )
    image->AddRef(image);
  this->pImage.pObject = image;
  this->__vftable = (Scaleform::Render::DICommand_SourceRect_vtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable';
  if ( source )
    source->AddRef(source);
  this->pSource.pObject = source;
  y2 = sr->y2;
  x2 = sr->x2;
  y1 = sr->y1;
  this->SourceRect.x1 = sr->x1;
  this->SourceRect.y1 = y1;
  this->SourceRect.x2 = x2;
  this->SourceRect.y2 = y2;
  y = dp->y;
  this->DestPoint.x = dp->x;
  this->DestPoint.y = y;
}
