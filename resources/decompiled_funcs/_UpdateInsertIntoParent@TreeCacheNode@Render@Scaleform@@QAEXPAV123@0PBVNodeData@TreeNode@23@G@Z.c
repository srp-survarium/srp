void __thiscall Scaleform::Render::TreeCacheNode::UpdateInsertIntoParent(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::TreeCacheNode *pparent,
        Scaleform::Render::TreeCacheNode *pinsert,
        const Scaleform::Render::TreeNode::NodeData *nodeData,
        int depth)
{
  Scaleform::Render::TreeCacheNode *v6; // ebx
  const Scaleform::Render::TreeNode::NodeData *v7; // ebp
  Scaleform::Render::TreeCacheNode_vtbl *v8; // edx
  void (__thiscall *UpdateChildSubtree)(Scaleform::Render::TreeCacheNode *, const Scaleform::Render::TreeNode::NodeData *, unsigned __int16); // eax
  Scaleform::Render::TreeCacheNode *pMask; // ecx
  void (__thiscall *propagateMaskFlag)(Scaleform::Render::TreeCacheNode *, unsigned int); // eax
  unsigned int v12; // ebx

  v6 = this->pParent;
  if ( v6 == pparent )
  {
    if ( pinsert )
    {
      if ( pparent->pMask != this )
      {
LABEL_4:
        v7 = nodeData;
        goto LABEL_5;
      }
    }
    else if ( pparent->pMask == this )
    {
      goto LABEL_4;
    }
  }
  if ( v6 )
  {
    Scaleform::Render::TreeCacheNode::RemoveFromParent(this);
    if ( v6->pRoot )
    {
      if ( v6->IsPatternChainValid(v6) )
        Scaleform::Render::TreeCacheRoot::AddToUpdate(
          v6->pRoot,
          v6,
          (unsigned int)&vostok::memory::s_CRT_arena[5574200]);
    }
  }
  if ( pinsert )
  {
    this->pPrev = pinsert->pNext->pPrev;
    this->pNext = pinsert->pNext;
    pinsert->pNext->pPrev = this;
    pinsert->pNext = this;
  }
  v7 = nodeData;
  if ( nodeData )
  {
    if ( (nodeData->Flags & 0x20) != 0 )
    {
      pMask = pparent->pMask;
      if ( pMask && pMask != this )
        Scaleform::Render::TreeCacheNode::RemoveFromParent(pMask);
      pparent->Flags |= 0x10u;
      pparent->pMask = this;
      propagateMaskFlag = this->propagateMaskFlag;
      this->Flags |= 0x20u;
      propagateMaskFlag(this, 64u);
    }
    v12 = pparent->Flags & 0x80;
    if ( Scaleform::Render::StateBag::GetState(&nodeData->States, State_Log) )
      v12 |= 0x80u;
    this->propagateScale9Flag(this, v12);
    this->propagateEdgeAA(this, (Scaleform::Render::EdgeAAMode)(pparent->Flags & 0xC));
  }
  this->pParent = pparent;
LABEL_5:
  v8 = this->__vftable;
  this->Depth = depth;
  UpdateChildSubtree = v8->UpdateChildSubtree;
  this->pRoot = pparent->pRoot;
  UpdateChildSubtree(this, v7, depth + 1);
}
