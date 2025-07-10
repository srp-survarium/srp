const Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::Rect<float>::operator+=(
        Scaleform::Render::Rect<float> *this,
        const Scaleform::Render::Point<float> *pt)
{
  const Scaleform::Render::Rect<float> *result; // eax
  double x; // st7
  float y; // [esp+0h] [ebp-4h]

  result = this;
  y = pt->y;
  x = pt->x;
  this->x1 = this->x1 + x;
  this->x2 = x + this->x2;
  this->y1 = this->y1 + y;
  this->y2 = y + this->y2;
  return result;
}
