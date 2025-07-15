void __thiscall Scaleform::Render::GlyphCache::cacheFullWarning(Scaleform::Render::GlyphCache *this)
{
  if ( this->RasterCacheWarning )
  {
    Scaleform::Render::GlyphCache::LogWarning(
      this,
      "Warning: Increase raster glyph cache capacity - see GlyphCacheParams");
    this->RasterCacheWarning = 0;
  }
}
