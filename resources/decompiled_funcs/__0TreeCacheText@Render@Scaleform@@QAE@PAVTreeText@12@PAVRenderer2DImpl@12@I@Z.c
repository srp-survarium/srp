void __thiscall Scaleform::Render::TreeCacheText::TreeCacheText(
        Scaleform::Render::TreeCacheText *this,
        Scaleform::Render::TreeText *node,
        Scaleform::Render::Renderer2DImpl *prenderer2D,
        unsigned __int16 flags)
{
  const Scaleform::Render::SortKey *v5; // eax
  Scaleform::Render::Renderer2DImpl *v6; // eax
  Scaleform::Render::SortKey v7; // [esp+4h] [ebp-8h] BYREF

  Scaleform::Render::SortKey::SortKey(&v7, SortKeyText, (flags & 0x200) != 0);
  Scaleform::Render::TreeCacheMeshBase::TreeCacheMeshBase(this, node, v5, prenderer2D, flags);
  v7.pImpl->Release(v7.pImpl, v7.Data);
  v6 = this->pRenderer2D;
  this->__vftable = (Scaleform::Render::TreeCacheText_vtbl *)&Scaleform::Render::TreeCacheText::`vftable';
  this->pNextNoBatch = 0;
  Scaleform::Render::TextMeshProvider::TextMeshProvider(&this->TMProvider, v6->pGlyphCache.pObject);
}
