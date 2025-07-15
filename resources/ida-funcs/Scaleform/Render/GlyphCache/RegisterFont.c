Scaleform::Render::FontCacheHandle *__thiscall Scaleform::Render::GlyphCache::RegisterFont(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::Font *font)
{
  Scaleform::Render::FontCacheHandleManager *pObject; // ecx

  if ( !this->pFontHandleManager.pObject )
  {
    if ( !this->pRenderer || !this->pRenderer->IsInitialized(this->pRenderer) )
      return 0;
    Scaleform::Render::GlyphCache::initialize(this);
  }
  pObject = this->pFontHandleManager.pObject;
  if ( pObject )
    return Scaleform::Render::FontCacheHandleManager::RegisterFont(pObject, font);
  return 0;
}
