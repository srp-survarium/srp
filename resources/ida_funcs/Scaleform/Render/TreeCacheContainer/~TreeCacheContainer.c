void __thiscall Scaleform::Render::TreeCacheContainer::~TreeCacheContainer(Scaleform::Render::TreeCacheContainer *this)
{
  Scaleform::Render::TreeCacheNode *pNext; // ecx
  Scaleform::Render::Rect<float> *v3; // eax
  Scaleform::Render::TreeCacheNode *v4; // esi

  pNext = this->Children.Root.pNext;
  this->__vftable = (Scaleform::Render::TreeCacheContainer_vtbl *)&Scaleform::Render::TreeCacheContainer::`vftable';
  while ( 1 )
  {
    v3 = this == (Scaleform::Render::TreeCacheContainer *)-80 ? 0 : &this->SortParentBounds;
    if ( pNext == (Scaleform::Render::TreeCacheNode *)v3 )
      break;
    v4 = pNext->pNext;
    pNext->pParent = 0;
    pNext->pNext = 0;
    pNext->pPrev = 0;
    if ( pNext->pRoot )
      pNext->HandleRemoveNode(pNext);
    pNext = v4;
  }
  Scaleform::Render::TreeCacheNode::~TreeCacheNode(this);
}
