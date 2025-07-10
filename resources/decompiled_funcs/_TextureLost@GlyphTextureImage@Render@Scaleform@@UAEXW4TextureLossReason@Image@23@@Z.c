void __thiscall Scaleform::Render::GlyphTextureImage::TextureLost(
        Scaleform::Render::GlyphTextureImage *this,
        Scaleform::Render::Image::TextureLossReason reason)
{
  Scaleform::Render::Image::releaseTexture(this);
  Scaleform::Render::GlyphCache::TextureLost(this->pCache, this->TextureId, reason);
}
