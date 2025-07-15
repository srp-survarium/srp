char __thiscall Scaleform::Render::DrawableImage::GetPixels(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DIPixelProvider *provider,
        const Scaleform::Render::Rect<long> *sourceRect)
{
  int x2; // edx
  int y2; // ebx
  char v7; // bl
  Scaleform::Render::Rect<long> v8; // [esp-18h] [ebp-44h]
  Scaleform::Render::DICommand_GetPixels cmd; // [esp+Ch] [ebp-20h] BYREF

  x2 = sourceRect->x2;
  if ( (signed int)this->ISize.Width < x2 )
    return 0;
  y2 = sourceRect->y2;
  if ( (signed int)this->ISize.Height < y2 || sourceRect->x1 < 0 || sourceRect->y1 < 0 )
    return 0;
  *(_QWORD *)&v8.x1 = *(_QWORD *)&sourceRect->x1;
  *(_QWORD *)&v8.x2 = __PAIR64__(y2, x2);
  Scaleform::Render::DICommand_GetPixels::DICommand_GetPixels(&cmd, this, v8, provider, (bool *)&sourceRect);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_GetPixels>(this, &cmd);
  v7 = (char)sourceRect;
  cmd.__vftable = (Scaleform::Render::DICommand_GetPixels_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( cmd.pImage.pObject )
    cmd.pImage.pObject->Release(cmd.pImage.pObject);
  return v7;
}
