Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::Rect<float>::VClamp(
        Scaleform::Render::Rect<float> *this,
        float top,
        float bottom)
{
  Scaleform::Render::Rect<float> *result; // eax

  if ( this->y1 < (double)top )
    this->y1 = top;
  result = this;
  if ( this->y2 > (double)bottom )
    this->y2 = bottom;
  return result;
}
