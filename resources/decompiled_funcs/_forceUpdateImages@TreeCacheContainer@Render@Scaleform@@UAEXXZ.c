void __thiscall Scaleform::Render::TreeCacheContainer::forceUpdateImages(Scaleform::Render::TreeCacheContainer *this)
{
  Scaleform::Render::TreeCacheNode *pNext; // esi
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // edi
  int v3; // eax

  pNext = this->Children.Root.pNext;
  p_Children = &this->Children;
  while ( 1 )
  {
    v3 = p_Children ? (int)&p_Children[-2] : 0;
    if ( pNext == (Scaleform::Render::TreeCacheNode *)v3 )
      break;
    pNext->forceUpdateImages(pNext);
    pNext = pNext->pNext;
  }
}
