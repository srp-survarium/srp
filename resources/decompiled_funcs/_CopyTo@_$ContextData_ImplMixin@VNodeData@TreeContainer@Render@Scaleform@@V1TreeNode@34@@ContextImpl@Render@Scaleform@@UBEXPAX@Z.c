void __thiscall Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeContainer::NodeData,Scaleform::Render::TreeNode::NodeData>::CopyTo(
        Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeContainer::NodeData,Scaleform::Render::TreeNode::NodeData> *this,
        void *pdest)
{
  Scaleform::Render::TreeNode::NodeData::operator=((Scaleform::Render::TreeNode::NodeData *)pdest, this);
  Scaleform::Render::TreeNodeArray::operator=(
    (Scaleform::Render::TreeNodeArray *)pdest + 18,
    (const Scaleform::Render::TreeNodeArray *)&this[1]);
  ++Scaleform::Render::ContextImpl::CopyCalls;
}
