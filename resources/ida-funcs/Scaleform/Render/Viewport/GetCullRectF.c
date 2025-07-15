char __thiscall Scaleform::Render::Viewport::GetCullRectF(
        Scaleform::Render::Viewport *this,
        Scaleform::Render::Rect<float> *prect,
        bool orient)
{
  char result; // al
  int Top; // eax
  int Left; // ecx
  float v7; // [esp+4h] [ebp-1Ch]
  float v8; // [esp+8h] [ebp-18h]
  float v9; // [esp+Ch] [ebp-14h]
  Scaleform::Render::Rect<int> clipRect; // [esp+10h] [ebp-10h] BYREF

  memset(&clipRect, 0, sizeof(clipRect));
  result = Scaleform::Render::Viewport::GetClippedRect<int>(this, &clipRect, orient);
  if ( result )
  {
    Top = this->Top;
    Left = this->Left;
    v7 = (float)(clipRect.y1 - Top);
    v8 = (float)(clipRect.x2 - Left);
    v9 = (float)(clipRect.y2 - Top);
    prect->x1 = (float)(clipRect.x1 - Left);
    prect->y1 = v7;
    prect->x2 = v8;
    prect->y2 = v9;
    return 1;
  }
  return result;
}
