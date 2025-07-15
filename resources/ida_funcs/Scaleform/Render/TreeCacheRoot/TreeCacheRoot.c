void __thiscall Scaleform::Render::TreeCacheRoot::TreeCacheRoot(
        Scaleform::Render::TreeCacheRoot *this,
        Scaleform::Render::Renderer2DImpl *prenderer2D,
        Scaleform::Render::HAL *phal,
        unsigned int flags,
        Scaleform::Render::TreeRoot *pnode)
{
  Scaleform::Render::Rect<float> *p_SortParentBounds; // ecx
  Scaleform::MemoryHeap *v7; // eax
  Scaleform::Render::TreeCacheNode **ArrayReserve; // ecx
  int v9; // eax

  Scaleform::Render::TreeCacheNode::TreeCacheNode(this, pnode, prenderer2D, flags);
  this->__vftable = (Scaleform::Render::TreeCacheRoot_vtbl *)&Scaleform::Render::TreeCacheContainer::`vftable';
  if ( this == (Scaleform::Render::TreeCacheRoot *)-80 )
    p_SortParentBounds = 0;
  else
    p_SortParentBounds = &this->SortParentBounds;
  this->Children.Root.Scaleform::Render::TreeCacheContainer::pPrev = (Scaleform::Render::TreeCacheNode *)p_SortParentBounds;
  this->Children.Root.pNext = (Scaleform::Render::TreeCacheNode *)p_SortParentBounds;
  this->CachedChildPattern.pFirst = 0;
  this->CachedChildPattern.pLast = 0;
  this->CachedChildPattern.Length = 0x80000000;
  this->pHAL = phal;
  this->__vftable = (Scaleform::Render::TreeCacheRoot_vtbl *)&Scaleform::Render::TreeCacheRoot::`vftable';
  this->ViewCullRect.x1 = 0.0;
  this->ViewCullRect.y1 = 0.0;
  this->ViewCullRect.x2 = 0.0;
  this->ViewCullRect.y2 = 0.0;
  this->pUpdateList = 0;
  this->DepthUpdatesChained = 0;
  v7 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  ArrayReserve = this->DepthUpdates.ArrayReserve;
  this->DepthUpdates.pHeap = v7;
  this->DepthUpdates.pDepth = this->DepthUpdates.ArrayReserve;
  this->DepthUpdates.DepthUsed = 0;
  this->DepthUpdates.DepthAvailable = 32;
  this->DepthUpdates.NullValue = 0;
  v9 = 32;
  do
  {
    *ArrayReserve++ = this->DepthUpdates.NullValue;
    --v9;
  }
  while ( v9 );
  this->pRoot = this;
  this->CachedChildPattern.pLast = 0;
  this->CachedChildPattern.pFirst = 0;
  this->CachedChildPattern.Length = 0;
}
