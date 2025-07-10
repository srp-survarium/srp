void __thiscall Scaleform::Render::DrawableImage::Histogram(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Rect<long> *rect,
        unsigned int (*colors)[256])
{
  int x1; // edi
  int y1; // ebx
  int x2; // ebp
  Scaleform::Render::Size<unsigned long> *v7; // eax
  Scaleform::Render::Rect<long> hrect; // [esp+10h] [ebp-2Ch] BYREF
  Scaleform::Render::DICommand_Histogram cmd; // [esp+20h] [ebp-1Ch] BYREF

  memset((int)colors, 0, 0x1000u);
  if ( rect )
  {
    x1 = rect->x1;
    y1 = rect->y1;
    x2 = rect->x2;
    hrect.y2 = rect->y2;
  }
  else
  {
    v7 = this->GetSize(this, &hrect);
    x2 = v7->Width;
    x1 = 0;
    y1 = 0;
    hrect.y2 = v7->Height;
  }
  cmd.__vftable = (Scaleform::Render::DICommand_Histogram_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( this )
    this->AddRef(this);
  cmd.SourceRect.y2 = hrect.y2;
  cmd.pImage.pObject = this;
  cmd.__vftable = (Scaleform::Render::DICommand_Histogram_vtbl *)&Scaleform::Render::DICommand_Histogram::`vftable';
  cmd.SourceRect.x1 = x1;
  cmd.SourceRect.y1 = y1;
  cmd.SourceRect.x2 = x2;
  cmd.Result = (unsigned int *)colors;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Histogram>(this, &cmd);
  cmd.__vftable = (Scaleform::Render::DICommand_Histogram_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( cmd.pImage.pObject )
    cmd.pImage.pObject->Release(cmd.pImage.pObject);
}
