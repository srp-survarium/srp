Scaleform::Render::Rect<unsigned long> *__thiscall Scaleform::Render::ImageBase::GetRect(
        Scaleform::Render::Image *this,
        Scaleform::Render::Rect<unsigned long> *result)
{
  Scaleform::Render::Size<unsigned long> *v2; // ecx
  Scaleform::Render::Rect<unsigned long> *v3; // eax
  unsigned int Width; // edx
  unsigned int Height; // ecx
  _BYTE v6[8]; // [esp+0h] [ebp-8h] BYREF

  v2 = this->GetSize(this, v6);
  v3 = result;
  Width = v2->Width;
  Height = v2->Height;
  result->x1 = 0;
  result->y1 = 0;
  result->x2 = Width;
  result->y2 = Height;
  return v3;
}
