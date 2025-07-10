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
