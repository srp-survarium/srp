char __thiscall Scaleform::Render::Viewport::GetClippedRect<int>(
        Scaleform::Render::Viewport *this,
        Scaleform::Render::Rect<int> *prect,
        bool orient)
{
  unsigned int v4; // eax
  int Height; // edx
  int Width; // edi
  int BufferHeight; // ecx
  int Left; // eax
  int Top; // ecx
  int ScissorTop; // ecx
  int v12; // edx
  int v13; // eax
  Scaleform::Render::Rect<int> r; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::Render::Rect<int> v15; // [esp+1Ch] [ebp-10h] BYREF

  if ( orient && ((v4 = this->Flags & 0x30, v4 == 16) || v4 == 48) )
  {
    Height = this->Height;
    Width = this->Width;
  }
  else
  {
    Width = this->Height;
    Height = this->Width;
  }
  BufferHeight = this->BufferHeight;
  r.x2 = this->BufferWidth;
  Left = this->Left;
  r.y2 = BufferHeight;
  Top = this->Top;
  v15.x1 = Left;
  v15.y1 = Top;
  v15.y2 = Width + Top;
  r.x1 = 0;
  r.y1 = 0;
  v15.x2 = Height + Left;
  if ( Scaleform::Render::Rect<int>::IntersectRect(&v15, prect, &r) )
  {
    if ( (this->Flags & 4) == 0 )
      return 1;
    ScissorTop = this->ScissorTop;
    v12 = this->ScissorLeft + this->ScissorWidth;
    v15.x1 = this->ScissorLeft;
    v13 = ScissorTop + this->ScissorHeight;
    v15.y1 = ScissorTop;
    v15.x2 = v12;
    v15.y2 = v13;
    if ( Scaleform::Render::Rect<int>::IntersectRect(prect, prect, &v15) )
      return 1;
  }
  prect->x1 = 0;
  prect->y1 = 0;
  prect->x2 = 0;
  prect->y2 = 0;
  return 0;
}
