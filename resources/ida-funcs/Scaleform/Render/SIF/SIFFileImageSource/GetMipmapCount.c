unsigned int __thiscall Scaleform::Render::SIF::SIFFileImageSource::GetMipmapCount(
        Scaleform::Render::SIF::SIFFileImageSource *this)
{
  unsigned int result; // eax

  result = this->HeaderInfo.LevelCount;
  if ( !this->HeaderInfo.LevelCount )
    return 1;
  return result;
}
