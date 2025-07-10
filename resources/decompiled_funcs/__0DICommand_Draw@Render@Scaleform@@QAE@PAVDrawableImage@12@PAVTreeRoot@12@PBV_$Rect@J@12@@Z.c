void __thiscall Scaleform::Render::DICommand_Draw::DICommand_Draw(
        Scaleform::Render::DICommand_Draw *this,
        Scaleform::Render::DrawableImage *image,
        Scaleform::Render::TreeRoot *root,
        const Scaleform::Render::Rect<long> *clipRect)
{
  int y2; // ecx
  int x2; // edx
  int y1; // edi

  this->__vftable = (Scaleform::Render::DICommand_Draw_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( image )
    image->AddRef(image);
  this->pImage.pObject = image;
  this->pRoot = root;
  this->__vftable = (Scaleform::Render::DICommand_Draw_vtbl *)&Scaleform::Render::DICommand_Draw::`vftable';
  this->ClipRect.x1 = 0;
  this->ClipRect.y1 = 0;
  this->ClipRect.x2 = 0;
  this->ClipRect.y2 = 0;
  this->HasClipRect = clipRect != 0;
  if ( clipRect )
  {
    y2 = clipRect->y2;
    x2 = clipRect->x2;
    y1 = clipRect->y1;
    this->ClipRect.x1 = clipRect->x1;
    this->ClipRect.y1 = y1;
    this->ClipRect.x2 = x2;
    this->ClipRect.y2 = y2;
  }
}
