Scaleform::Render::Size<unsigned long> *__thiscall Scaleform::Render::DrawableImage::GetSize(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Size<unsigned long> *result)
{
  unsigned int Width; // edx
  Scaleform::Render::Size<unsigned long> *v3; // eax
  unsigned int Height; // ecx

  Width = this->ISize.Width;
  v3 = result;
  Height = this->ISize.Height;
  result->Width = Width;
  result->Height = Height;
  return v3;
}
