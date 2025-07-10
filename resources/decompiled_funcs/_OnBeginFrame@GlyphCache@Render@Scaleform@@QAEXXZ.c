void __thiscall Scaleform::Render::GlyphCache::OnBeginFrame(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::FontCacheHandleManager *pObject; // ecx

  if ( this->pFontHandleManager.pObject )
    goto LABEL_5;
  if ( this->pRenderer && this->pRenderer->IsInitialized(this->pRenderer) )
  {
    Scaleform::Render::GlyphCache::initialize(this);
LABEL_5:
    pObject = this->pFontHandleManager.pObject;
    if ( pObject )
      Scaleform::Render::FontCacheHandleManager::ProcessKillList(pObject);
  }
}
