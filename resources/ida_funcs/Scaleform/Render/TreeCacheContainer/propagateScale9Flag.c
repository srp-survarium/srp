void __thiscall Scaleform::Render::TreeCacheContainer::propagateScale9Flag(
        Scaleform::Render::TreeCacheContainer *this,
        unsigned int partOfScale9)
{
  unsigned int v3; // ebx
  Scaleform::Render::TreeCacheNode *pNext; // edi
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // esi
  int v6; // eax

  v3 = partOfScale9;
  if ( Scaleform::Render::StateBag::GetState(
         (Scaleform::Render::StateBag *)((*(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                                                    + 4
                                                    * ((int)((int)&this->pNode[-1] - ((int)this->pNode & 0xFFFFF000))
                                                     / 28)
                                                    + 20)
                                        & 0xFFFFFFFE)
                                       + 64),
         State_Log) )
  {
    v3 = partOfScale9 | 0x80;
  }
  if ( (this->Flags & 0x80) != v3 )
  {
    pNext = this->Children.Root.pNext;
    this->Flags = v3 | this->Flags & 0xFF7F;
    p_Children = &this->Children;
    while ( 1 )
    {
      v6 = p_Children ? (int)&p_Children[-2] : 0;
      if ( pNext == (Scaleform::Render::TreeCacheNode *)v6 )
        break;
      pNext->propagateScale9Flag(pNext, v3);
      pNext = pNext->pNext;
    }
  }
}
