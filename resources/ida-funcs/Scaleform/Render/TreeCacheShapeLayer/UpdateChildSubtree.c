void __thiscall Scaleform::Render::TreeCacheShapeLayer::UpdateChildSubtree(
        Scaleform::Render::TreeCacheShapeLayer *this,
        const Scaleform::Render::TreeNode::NodeData *data,
        unsigned __int16 depth)
{
  int v4; // esi

  v4 = this->Flags & 0xFFBF
     | ((unsigned __int8)(2 * (this->Flags & 0x20)) | (unsigned __int8)this->pParent->Flags) & 0xC0;
  if ( data )
  {
    if ( Scaleform::Render::StateBag::GetState(&data->States, State_Log) )
      v4 |= 0x80u;
    if ( (data->Flags & 0x200) != 0 )
      v4 |= 0x200u;
  }
  if ( v4 != this->Flags )
  {
    this->Flags = v4;
    Scaleform::Render::TreeCacheShapeLayer::updateSortKey(this);
  }
  if ( data )
    Scaleform::Render::TreeCacheNode::updateMaskCache(this, data, depth, 1);
}
