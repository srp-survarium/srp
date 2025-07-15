unsigned int __thiscall Scaleform::Render::DICommand_PixelDissolve::GetSourceImages(
        Scaleform::Render::DICommand_PixelDissolve *this,
        Scaleform::Render::DISourceImages *ps)
{
  ps->pImages[0] = this->pSource.pObject;
  return 1;
}
