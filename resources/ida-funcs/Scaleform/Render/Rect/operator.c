const Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::Rect<float>::operator=(
        Scaleform::Render::Rect<float> *this,
        const Scaleform::Render::Rect<float> *r)
{
  const Scaleform::Render::Rect<float> *result; // eax
  float x2; // [esp+0h] [ebp-8h]
  float y2; // [esp+4h] [ebp-4h]
  float y1; // [esp+Ch] [ebp+4h]

  result = this;
  y1 = r->y1;
  x2 = r->x2;
  y2 = r->y2;
  result->x1 = r->x1;
  result->y1 = y1;
  result->x2 = x2;
  result->y2 = y2;
  return result;
}


BOOL __thiscall Scaleform::Render::Rect<double>::operator==(
        Scaleform::Render::Rect<double> *this,
        const Scaleform::Render::Rect<double> *r)
{
  return r->x1 == this->x1 && r->x2 == this->x2 && r->y1 == this->y1 && r->y2 == this->y2;
}


BOOL __thiscall Scaleform::Render::Rect<float>::operator!=(
        Scaleform::Render::Rect<float> *this,
        const Scaleform::Render::Rect<float> *r)
{
  return r->x1 != this->x1 || r->x2 != this->x2 || r->y1 != this->y1 || r->y2 != this->y2;
}


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
