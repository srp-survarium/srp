void __thiscall Scaleform::Render::DICommand_CopyPixels::DICommand_CopyPixels(
        Scaleform::Render::DICommand_CopyPixels *this,
        Scaleform::Render::DrawableImage *image,
        Scaleform::Render::DrawableImage *source,
        const Scaleform::Render::Rect<long> *sourceRect,
        const Scaleform::Render::Point<long> *destPoint,
        Scaleform::Render::DrawableImage *alphaSource,
        const Scaleform::Render::Point<long> *alphaPoint,
        bool mergeAlpha)
{
  const Scaleform::Render::Point<long> *v9; // eax
  int y; // ecx
  _DWORD v11[2]; // [esp+8h] [ebp-8h] BYREF

  Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(this, image, source, sourceRect, destPoint);
  this->__vftable = (Scaleform::Render::DICommand_CopyPixels_vtbl *)&Scaleform::Render::DICommand_CopyPixels::`vftable';
  if ( alphaSource )
    alphaSource->AddRef(alphaSource);
  v9 = alphaPoint;
  this->pAlphaSource.pObject = alphaSource;
  if ( !alphaPoint )
  {
    v11[1] = 0;
    v11[0] = 0;
    v9 = (const Scaleform::Render::Point<long> *)v11;
  }
  y = v9->y;
  this->AlphaPoint.x = v9->x;
  this->AlphaPoint.y = y;
  this->MergeAlpha = mergeAlpha;
}
