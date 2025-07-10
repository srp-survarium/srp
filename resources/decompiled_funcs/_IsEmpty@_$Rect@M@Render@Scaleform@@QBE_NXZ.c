BOOL __thiscall Scaleform::Render::Rect<float>::IsEmpty(Scaleform::Render::Rect<float> *this)
{
  return this->x2 <= (double)this->x1 || this->y2 <= (double)this->y1;
}
