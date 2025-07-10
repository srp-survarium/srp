void __thiscall Scaleform::Render::DrawableImage::CopyPixels(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *source,
        const Scaleform::Render::Rect<long> *sourceRect,
        const Scaleform::Render::Point<long> *destPoint,
        Scaleform::Render::DrawableImage *alphaSource,
        const Scaleform::Render::Point<long> *alphaPoint,
        bool mergeAlpha)
{
  Scaleform::Render::DICommand_CopyPixels *v8; // eax
  Scaleform::Render::DICommand_CopyPixels v9; // [esp+4h] [ebp-34h] BYREF

  Scaleform::Render::DICommand_CopyPixels::DICommand_CopyPixels(
    &v9,
    this,
    source,
    sourceRect,
    destPoint,
    alphaSource,
    alphaPoint,
    mergeAlpha);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_CopyPixels>(this, v8);
  if ( v9.pAlphaSource.pObject )
    v9.pAlphaSource.pObject->Release(v9.pAlphaSource.pObject);
  if ( v9.pSource.pObject )
    v9.pSource.pObject->Release(v9.pSource.pObject);
  v9.__vftable = (Scaleform::Render::DICommand_CopyPixels_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( v9.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DICommand_CopyPixels_vtbl *))v9.pImage.pObject->Release)(v9.__vftable);
}
