void __thiscall Scaleform::Render::DrawableImage::Merge(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *source,
        const Scaleform::Render::Rect<long> *sourceRect,
        const Scaleform::Render::Point<long> *destPoint,
        unsigned int redMult,
        unsigned int greenMult,
        unsigned int blueMult,
        unsigned int alphaMult)
{
  Scaleform::Render::DICommand_Merge v9; // [esp+4h] [ebp-34h] BYREF

  Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(&v9, this, source, sourceRect, destPoint);
  v9.GreenMultiplier = greenMult;
  v9.RedMultiplier = redMult;
  v9.__vftable = (Scaleform::Render::DICommand_Merge_vtbl *)&Scaleform::Render::DICommand_Merge::`vftable';
  v9.BlueMultiplier = blueMult;
  v9.AlphaMultiplier = alphaMult;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Merge>(this, &v9);
  if ( v9.pSource.pObject )
    v9.pSource.pObject->Release(v9.pSource.pObject);
  v9.__vftable = (Scaleform::Render::DICommand_Merge_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( v9.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DICommand_Merge_vtbl *))v9.pImage.pObject->Release)(v9.__vftable);
}
