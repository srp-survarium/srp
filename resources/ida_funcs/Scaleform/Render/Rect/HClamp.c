Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::Rect<float>::HClamp(
        Scaleform::Render::Rect<float> *this,
        float left,
        float right)
{
  Scaleform::Render::Rect<float> *result; // eax

  if ( this->x1 < (double)left )
    this->x1 = left;
  result = this;
  if ( this->x2 > (double)right )
    this->x2 = right;
  return result;
}
