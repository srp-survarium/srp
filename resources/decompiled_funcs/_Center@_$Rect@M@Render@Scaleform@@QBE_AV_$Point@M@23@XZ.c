Scaleform::Render::Point<float> *__thiscall Scaleform::Render::Rect<float>::Center(
        Scaleform::Render::Rect<float> *this,
        Scaleform::Render::Point<float> *result)
{
  Scaleform::Render::Point<float> *v2; // eax

  v2 = result;
  result->x = (this->x2 + this->x1) * 0.5;
  result->y = 0.5 * (this->y2 + this->y1);
  return v2;
}
