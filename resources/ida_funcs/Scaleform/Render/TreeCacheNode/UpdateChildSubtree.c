void __thiscall Scaleform::Render::TreeCacheNode::UpdateChildSubtree(
        Scaleform::Render::TreeCacheNode *this,
        const Scaleform::Render::TreeNode::NodeData *data,
        int depth)
{
  unsigned __int16 v4; // si
  Scaleform::Render::TreeCacheNode *pParent; // eax

  v4 = this->Flags ^ ((unsigned __int8)this->Flags ^ (unsigned __int8)(2 * this->Flags)) & 0x40;
  if ( Scaleform::Render::StateBag::GetState(&data->States, State_Log) )
    v4 |= 0x80u;
  pParent = this->pParent;
  if ( pParent )
    v4 |= pParent->Flags & 0xC0;
  if ( (data->Flags & 0x200) != 0 )
    v4 |= 0x200u;
  this->Flags = v4;
  Scaleform::Render::TreeCacheNode::updateMaskCache(this, data, depth, 1);
}
