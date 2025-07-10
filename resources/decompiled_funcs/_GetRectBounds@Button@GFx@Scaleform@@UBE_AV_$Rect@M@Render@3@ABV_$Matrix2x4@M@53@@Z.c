Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::Button::GetRectBounds(
        Scaleform::GFx::Button *this,
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Matrix2x4<float> *transform)
{
  int v3; // eax
  int v4; // eax
  Scaleform::ArrayLH<Scaleform::GFx::Button::CharToRec,2,Scaleform::ArrayDefaultPolicy> *p_Characters; // ebx
  int v6; // edi
  Scaleform::Render::Rect<float> *RectBounds; // eax
  char v9; // [esp+61h] [ebp-25h]
  Scaleform::GFx::Button *v10; // [esp+62h] [ebp-24h]
  Scaleform::Render::Rect<float> left; // [esp+66h] [ebp-20h]
  Scaleform::Render::Rect<float> v12; // [esp+76h] [ebp-10h] BYREF

  result->x1 = 0.0;
  result->y1 = 0.0;
  result->x2 = 0.0;
  v10 = this;
  result->y2 = 0.0;
  v9 = 0;
  if ( this->MouseState )
  {
    if ( this->MouseState == MouseMove )
      v3 = 2;
    else
      v3 = this->MouseState == MouseDown;
  }
  else
  {
    v3 = 0;
  }
  v4 = v3;
  p_Characters = &this->States[v4].Characters;
  v6 = 0;
  if ( this->States[v4].Characters.Data.Size )
  {
    while ( 1 )
    {
      RectBounds = Scaleform::GFx::Button::GetRectBounds(
                     this,
                     &v12,
                     transform,
                     p_Characters->Data.Data[v6].Char.pObject);
      left.x1 = RectBounds->x1;
      left.y1 = RectBounds->y1;
      left.x2 = RectBounds->x2;
      left.y2 = RectBounds->y2;
      if ( left.x1 != left.x2 || left.y1 != left.y2 )
      {
        if ( v9 )
        {
          Scaleform::Render::Rect<float>::Union(result, left.x1, left.y1, left.x2, left.y2);
        }
        else
        {
          v9 = 1;
          *result = left;
        }
      }
      if ( ++v6 >= p_Characters->Data.Size )
        break;
      this = v10;
    }
  }
  return result;
}
