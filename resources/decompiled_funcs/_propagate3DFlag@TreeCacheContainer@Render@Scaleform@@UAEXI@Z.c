void __thiscall Scaleform::Render::TreeCacheContainer::propagate3DFlag(
        Scaleform::Render::TreeCacheContainer *this,
        unsigned int parent3D)
{
  Scaleform::Render::TreeCacheNode *pNext; // esi
  unsigned int v3; // ebx
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // edi
  int v5; // eax

  if ( parent3D != 512 || (this->Flags & 0x200) == 0 )
  {
    pNext = this->Children.Root.pNext;
    v3 = this->Flags & 0x200 | parent3D;
    p_Children = &this->Children;
    while ( 1 )
    {
      v5 = p_Children ? (int)&p_Children[-2] : 0;
      if ( pNext == (Scaleform::Render::TreeCacheNode *)v5 )
        break;
      pNext->propagate3DFlag(pNext, v3);
      pNext = pNext->pNext;
    }
  }
}
