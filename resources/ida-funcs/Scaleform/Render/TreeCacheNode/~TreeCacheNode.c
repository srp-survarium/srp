void __thiscall Scaleform::Render::TreeCacheNode::~TreeCacheNode(Scaleform::Render::TreeCacheNode *this)
{
  bool v2; // zf
  Scaleform::Render::TreeCacheNode *pParent; // eax
  Scaleform::Render::TreeCacheNode *pMask; // ecx

  v2 = this->pPrev == 0;
  this->__vftable = (Scaleform::Render::TreeCacheNode_vtbl *)&Scaleform::Render::TreeCacheNode::`vftable';
  if ( v2 )
  {
    pParent = this->pParent;
    if ( pParent )
    {
      pParent->Flags &= ~0x10u;
      pParent->pMask = 0;
    }
  }
  else
  {
    this->pPrev->pNext = this->pNext;
    this->pNext->pPrev = this->pPrev;
  }
  pMask = this->pMask;
  if ( pMask )
    Scaleform::Render::TreeCacheNode::RemoveFromParent(pMask);
  Scaleform::Render::CacheEffectChain::~CacheEffectChain(&this->Effects);
}
