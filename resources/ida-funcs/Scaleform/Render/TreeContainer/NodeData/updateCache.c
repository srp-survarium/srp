Scaleform::Render::TreeCacheNode *__thiscall Scaleform::Render::TreeContainer::NodeData::updateCache(
        Scaleform::Render::TreeContainer::NodeData *this,
        Scaleform::Render::TreeCacheNode *pparent,
        Scaleform::Render::TreeCacheNode *pinsert,
        Scaleform::Render::TreeNode *pnode,
        int depth)
{
  Scaleform::Render::TreeNode *v5; // ebp
  Scaleform::Render::TreeCacheNode *pRenderer; // esi
  int v8; // eax
  __int16 v9; // cx
  unsigned __int16 v10; // si
  Scaleform::Render::TreeCacheContainer *v11; // eax
  Scaleform::Render::TreeCacheNode *v12; // eax

  v5 = pnode;
  pRenderer = pnode->pRenderer;
  if ( pRenderer )
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
    LOWORD(v8) = 4;
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
  pnode = (Scaleform::Render::TreeNode *)74;
  v11 = (Scaleform::Render::TreeCacheContainer *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   pparent,
                                                   112,
                                                   &pnode);
  if ( v11 )
  {
    Scaleform::Render::TreeCacheContainer::TreeCacheContainer(v11, v5, pparent->pRenderer2D, v10);
    pRenderer = v12;
  }
  else
  {
    pRenderer = 0;
  }
  v5->pRenderer = pRenderer;
  if ( !pRenderer )
    return 0;
LABEL_17:
  Scaleform::Render::TreeCacheNode::UpdateInsertIntoParent(pRenderer, pparent, pinsert, this, depth);
  return pRenderer;
}
