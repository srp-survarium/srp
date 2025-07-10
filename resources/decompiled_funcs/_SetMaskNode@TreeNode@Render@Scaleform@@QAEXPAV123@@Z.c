void __thiscall Scaleform::Render::TreeNode::SetMaskNode(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::TreeNode *node)
{
  const Scaleform::Render::TreeNode::NodeData *WritableData; // eax
  const Scaleform::Render::TreeNode::NodeData *v4; // esi
  Scaleform::Render::ContextImpl::EntryData *v5; // eax

  WritableData = (const Scaleform::Render::TreeNode::NodeData *)Scaleform::Render::ContextImpl::Entry::getWritableData(
                                                                  this,
                                                                  0x40000u);
  v4 = WritableData;
  if ( node )
  {
    v5 = Scaleform::Render::ContextImpl::Entry::getWritableData(node, 0x80u);
    node->pParent = this;
    v5->Flags |= 0x20u;
    Scaleform::Render::StateBag::SetStateVoid(
      (Scaleform::Render::StateBag *)&v5[8],
      &Scaleform::Render::Internal_MaskOwnerState::InterfaceImpl,
      this);
    v4->Flags |= 0x10u;
    Scaleform::Render::StateBag::SetStateVoid(&v4->States, &Scaleform::Render::MaskNodeState::InterfaceImpl, node);
  }
  else if ( Scaleform::Render::TreeNode::removeThisAsMaskOwner(WritableData) )
  {
    Scaleform::Render::StateBag::RemoveState(&v4->States, State_UserEventHandler);
    v4->Flags &= ~0x10u;
  }
  if ( !this->PNode.Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}
