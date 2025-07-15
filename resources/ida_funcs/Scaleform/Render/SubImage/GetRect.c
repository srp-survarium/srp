Scaleform::Render::Rect<unsigned long> *__thiscall Scaleform::Render::SubImage::GetRect(
        Scaleform::Render::SubImage *this,
        Scaleform::Render::Rect<unsigned long> *result)
{
  Scaleform::Render::Rect<unsigned long> *v2; // eax
  unsigned int x2; // edx
  unsigned int y2; // ecx

  v2 = result;
  result->x1 = this->SubRect.x1;
  result->y1 = this->SubRect.y1;
  x2 = this->SubRect.x2;
  y2 = this->SubRect.y2;
  result->x2 = x2;
  result->y2 = y2;
  return v2;
}
