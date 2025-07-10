char __thiscall Scaleform::Render::RawImage::Map(
        Scaleform::Render::RawImage *this,
        Scaleform::Render::ImageData *pdata,
        unsigned int levelIndex,
        unsigned int levelCount)
{
  if ( !Scaleform::Render::ImageData::Initialize(pdata, &this->Data, levelIndex, levelCount) )
    return 0;
  this->Data.Flags |= 0x10u;
  return 1;
}
