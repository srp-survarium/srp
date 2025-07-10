unsigned int __thiscall Scaleform::Render::DICommand_HitTest::GetSourceImages(
        Scaleform::Render::DICommand_HitTest *this,
        Scaleform::Render::DISourceImages *ps)
{
  Scaleform::Render::Image *pObject; // eax

  pObject = this->SecondImage.pObject;
  if ( !pObject )
    return 0;
  ps->pImages[0] = pObject;
  return 1;
}
