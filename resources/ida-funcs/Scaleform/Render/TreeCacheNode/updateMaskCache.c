void __thiscall Scaleform::Render::TreeCacheNode::updateMaskCache(
        Scaleform::Render::TreeCacheNode *this,
        const Scaleform::Render::TreeNode::NodeData *data,
        int depth,
        bool updateSubtree)
{
  const volatile Scaleform::Render::TreeNode *v5; // esi
  Scaleform::Render::TreeCacheNode *v6; // eax
  Scaleform::Render::TreeCacheNode *pMask; // ecx

  TCN_This = this;
  TCN_ThisData = data;
  if ( (data->Flags & 0x10) == 0 )
  {
    pMask = this->pMask;
    if ( !pMask )
      return;
    Scaleform::Render::TreeCacheNode::RemoveFromParent(pMask);
    goto update_on_mask_change;
  }
  v5 = *(const volatile Scaleform::Render::TreeNode **)(Scaleform::Render::StateBag::GetState(
                                                          &data->States,
                                                          State_UserEventHandler)
                                                      + 4);
  TCN_ChildNode = v5;
  if ( updateSubtree )
  {
    (*(void (__thiscall **)(unsigned int, Scaleform::Render::TreeCacheNode *, _DWORD, const volatile Scaleform::Render::TreeNode *, int))(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)v5 & 0xFFFFF000) + 0x14) + 4 * ((int)((int)&v5[-1] - ((unsigned int)v5 & 0xFFFFF000)) / 28) + 20) & 0xFFFFFFFE) + 24))(
      *(_DWORD *)(*(_DWORD *)(((unsigned int)v5 & 0xFFFFF000) + 0x14)
                + 4 * ((int)((int)&v5[-1] - ((unsigned int)v5 & 0xFFFFF000)) / 28)
                + 20)
    & 0xFFFFFFFE,
      this,
      0,
      v5,
      depth);
    return;
  }
  v6 = this->pMask;
  if ( v5->pRenderer != v6 || !v6 )
  {
    (*(void (__thiscall **)(unsigned int, Scaleform::Render::TreeCacheNode *, _DWORD, const volatile Scaleform::Render::TreeNode *, int))(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)v5 & 0xFFFFF000) + 0x14) + 4 * ((int)((int)&v5[-1] - ((unsigned int)v5 & 0xFFFFF000)) / 28) + 20) & 0xFFFFFFFE) + 24))(
      *(_DWORD *)(*(_DWORD *)(((unsigned int)v5 & 0xFFFFF000) + 0x14)
                + 4 * ((int)((int)&v5[-1] - ((unsigned int)v5 & 0xFFFFF000)) / 28)
                + 20)
    & 0xFFFFFFFE,
      this,
      0,
      v5,
      depth);
update_on_mask_change:
    if ( this->pRoot )
    {
      if ( this->IsPatternChainValid(this) )
        Scaleform::Render::TreeCacheRoot::AddToUpdate(this->pRoot, this, 0x1000000u);
    }
  }
}
