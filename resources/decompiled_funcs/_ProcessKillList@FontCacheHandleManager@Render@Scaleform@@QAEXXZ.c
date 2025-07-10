void __thiscall Scaleform::Render::FontCacheHandleManager::ProcessKillList(
        Scaleform::Render::FontCacheHandleManager *this)
{
  Scaleform::Lock *p_FontLock; // edi

  p_FontLock = &this->FontLock;
  EnterCriticalSection(&this->FontLock.cs);
  Scaleform::Render::FontCacheHandleManager::destroyFontList_NTS(this, Font_KillList);
  LeaveCriticalSection(&p_FontLock->cs);
}
