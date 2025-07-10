const Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::Rect<float>::operator=(
        Scaleform::Render::Rect<float> *this,
        const Scaleform::Render::Rect<float> *r)
{
  const Scaleform::Render::Rect<float> *result; // eax
  float x2; // [esp+0h] [ebp-8h]
  float y2; // [esp+4h] [ebp-4h]
  float ra; // [esp+Ch] [ebp+4h]

  result = this;
  ra = r->y1;
  x2 = r->x2;
  y2 = r->y2;
  result->x1 = r->x1;
  result->y1 = ra;
  result->x2 = x2;
  result->y2 = y2;
  return result;
}
