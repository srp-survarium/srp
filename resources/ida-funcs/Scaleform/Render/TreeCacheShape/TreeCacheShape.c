void __thiscall Scaleform::Render::TreeCacheShape::TreeCacheShape(
        Scaleform::Render::TreeCacheShape *this,
        Scaleform::Render::TreeShape *pnode,
        Scaleform::Render::Renderer2DImpl *prenderer2D,
        unsigned __int16 flags)
{
  Scaleform::Render::TreeCacheNode *p_SortParentBounds; // ecx

  Scaleform::Render::TreeCacheNode::TreeCacheNode(this, pnode, prenderer2D, flags);
  this->__vftable = (Scaleform::Render::TreeCacheShape_vtbl *)&Scaleform::Render::TreeCacheContainer::`vftable';
  if ( this == (Scaleform::Render::TreeCacheShape *)-80 )
    p_SortParentBounds = 0;
  else
    p_SortParentBounds = (Scaleform::Render::TreeCacheNode *)&this->SortParentBounds;
  this->Children.Root.Scaleform::Render::TreeCacheContainer::pPrev = p_SortParentBounds;
  this->Children.Root.pNext = p_SortParentBounds;
  this->CachedChildPattern.pFirst = 0;
  this->CachedChildPattern.pLast = 0;
  this->CachedChildPattern.Length = 0x80000000;
  this->__vftable = (Scaleform::Render::TreeCacheShape_vtbl *)&Scaleform::Render::TreeCacheShape::`vftable';
}
