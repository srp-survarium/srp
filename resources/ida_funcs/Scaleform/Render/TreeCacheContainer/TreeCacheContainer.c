void __thiscall Scaleform::Render::TreeCacheContainer::TreeCacheContainer(
        Scaleform::Render::TreeCacheContainer *this,
        Scaleform::Render::TreeNode *pnode,
        Scaleform::Render::Renderer2DImpl *prenderer2D,
        unsigned int flags)
{
  Scaleform::Render::Rect<float> *p_SortParentBounds; // ecx

  Scaleform::Render::TreeCacheNode::TreeCacheNode(this, pnode, prenderer2D, flags);
  this->__vftable = (Scaleform::Render::TreeCacheContainer_vtbl *)&Scaleform::Render::TreeCacheContainer::`vftable';
  if ( this == (Scaleform::Render::TreeCacheContainer *)-80 )
    p_SortParentBounds = 0;
  else
    p_SortParentBounds = &this->SortParentBounds;
  this->Children.Root.pPrev = (Scaleform::Render::TreeCacheNode *)p_SortParentBounds;
  this->Children.Root.pNext = (Scaleform::Render::TreeCacheNode *)p_SortParentBounds;
  this->CachedChildPattern.pFirst = 0;
  this->CachedChildPattern.pLast = 0;
  this->CachedChildPattern.Length = 0x80000000;
}
