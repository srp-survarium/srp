void __thiscall Scaleform::Render::TreeNode::NodeData::ReleaseNodes(Scaleform::Render::TreeNode::NodeData *this)
{
  if ( (this->Flags & 0x10) != 0 )
    Scaleform::Render::TreeNode::removeThisAsMaskOwner(this);
  Scaleform::Render::StateBag::ReleaseNodes(&this->States);
}
