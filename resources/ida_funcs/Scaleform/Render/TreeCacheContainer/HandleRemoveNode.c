void __thiscall Scaleform::Render::TreeCacheContainer::HandleRemoveNode(Scaleform::Render::TreeCacheContainer *this)
{
  Scaleform::Render::TreeCacheNode *pMask; // ecx
  Scaleform::Render::TreeCacheNode *pNext; // edi
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // esi
  int v5; // eax

  pMask = this->pMask;
  this->pRoot = 0;
  if ( pMask )
    pMask->HandleRemoveNode(pMask);
  this->CachedChildPattern.pLast = 0;
  this->CachedChildPattern.pFirst = 0;
  this->CachedChildPattern.Length = 0x80000000;
  pNext = this->Children.Root.pNext;
  p_Children = &this->Children;
  while ( 1 )
  {
    v5 = p_Children ? (int)&p_Children[-2] : 0;
    if ( pNext == (Scaleform::Render::TreeCacheNode *)v5 )
      break;
    pNext->HandleRemoveNode(pNext);
    pNext = pNext->pNext;
  }
}
