void __thiscall Scaleform::Render::TreeCacheContainer::propagateMaskFlag(
        Scaleform::Render::TreeCacheContainer *this,
        unsigned int partOfMask)
{
  Scaleform::Render::TreeCacheNode *pNext; // esi
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // edi
  int v4; // eax

  pNext = this->Children.Root.pNext;
  this->Flags = partOfMask | this->Flags & 0xFFBF;
  p_Children = &this->Children;
  while ( 1 )
  {
    v4 = p_Children ? (int)&p_Children[-2] : 0;
    if ( pNext == (Scaleform::Render::TreeCacheNode *)v4 )
      break;
    if ( (pNext->Flags & 0x20) == 0 )
      pNext->propagateMaskFlag(pNext, partOfMask);
    pNext = pNext->pNext;
  }
}
