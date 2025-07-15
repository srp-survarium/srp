unsigned int __thiscall Scaleform::Render::DICommand_CopyPixels::GetSourceImages(
        Scaleform::Render::DICommand_CopyPixels *this,
        Scaleform::Render::DISourceImages *ps)
{
  Scaleform::Render::DrawableImage *pObject; // ecx
  unsigned int result; // eax

  ps->pImages[0] = this->pSource.pObject;
  pObject = this->pAlphaSource.pObject;
  result = 1;
  if ( pObject )
  {
    ps->pImages[1] = pObject;
    return 2;
  }
  return result;
}
