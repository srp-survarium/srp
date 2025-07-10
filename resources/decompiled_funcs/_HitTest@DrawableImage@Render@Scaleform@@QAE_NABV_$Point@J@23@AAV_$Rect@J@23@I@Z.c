bool __thiscall Scaleform::Render::DrawableImage::HitTest(
        Scaleform::Render::DrawableImage *this,
        const Scaleform::Render::Point<long> *firstPoint,
        Scaleform::Render::Rect<long> *secondImage,
        unsigned int alphaThreshold)
{
  char v5; // bl
  Scaleform::Render::DICommand_HitTest cmd; // [esp+8h] [ebp-38h] BYREF

  Scaleform::Render::DICommand_HitTest::DICommand_HitTest(
    &cmd,
    this,
    firstPoint,
    secondImage,
    alphaThreshold,
    (bool *)&alphaThreshold);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_HitTest>(this, &cmd);
  v5 = alphaThreshold;
  if ( cmd.SecondImage.pObject )
    cmd.SecondImage.pObject->Release(cmd.SecondImage.pObject);
  cmd.__vftable = (Scaleform::Render::DICommand_HitTest_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( cmd.pImage.pObject )
    cmd.pImage.pObject->Release(cmd.pImage.pObject);
  return v5;
}
