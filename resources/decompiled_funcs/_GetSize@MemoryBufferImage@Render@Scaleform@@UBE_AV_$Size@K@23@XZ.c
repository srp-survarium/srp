Scaleform::Render::Size<unsigned long> *__thiscall Scaleform::Render::MemoryBufferImage::GetSize(
        Scaleform::Render::MemoryBufferImage *this,
        Scaleform::Render::Size<unsigned long> *result)
{
  unsigned int Width; // edx
  Scaleform::Render::Size<unsigned long> *v3; // eax
  unsigned int Height; // ecx

  Width = this->Size.Width;
  v3 = result;
  Height = this->Size.Height;
  result->Width = Width;
  result->Height = Height;
  return v3;
}
