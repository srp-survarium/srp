BOOL __thiscall Scaleform::Render::Rect<float>::IsNull(Scaleform::Render::Rect<float> *this)
{
  return this->x1 == this->x2 && this->y1 == this->y2;
}
