BOOL __thiscall Scaleform::Render::Rect<float>::IsNormal(Scaleform::Render::Rect<float> *this)
{
  return this->x1 <= (double)this->x2 && this->y1 <= (double)this->y2;
}
