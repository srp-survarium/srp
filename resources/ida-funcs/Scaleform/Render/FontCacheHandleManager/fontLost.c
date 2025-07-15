void __thiscall Scaleform::Render::FontCacheHandleManager::fontLost(
        Scaleform::Render::FontCacheHandleManager *this,
        Scaleform::Render::FontCacheHandleRef *href)
{
  Scaleform::Lock *p_FontLock; // esi
  Scaleform::Render::FontCacheHandle *volatile pFontHandle; // eax

  p_FontLock = &this->FontLock;
  EnterCriticalSection(&this->FontLock.cs);
  pFontHandle = href->pFontHandle;
  if ( pFontHandle )
  {
    pFontHandle->pPrev->pNext = pFontHandle->pNext;
    pFontHandle->pNext->Scaleform::ListNode<Scaleform::Render::FontCacheHandle>::$23F765397AA6D94B0E32A5066342EE47::pPrev = pFontHandle->pPrev;
    pFontHandle->pPrev = this->Fonts[1].Root.pPrev;
    pFontHandle->pNext = (Scaleform::Render::FontCacheHandle *)&this->Fonts[1];
    this->Fonts[1].Root.pPrev->pNext = pFontHandle;
    this->Fonts[1].Root.pPrev = pFontHandle;
    pFontHandle->pFont = 0;
  }
  LeaveCriticalSection(&p_FontLock->cs);
}
