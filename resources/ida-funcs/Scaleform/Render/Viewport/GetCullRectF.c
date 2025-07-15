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
  Scaleform::Render::Rect<int> v10; // [esp+10h] [ebp-10h] BYREF

  memset(&v10, 0, sizeof(v10));
  result = Scaleform::Render::Viewport::GetClippedRect<int>(this, &v10, orient);
  if ( result )
  {
    Top = this->Top;
    Left = this->Left;
    v7 = (float)(v10.y1 - Top);
    v8 = (float)(v10.x2 - Left);
    v9 = (float)(v10.y2 - Top);
    prect->x1 = (float)(v10.x1 - Left);
    prect->y1 = v7;
    prect->x2 = v8;
    prect->y2 = v9;
    return 1;
  }
  return result;
}
