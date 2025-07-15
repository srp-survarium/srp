BOOL __thiscall Scaleform::Render::CacheAsBitmapFilter::CanCacheAcrossTransform(
        Scaleform::Render::CacheAsBitmapFilter *this,
        bool __formal,
        bool deltaRot,
        bool deltaScale)
{
  return !deltaScale;
}
