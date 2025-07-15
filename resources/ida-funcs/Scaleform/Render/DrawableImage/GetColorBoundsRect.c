Scaleform::Render::Rect<long> *__thiscall Scaleform::Render::DrawableImage::GetColorBoundsRect(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Rect<long> *result,
        unsigned int mask,
        unsigned int color,
        bool findColor)
{
  bool v6; // zf
  Scaleform::Render::DICommand_GetColorBoundsRect cmd; // [esp+8h] [ebp-18h] BYREF

  result->x1 = 0;
  result->y1 = 0;
  result->x2 = 0;
  result->y2 = 0;
  cmd.__vftable = (Scaleform::Render::DICommand_GetColorBoundsRect_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( this )
    this->AddRef(this);
  v6 = !this->Transparent;
  cmd.pImage.pObject = this;
  cmd.__vftable = (Scaleform::Render::DICommand_GetColorBoundsRect_vtbl *)&Scaleform::Render::DICommand_GetColorBoundsRect::`vftable';
  cmd.Mask = mask;
  cmd.SearchColor = color;
  cmd.FindColor = findColor;
  cmd.Result = result;
  if ( v6 )
    cmd.Mask = mask & 0xFFFFFF;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_GetColorBoundsRect>(this, &cmd);
  cmd.__vftable = (Scaleform::Render::DICommand_GetColorBoundsRect_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( cmd.pImage.pObject )
    cmd.pImage.pObject->Release(cmd.pImage.pObject);
  return result;
}
