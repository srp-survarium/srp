void __thiscall Scaleform::Render::TreeCacheText::UpdateChildSubtree(
        Scaleform::Render::TreeCacheText *this,
        const Scaleform::Render::TreeNode::NodeData *data,
        int depth)
{
  int v3; // eax

  v3 = this->Flags & 0xFFBF
     | ((unsigned __int8)(2 * (this->Flags & 0x20)) | (unsigned __int8)this->pParent->Flags) & 0xC0;
  if ( data && (data->Flags & 0x200) != 0 )
    v3 |= 0x200u;
  if ( v3 != this->Flags )
    this->Flags = v3;
  if ( data )
    Scaleform::Render::TreeCacheNode::updateMaskCache(this, data, depth, 1);
}
