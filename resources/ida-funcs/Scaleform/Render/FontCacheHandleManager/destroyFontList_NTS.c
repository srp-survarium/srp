void __thiscall Scaleform::Render::FontCacheHandleManager::destroyFontList_NTS(
        Scaleform::Render::FontCacheHandleManager *this,
        Scaleform::Render::FontCacheHandleManager::FontListType type)
{
  Scaleform::Render::FontCacheHandle *pNext; // esi
  Scaleform::List<Scaleform::Render::FontCacheHandle,Scaleform::Render::FontCacheHandle> *v3; // edi
  Scaleform::Render::FontCacheHandle *v4; // ebp
  Scaleform::RefCountVImpl *v5; // eax
  Scaleform::Render::GlyphCache *pCache; // ecx
  char v7; // [esp+Bh] [ebp-5h]
  Scaleform::Render::FontCacheHandleManager *v8; // [esp+Ch] [ebp-4h]

  pNext = this->Fonts[type].Root.pNext;
  v3 = &this->Fonts[type];
  v8 = this;
  if ( pNext != (Scaleform::Render::FontCacheHandle *)v3 )
  {
    v7 = 0;
    while ( 1 )
    {
      v4 = pNext->pNext;
      if ( type == Font_KillList )
      {
        pCache = this->pCache;
        if ( pCache )
        {
          Scaleform::Render::GlyphCache::CleanUpFont(pCache, pNext);
          v7 = 1;
        }
      }
      else
      {
        pNext->pFont->hRef.pFontHandle = 0;
        v5 = (Scaleform::RefCountVImpl *)InterlockedExchange((volatile LONG *)&pNext->pFont->hRef, 0);
        if ( v5 )
          Scaleform::RefCountImpl::Release(v5);
        pNext->pFont = 0;
      }
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pNext);
      pNext = v4;
      if ( v4 == (Scaleform::Render::FontCacheHandle *)v3 )
        break;
      this = v8;
    }
    v3->Root.pPrev = (Scaleform::Render::FontCacheHandle *)v3;
    v3->Root.pNext = (Scaleform::Render::FontCacheHandle *)v3;
    if ( v7 )
      Scaleform::Render::GlyphCache::MergeCacheSlots(v8->pCache);
  }
}
