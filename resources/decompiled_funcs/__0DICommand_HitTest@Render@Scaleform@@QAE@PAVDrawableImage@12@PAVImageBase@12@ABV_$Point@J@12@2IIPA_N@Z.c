void __thiscall Scaleform::Render::DICommand_HitTest::DICommand_HitTest(
        Scaleform::Render::DICommand_HitTest *this,
        Scaleform::Render::DrawableImage *image,
        Scaleform::Render::Image *secondImage,
        const Scaleform::Render::Point<long> *firstPoint,
        const Scaleform::Render::Point<long> *secondPoint,
        unsigned int firstThreshold,
        unsigned int secondThreshold,
        bool *result)
{
  int y; // ecx
  int v10; // ecx

  this->__vftable = (Scaleform::Render::DICommand_HitTest_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( image )
    image->AddRef(image);
  this->pImage.pObject = image;
  this->__vftable = (Scaleform::Render::DICommand_HitTest_vtbl *)&Scaleform::Render::DICommand_HitTest::`vftable';
  if ( secondImage )
    secondImage->AddRef(secondImage);
  this->SecondImage.pObject = secondImage;
  this->SecondArea.x1 = 0;
  this->SecondArea.y1 = 0;
  this->SecondArea.x2 = 0;
  this->SecondArea.y2 = 0;
  y = firstPoint->y;
  this->FirstPoint.x = firstPoint->x;
  this->FirstPoint.y = y;
  v10 = secondPoint->y;
  this->SecondPoint.x = secondPoint->x;
  this->SecondPoint.y = v10;
  this->FirstThreshold = firstThreshold;
  this->SecondThreshold = secondThreshold;
  this->Result = result;
}
