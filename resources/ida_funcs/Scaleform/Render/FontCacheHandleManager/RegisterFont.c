Scaleform::Render::FontCacheHandle *__thiscall Scaleform::Render::FontCacheHandleManager::RegisterFont(
        Scaleform::Render::FontCacheHandleManager *this,
        Scaleform::Render::Font *font)
{
  Scaleform::Render::FontCacheHandle *v3; // eax
  Scaleform::Render::FontCacheHandle *volatile pFontHandle; // eax
  Scaleform::Lock *p_FontLock; // [esp-4h] [ebp-14h]

  if ( !font->hRef.pManager.Value )
  {
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)this);
    InterlockedExchange((volatile LONG *)&font->hRef, (LONG)this);
  }
  if ( !font->hRef.pFontHandle )
  {
    EnterCriticalSection(&this->FontLock.cs);
    v3 = (Scaleform::Render::FontCacheHandle *)this->pRenderHeap->Alloc(this->pRenderHeap, 16, 0);
    if ( v3 )
    {
      v3->pManager = this;
      v3->pFont = font;
    }
    else
    {
      v3 = 0;
    }
    font->hRef.pFontHandle = v3;
    p_FontLock = &this->FontLock;
    if ( !font->hRef.pFontHandle )
    {
      LeaveCriticalSection(&p_FontLock->cs);
      return 0;
    }
    pFontHandle = font->hRef.pFontHandle;
    pFontHandle->pPrev = this->Fonts[0].Root.pPrev;
    pFontHandle->pNext = (Scaleform::Render::FontCacheHandle *)this->Fonts;
    this->Fonts[0].Root.pPrev->pNext = pFontHandle;
    this->Fonts[0].Root.pPrev = pFontHandle;
    LeaveCriticalSection(&p_FontLock->cs);
  }
  return font->hRef.pFontHandle;
}
