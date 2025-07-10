Scaleform::Render::TreeCacheNode *__thiscall Scaleform::Render::TreeContainer::NodeData::updateCache(
        Scaleform::Render::TreeContainer::NodeData *this,
        Scaleform::Render::TreeCacheNode *pparent,
        Scaleform::Render::TreeCacheNode *pinsert,
        int pnode,
        unsigned __int16 depth)
{
  Scaleform::Render::TreeNode *v5; // ebp
  Scaleform::Render::TreeCacheNode *v6; // esi
  int v8; // eax
  int v9; // ecx
  unsigned int v10; // esi
  Scaleform::Render::TreeCacheContainer *v11; // eax
  Scaleform::Render::TreeCacheNode *v12; // eax

  v5 = (Scaleform::Render::TreeNode *)pnode;
  v6 = *(Scaleform::Render::TreeCacheNode **)(pnode + 12);
  if ( v6 )
    goto LABEL_17;
  if ( pparent )
  {
    v8 = pparent->Flags & 0xC;
    if ( v8 == 12 )
    {
      v9 = 12;
      goto LABEL_8;
    }
  }
  else
  {
    v8 = 4;
  }
  v9 = this->Flags & 0xC;
  if ( (this->Flags & 0xC) == 0 )
    v9 = v8;
LABEL_8:
  v10 = v9 | this->Flags & 1;
  if ( (this->Flags & 0x20) != 0 )
    v10 |= 0x60u;
  if ( (this->Flags & 0x200) != 0 )
    v10 |= 0x200u;
  pnode = 74;
  v11 = (Scaleform::Render::TreeCacheContainer *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   pparent,
                                                   112,
                                                   &pnode);
  if ( v11 )
  {
    Scaleform::Render::TreeCacheContainer::TreeCacheContainer(v11, v5, pparent->pRenderer2D, v10);
    v6 = v12;
  }
  else
  {
    v6 = 0;
  }
  v5->pRenderer = v6;
  if ( !v6 )
    return 0;
LABEL_17:
  Scaleform::Render::TreeCacheNode::UpdateInsertIntoParent(v6, pparent, pinsert, this, depth);
  return v6;
}
