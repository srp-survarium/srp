char __thiscall Scaleform::Render::DrawableImage::SetPixels(
        Scaleform::Render::DrawableImage *this,
        const Scaleform::Render::Rect<long> *inputRect,
        Scaleform::Render::DIPixelProvider *provider)
{
  unsigned int Height; // eax
  unsigned int Width; // ecx
  char result; // al
  char v7; // bl
  Scaleform::Render::Rect<long> v8; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::Render::DICommand_SetPixels cmd; // [esp+1Ch] [ebp-20h] BYREF

  Height = this->ISize.Height;
  Width = this->ISize.Width;
  cmd.DestRect.y1 = Height;
  cmd.DestRect.x1 = Width;
  memset(&v8, 0, sizeof(v8));
  cmd.__vftable = 0;
  cmd.pImage.pObject = 0;
  result = Scaleform::Render::Rect<long>::IntersectRect((Scaleform::Render::Rect<long> *)&cmd, &v8, inputRect);
  if ( result )
  {
    Scaleform::Render::DICommand_SetPixels::DICommand_SetPixels(&cmd, this, v8, provider, (bool *)&inputRect);
    Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_SetPixels>(this, &cmd);
    v7 = (char)inputRect;
    cmd.__vftable = (Scaleform::Render::DICommand_SetPixels_vtbl *)&Scaleform::Render::DICommand::`vftable';
    if ( cmd.pImage.pObject )
      cmd.pImage.pObject->Release(cmd.pImage.pObject);
    return v7;
  }
  return result;
}
