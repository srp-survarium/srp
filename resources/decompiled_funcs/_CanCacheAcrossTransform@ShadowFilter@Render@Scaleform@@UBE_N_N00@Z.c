BOOL __thiscall Scaleform::Render::ShadowFilter::CanCacheAcrossTransform(
        Scaleform::Render::BevelFilter *this,
        bool deltaTrans,
        bool deltaRot,
        bool deltaScale)
{
  return !deltaRot && !deltaScale;
}
