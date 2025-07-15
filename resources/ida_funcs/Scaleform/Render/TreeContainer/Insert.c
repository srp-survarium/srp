char __thiscall Scaleform::Render::TreeContainer::Insert(
        Scaleform::Render::TreeContainer *this,
        unsigned int index,
        Scaleform::Render::TreeNode *pnode)
{
  Scaleform::Render::TreeNodeArray *WritableData; // eax
  char v5; // bl

  WritableData = (Scaleform::Render::TreeNodeArray *)Scaleform::Render::ContextImpl::Entry::getWritableData(
                                                       this,
                                                       0x100u);
  v5 = Scaleform::Render::TreeNodeArray::Insert(WritableData + 18, index, pnode);
  if ( v5 )
  {
    ++pnode->RefCount;
    pnode->pParent = this;
    if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
      Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
  }
  return v5;
}
