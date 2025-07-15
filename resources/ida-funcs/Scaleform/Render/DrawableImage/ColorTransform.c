void __thiscall Scaleform::Render::DrawableImage::ColorTransform(
        Scaleform::Render::DrawableImage *this,
        const Scaleform::Render::Rect<long> *rect,
        const Scaleform::Render::Cxform *cxform)
{
  int y1; // edx
  Scaleform::Render::Point<long> dp; // [esp+18h] [ebp-58h] BYREF
  Scaleform::Render::DICommand_ColorTransform v6; // [esp+20h] [ebp-50h] BYREF

  y1 = rect->y1;
  dp.x = rect->x1;
  dp.y = y1;
  Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(&v6, this, this, rect, &dp);
  v6.__vftable = (Scaleform::Render::DICommand_ColorTransform_vtbl *)&Scaleform::Render::DICommand_ColorTransform::`vftable';
  qmemcpy(&v6.Cx, cxform, sizeof(v6.Cx));
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_ColorTransform>(this, &v6);
  if ( v6.pSource.pObject )
    v6.pSource.pObject->Release(v6.pSource.pObject);
  v6.__vftable = (Scaleform::Render::DICommand_ColorTransform_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( v6.pImage.pObject )
    v6.pImage.pObject->Release(v6.pImage.pObject);
}
