unsigned int __thiscall Scaleform::Render::DrawableImage::PixelDissolve(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *source,
        const Scaleform::Render::Rect<long> *sourceRect,
        const Scaleform::Render::Point<long> *destPoint,
        unsigned int randomSeed,
        unsigned int numPixels,
        Scaleform::Render::Color fill)
{
  unsigned int v8; // esi
  unsigned int result; // [esp+4h] [ebp-38h] BYREF
  Scaleform::Render::DICommand_PixelDissolve cmd; // [esp+8h] [ebp-34h] BYREF

  Scaleform::Render::DICommand_PixelDissolve::DICommand_PixelDissolve(
    &cmd,
    this,
    source,
    sourceRect,
    destPoint,
    randomSeed,
    numPixels,
    fill,
    &result);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_PixelDissolve>(this, &cmd);
  v8 = result;
  if ( cmd.pSource.pObject )
    cmd.pSource.pObject->Release(cmd.pSource.pObject);
  cmd.__vftable = (Scaleform::Render::DICommand_PixelDissolve_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( cmd.pImage.pObject )
    cmd.pImage.pObject->Release(cmd.pImage.pObject);
  return v8;
}
