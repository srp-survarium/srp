void __thiscall Scaleform::Render::DICommand_HitTest::DICommand_HitTest(
        Scaleform::Render::DICommand_HitTest *this,
        Scaleform::Render::DrawableImage *image,
        const Scaleform::Render::Point<long> *firstPoint,
        Scaleform::Render::Rect<long> *secondImage,
        unsigned int alphaThreshold,
        bool *result)
{
  int y2; // ecx
  int x2; // edx
  int y1; // edi
  int x; // edx

  this->__vftable = (Scaleform::Render::DICommand_HitTest_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( image )
    image->AddRef(image);
  this->pImage.pObject = image;
  this->__vftable = (Scaleform::Render::DICommand_HitTest_vtbl *)&Scaleform::Render::DICommand_HitTest::`vftable';
  this->SecondImage.pObject = 0;
  y2 = secondImage->y2;
  x2 = secondImage->x2;
  y1 = secondImage->y1;
  this->SecondArea.x1 = secondImage->x1;
  this->SecondArea.y1 = y1;
  this->SecondArea.y2 = y2;
  this->SecondArea.x2 = x2;
  x = firstPoint->x;
  this->FirstPoint.y = firstPoint->y;
  this->FirstPoint.x = x;
  this->FirstThreshold = alphaThreshold;
  this->SecondThreshold = 0;
  this->Result = result;
}
