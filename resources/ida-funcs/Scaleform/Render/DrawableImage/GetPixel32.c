Scaleform::Render::Color *__thiscall Scaleform::Render::DrawableImage::GetPixel32(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Color *result,
        int x,
        int y)
{
  Scaleform::Render::Color *v5; // eax
  Scaleform::Render::DICommand_GetPixel32 cmd; // [esp+4h] [ebp-14h] BYREF

  if ( x >= this->ISize.Width || y >= this->ISize.Height || x < 0 || y < 0 )
  {
    v5 = result;
    result->Raw = 0;
  }
  else
  {
    Scaleform::Render::DICommand_GetPixel32::DICommand_GetPixel32(&cmd, this, x, y, (Scaleform::Render::Color *)&x);
    Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_GetPixel32>(this, &cmd);
    result->Raw = x;
    cmd.__vftable = (Scaleform::Render::DICommand_GetPixel32_vtbl *)&Scaleform::Render::DICommand::`vftable';
    if ( cmd.pImage.pObject )
      cmd.pImage.pObject->Release(cmd.pImage.pObject);
    return result;
  }
  return v5;
}
