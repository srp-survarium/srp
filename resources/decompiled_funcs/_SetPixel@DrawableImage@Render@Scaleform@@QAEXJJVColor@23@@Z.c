void __thiscall Scaleform::Render::DrawableImage::SetPixel(
        Scaleform::Render::DrawableImage *this,
        int x,
        int y,
        Scaleform::Render::Color c)
{
  signed int v5; // eax
  signed int v6; // ecx
  Scaleform::Render::DICommand_SetPixel32 cmd; // [esp+10h] [ebp-18h] BYREF

  v5 = this->ISize.Width - 1;
  v6 = this->ISize.Height - 1;
  if ( x <= v5 && x >= 0 && y <= v6 && y >= 0 )
  {
    this->AddRef(this);
    cmd.pImage.pObject = this;
    cmd.__vftable = (Scaleform::Render::DICommand_SetPixel32_vtbl *)&Scaleform::Render::DICommand_SetPixel32::`vftable';
    cmd.X = x;
    cmd.Y = y;
    cmd.Fill = c;
    cmd.OverwriteAlpha = 0;
    Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_SetPixel32>(this, &cmd);
    cmd.__vftable = (Scaleform::Render::DICommand_SetPixel32_vtbl *)&Scaleform::Render::DICommand::`vftable';
    if ( cmd.pImage.pObject )
      cmd.pImage.pObject->Release(cmd.pImage.pObject);
  }
}
