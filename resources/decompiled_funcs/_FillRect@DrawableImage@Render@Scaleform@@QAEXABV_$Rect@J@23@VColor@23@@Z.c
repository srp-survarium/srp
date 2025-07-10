void __thiscall Scaleform::Render::DrawableImage::FillRect(
        Scaleform::Render::DrawableImage *this,
        const Scaleform::Render::Rect<long> *rect,
        Scaleform::Render::Color color)
{
  int y1; // edx
  int x2; // ecx
  int y2; // edx
  Scaleform::Render::DICommand_FillRect cmd; // [esp+8h] [ebp-1Ch] BYREF

  cmd.__vftable = (Scaleform::Render::DICommand_FillRect_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( this )
    this->AddRef(this);
  y1 = rect->y1;
  cmd.ApplyRect.x1 = rect->x1;
  x2 = rect->x2;
  cmd.ApplyRect.y1 = y1;
  y2 = rect->y2;
  cmd.ApplyRect.x2 = x2;
  cmd.pImage.pObject = this;
  cmd.__vftable = (Scaleform::Render::DICommand_FillRect_vtbl *)&Scaleform::Render::DICommand_FillRect::`vftable';
  cmd.ApplyRect.y2 = y2;
  cmd.FillColor = color;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_FillRect>(this, &cmd);
  cmd.__vftable = (Scaleform::Render::DICommand_FillRect_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DICommand_FillRect_vtbl *))cmd.pImage.pObject->Release)(cmd.__vftable);
}
