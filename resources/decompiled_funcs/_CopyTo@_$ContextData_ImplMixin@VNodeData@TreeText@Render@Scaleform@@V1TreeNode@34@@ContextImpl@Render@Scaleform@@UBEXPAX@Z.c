void __thiscall Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeText::NodeData,Scaleform::Render::TreeNode::NodeData>::CopyTo(
        Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeText::NodeData,Scaleform::Render::TreeNode::NodeData> *this,
        Scaleform::Render::TreeText::NodeData *pdest)
{
  Scaleform::Render::TreeText::NodeData::operator=(pdest, (const Scaleform::Render::TreeText::NodeData *)this);
  ++Scaleform::Render::ContextImpl::CopyCalls;
}
