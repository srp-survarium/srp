Scaleform::Render::Size<unsigned long> *__thiscall Scaleform::Render::PNG::LibPNGInput::GetSize(
        Scaleform::Render::PNG::LibPNGInput *this,
        Scaleform::Render::Size<unsigned long> *result)
{
  unsigned int width; // edx
  Scaleform::Render::Size<unsigned long> *v3; // eax
  unsigned int height; // ecx

  width = this->Context.width;
  v3 = result;
  height = this->Context.height;
  result->Width = width;
  result->Height = height;
  return v3;
}
