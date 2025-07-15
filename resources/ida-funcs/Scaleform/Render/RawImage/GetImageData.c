char __thiscall Scaleform::Render::RawImage::GetImageData(
        Scaleform::Render::RawImage *this,
        Scaleform::Render::ImageData *pdata)
{
  Scaleform::Render::ImageData::operator=(pdata, &this->Data);
  return 1;
}
