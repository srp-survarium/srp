Scaleform::Render::TextMeshProvider *__thiscall Scaleform::Render::TreeCacheText::GetMeshProvider(
        Scaleform::Render::TreeCacheText *this)
{
  if ( (this->TMProvider.Flags & 0x20) != 0 )
    return &this->TMProvider;
  else
    return 0;
}
