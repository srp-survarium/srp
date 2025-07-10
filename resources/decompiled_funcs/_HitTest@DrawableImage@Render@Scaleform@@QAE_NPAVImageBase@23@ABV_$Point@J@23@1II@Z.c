char __thiscall Scaleform::Render::DrawableImage::HitTest(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Image *secondImage,
        const Scaleform::Render::Point<long> *firstPoint,
        const Scaleform::Render::Point<long> *secondPoint,
        unsigned int firstThreshold,
        unsigned int secondThreshold)
{
  char v7; // bl
  Scaleform::Render::DICommand_HitTest cmd; // [esp+8h] [ebp-38h] BYREF

  Scaleform::Render::DICommand_HitTest::DICommand_HitTest(
    &cmd,
    this,
    secondImage,
    firstPoint,
    secondPoint,
    firstThreshold,
    secondThreshold,
    (bool *)&secondThreshold);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_HitTest>(this, &cmd);
  v7 = secondThreshold;
  if ( cmd.SecondImage.pObject )
    cmd.SecondImage.pObject->Release(cmd.SecondImage.pObject);
  cmd.__vftable = (Scaleform::Render::DICommand_HitTest_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( cmd.pImage.pObject )
    cmd.pImage.pObject->Release(cmd.pImage.pObject);
  return v7;
}
