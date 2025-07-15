void __thiscall Scaleform::Render::GlyphTextureImage::TextureLost(
        Scaleform::Render::GlyphTextureImage *this,
        unsigned int reason)
{
  Scaleform::Render::Image::releaseTexture(this);
  Scaleform::Render::GlyphCache::TextureLost(this->pCache, this->TextureId, reason);
}
