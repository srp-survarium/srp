void __thiscall Scaleform::Render::FontCacheHandleManager::DestroyAllFonts(
        Scaleform::Render::FontCacheHandleManager *this)
{
  Scaleform::Lock *p_FontLock; // edi

  p_FontLock = &this->FontLock;
  EnterCriticalSection(&this->FontLock.cs);
  Scaleform::Render::FontCacheHandleManager::destroyFontList_NTS(this, Font_KillList);
  Scaleform::Render::FontCacheHandleManager::destroyFontList_NTS(this, Font_LiveList);
  LeaveCriticalSection(&p_FontLock->cs);
}
