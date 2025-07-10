Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::Rect<float>::operator-=(
        Scaleform::Render::Rect<float> *this,
        const Scaleform::Render::Point<float> *pt)
{
  Scaleform::Render::Rect<float> *result; // eax
  float v3; // [esp+0h] [ebp-8h]
  float v4; // [esp+4h] [ebp-4h]

  result = this;
  v3 = -pt->x;
  v4 = -pt->y;
  this->x1 = this->x1 + v3;
  this->x2 = v3 + this->x2;
  this->y1 = this->y1 + v4;
  this->y2 = v4 + this->y2;
  return result;
}
