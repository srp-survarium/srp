void __thiscall Scaleform::Render::DICommand_PixelDissolve::DICommand_PixelDissolve(
        Scaleform::Render::DICommand_PixelDissolve *this,
        Scaleform::Render::DrawableImage *image,
        Scaleform::Render::DrawableImage *source,
        const Scaleform::Render::Rect<long> *sourceRect,
        const Scaleform::Render::Point<long> *destPoint,
        unsigned int randomSeed,
        unsigned int numPixels,
        Scaleform::Render::Color fill,
        unsigned int *result)
{
  int y2; // ecx
  int x2; // edx
  int y1; // edi
  int x; // edx

  this->__vftable = (Scaleform::Render::DICommand_PixelDissolve_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( image )
    image->AddRef(image);
  this->pImage.pObject = image;
  this->__vftable = (Scaleform::Render::DICommand_PixelDissolve_vtbl *)&Scaleform::Render::DICommand_PixelDissolve::`vftable';
  if ( source )
    source->AddRef(source);
  this->pSource.pObject = source;
  y2 = sourceRect->y2;
  x2 = sourceRect->x2;
  y1 = sourceRect->y1;
  this->SourceRect.x1 = sourceRect->x1;
  this->SourceRect.y1 = y1;
  this->SourceRect.x2 = x2;
  this->SourceRect.y2 = y2;
  x = destPoint->x;
  this->DestPoint.y = destPoint->y;
  this->DestPoint.x = x;
  this->RandomSeed = randomSeed;
  this->NumPixels = numPixels;
  this->Fill = fill;
  this->Result = result;
}
