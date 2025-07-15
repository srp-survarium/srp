void __thiscall Scaleform::Render::DICommand_HitTest::DICommand_HitTest(
        Scaleform::Render::DICommand_HitTest *this,
        const Scaleform::Render::DICommand_HitTest *__that)
{
  Scaleform::Render::DrawableImage *pObject; // ecx
  Scaleform::Render::Image *v4; // ecx
  int y2; // eax
  int x2; // ecx
  int y1; // edx
  int x; // edx
  int v9; // ecx

  this->__vftable = (Scaleform::Render::DICommand_HitTest_vtbl *)&Scaleform::Render::DICommand::`vftable';
  pObject = __that->pImage.pObject;
  if ( pObject )
    pObject->AddRef(pObject);
  this->pImage.pObject = __that->pImage.pObject;
  this->__vftable = (Scaleform::Render::DICommand_HitTest_vtbl *)&Scaleform::Render::DICommand_HitTest::`vftable';
  v4 = __that->SecondImage.pObject;
  if ( v4 )
    v4->AddRef(v4);
  this->SecondImage.pObject = __that->SecondImage.pObject;
  y2 = __that->SecondArea.y2;
  x2 = __that->SecondArea.x2;
  y1 = __that->SecondArea.y1;
  this->SecondArea.x1 = __that->SecondArea.x1;
  this->SecondArea.y2 = y2;
  this->SecondArea.y1 = y1;
  this->SecondArea.x2 = x2;
  x = __that->FirstPoint.x;
  this->FirstPoint.y = __that->FirstPoint.y;
  this->FirstPoint.x = x;
  v9 = __that->SecondPoint.x;
  this->SecondPoint.y = __that->SecondPoint.y;
  this->SecondPoint.x = v9;
  this->FirstThreshold = __that->FirstThreshold;
  this->SecondThreshold = __that->SecondThreshold;
  this->Result = __that->Result;
}


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
