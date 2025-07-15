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


void __thiscall Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeRoot::NodeData,Scaleform::Render::TreeContainer::NodeData>::CopyTo(
        Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeRoot::NodeData,Scaleform::Render::TreeContainer::NodeData> *this,
        char *pdest)
{
  Scaleform::Render::TreeNode::NodeData::operator=((Scaleform::Render::TreeNode::NodeData *)pdest, this);
  Scaleform::Render::TreeNodeArray::operator=((Scaleform::Render::TreeNodeArray *)pdest + 18, &this->Children);
  qmemcpy(pdest + 160, &this[1], 0x30u);
  ++Scaleform::Render::ContextImpl::CopyCalls;
}


void __thiscall Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeShape::NodeData,Scaleform::Render::TreeNode::NodeData>::CopyTo(
        Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeShape::NodeData,Scaleform::Render::TreeNode::NodeData> *this,
        Scaleform::Render::TreeShape::NodeData *pdest)
{
  Scaleform::Render::TreeShape::NodeData::operator=(pdest, (const Scaleform::Render::TreeShape::NodeData *)this);
  ++Scaleform::Render::ContextImpl::CopyCalls;
}


void __thiscall Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeText::NodeData,Scaleform::Render::TreeNode::NodeData>::CopyTo(
        Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeText::NodeData,Scaleform::Render::TreeNode::NodeData> *this,
        Scaleform::Render::TreeText::NodeData *pdest)
{
  Scaleform::Render::TreeText::NodeData::operator=(pdest, (const Scaleform::Render::TreeText::NodeData *)this);
  ++Scaleform::Render::ContextImpl::CopyCalls;
}
