void __thiscall Scaleform::Render::TreeCacheShape::HandleChanges(
        Scaleform::Render::TreeCacheShape *this,
        char changeBits)
{
  unsigned int v3; // ecx
  Scaleform::Render::TreeCacheNode *pParent; // ebp
  int v5; // edx
  Scaleform::Render::EdgeAAMode v6; // eax
  Scaleform::Render::TreeCacheRoot *pRoot; // ecx
  Scaleform::Render::TreeCacheShapeLayer *i; // edi
  Scaleform::Render::Rect<float> *v9; // eax
  Scaleform::Render::TreeNode *pNode; // eax

  if ( (changeBits & 0x20) != 0 )
  {
    v3 = (int)this->pNode & 0xFFFFF000;
    pParent = this->pParent;
    if ( pParent )
    {
      v5 = pParent->Flags & 0xC;
      if ( v5 == 12 )
      {
        v6 = EdgeAA_Disable;
LABEL_8:
        this->propagateEdgeAA(this, v6);
        goto LABEL_9;
      }
    }
    else
    {
      v5 = 4;
    }
    v6 = *(_WORD *)((*(_DWORD *)(*(_DWORD *)(v3 + 20) + 4 * ((int)((int)&this->pNode[-1] - v3) / 28) + 20) & 0xFFFFFFFE)
                  + 6)
       & 0xC;
    if ( v6 == EdgeAA_Inherit )
      v6 = v5;
    goto LABEL_8;
  }
LABEL_9:
  if ( (changeBits & 0x10) != 0 )
  {
    pRoot = this->pRoot;
    if ( pRoot )
    {
      Scaleform::Render::TreeCacheRoot::AddToUpdate(pRoot, this, 1u);
      for ( i = (Scaleform::Render::TreeCacheShapeLayer *)this->Children.Root.pNext;
            ;
            i = (Scaleform::Render::TreeCacheShapeLayer *)i->pNext )
      {
        v9 = this == (Scaleform::Render::TreeCacheShape *)-80 ? 0 : &this->SortParentBounds;
        if ( i == (Scaleform::Render::TreeCacheShapeLayer *)v9 )
          break;
        pNode = i->pNode;
        if ( !pNode )
          pNode = i->pParent->Scaleform::Render::TreeCacheMeshBase::Scaleform::Render::TreeCacheNode::pNode;
        if ( *(_BYTE *)(*(_DWORD *)((*(_DWORD *)(*(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x14)
                                               + 4 * ((int)((int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000)) / 28)
                                               + 20)
                                   & 0xFFFFFFFE)
                                  + 144)
                      + 80) )
          Scaleform::Render::TreeCacheShapeLayer::updateSortKey(i);
      }
    }
  }
}
