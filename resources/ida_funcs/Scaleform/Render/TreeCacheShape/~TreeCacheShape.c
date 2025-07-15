void __thiscall Scaleform::Render::TreeCacheShape::~TreeCacheShape(Scaleform::Render::TreeCacheShape *this)
{
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // esi
  int v3; // eax
  Scaleform::Render::TreeCacheNode *pNext; // ecx

  this->__vftable = (Scaleform::Render::TreeCacheShape_vtbl *)&Scaleform::Render::TreeCacheShape::`vftable';
  p_Children = &this->Children;
  while ( 1 )
  {
    v3 = p_Children ? (int)&p_Children[-2] : 0;
    if ( p_Children->Root.pNext == (Scaleform::Render::TreeCacheNode *)v3 )
      break;
    pNext = this->Children.Root.pNext;
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->pPrev = pNext->pPrev;
    pNext->pPrev = 0;
    pNext->pParent = 0;
    ((void (__thiscall *)(Scaleform::Render::TreeCacheNode *, int))pNext->~Scaleform::Render::TreeCacheNode)(pNext, 1);
  }
  Scaleform::Render::TreeCacheContainer::~TreeCacheContainer(this);
}
