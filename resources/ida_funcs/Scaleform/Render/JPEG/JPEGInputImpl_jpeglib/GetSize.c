Scaleform::Render::Size<unsigned long> *__thiscall Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::GetSize(
        Scaleform::Render::JPEG::JPEGInputImpl_jpeglib *this,
        Scaleform::Render::Size<unsigned long> *result)
{
  unsigned int output_width; // edx
  Scaleform::Render::Size<unsigned long> *v3; // eax
  unsigned int output_height; // ecx

  output_width = this->CInfo.output_width;
  v3 = result;
  output_height = this->CInfo.output_height;
  result->Width = output_width;
  result->Height = output_height;
  return v3;
}
