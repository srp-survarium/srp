void __thiscall Scaleform::Render::DrawableImage::FloodFill(
        Scaleform::Render::DrawableImage *this,
        const Scaleform::Render::Point<long> *pt,
        Scaleform::Render::Color color)
{
  int y; // edx
  Scaleform::Render::DICommand_FloodFill cmd; // [esp+8h] [ebp-14h] BYREF

  cmd.__vftable = (Scaleform::Render::DICommand_FloodFill_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( this )
    this->AddRef(this);
  y = pt->y;
  cmd.Pt.x = pt->x;
  cmd.pImage.pObject = this;
  cmd.__vftable = (Scaleform::Render::DICommand_FloodFill_vtbl *)&Scaleform::Render::DICommand_FloodFill::`vftable';
  cmd.Pt.y = y;
  cmd.FillColor = color;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_FloodFill>(this, &cmd);
  cmd.__vftable = (Scaleform::Render::DICommand_FloodFill_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DICommand_FloodFill_vtbl *))cmd.pImage.pObject->Release)(cmd.__vftable);
}
