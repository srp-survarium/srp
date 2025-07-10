void __thiscall Scaleform::Render::Image::TextureLost(
        Scaleform::Render::Image *this,
        Scaleform::Render::Image::TextureLossReason reason)
{
  if ( reason == TLR_ManagerDestroyed )
    Scaleform::Render::Image::releaseTexture(this);
}
