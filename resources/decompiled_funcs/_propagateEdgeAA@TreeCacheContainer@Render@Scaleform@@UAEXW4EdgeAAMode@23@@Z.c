void __thiscall Scaleform::Render::TreeCacheContainer::propagateEdgeAA(
        Scaleform::Render::TreeCacheContainer *this,
        Scaleform::Render::EdgeAAMode parentEdgeAA)
{
  unsigned int v2; // esi
  Scaleform::Render::EdgeAAMode v3; // edi
  Scaleform::Render::TreeCacheNode *pNext; // esi
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // ebx
  int v6; // eax

  v2 = (int)this->pNode & 0xFFFFF000;
  v3 = parentEdgeAA;
  if ( parentEdgeAA != EdgeAA_Disable
    && (*(_WORD *)((*(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                              + 4 * ((int)((int)&this->pNode[-1] - v2) / 28)
                              + 20)
                  & 0xFFFFFFFE)
                 + 6)
      & 0xC) != 0 )
  {
    v3 = *(_WORD *)((*(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                               + 4 * ((int)((int)&this->pNode[-1] - v2) / 28)
                               + 20)
                   & 0xFFFFFFFE)
                  + 6)
       & 0xC;
  }
  if ( (this->Flags & 0xC) != v3 )
  {
    pNext = this->Children.Root.pNext;
    this->Flags = v3 | this->Flags & 0xFFF3;
    p_Children = &this->Children;
    while ( 1 )
    {
      v6 = p_Children ? (int)&p_Children[-2] : 0;
      if ( pNext == (Scaleform::Render::TreeCacheNode *)v6 )
        break;
      pNext->propagateEdgeAA(pNext, v3);
      pNext = pNext->pNext;
    }
  }
}
