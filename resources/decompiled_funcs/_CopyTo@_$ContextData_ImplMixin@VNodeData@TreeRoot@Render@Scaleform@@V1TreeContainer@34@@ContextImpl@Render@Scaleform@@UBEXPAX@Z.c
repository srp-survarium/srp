void __thiscall Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeRoot::NodeData,Scaleform::Render::TreeContainer::NodeData>::CopyTo(
        Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeRoot::NodeData,Scaleform::Render::TreeContainer::NodeData> *this,
        char *pdest)
{
  Scaleform::Render::TreeNode::NodeData::operator=((Scaleform::Render::TreeNode::NodeData *)pdest, this);
  Scaleform::Render::TreeNodeArray::operator=((Scaleform::Render::TreeNodeArray *)pdest + 18, &this->Children);
  qmemcpy(pdest + 160, &this[1], 0x30u);
  ++Scaleform::Render::ContextImpl::CopyCalls;
}
