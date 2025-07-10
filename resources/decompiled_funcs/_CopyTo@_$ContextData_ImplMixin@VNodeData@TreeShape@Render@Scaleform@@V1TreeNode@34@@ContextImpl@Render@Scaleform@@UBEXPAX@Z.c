void __thiscall Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeShape::NodeData,Scaleform::Render::TreeNode::NodeData>::CopyTo(
        Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeShape::NodeData,Scaleform::Render::TreeNode::NodeData> *this,
        Scaleform::Render::TreeShape::NodeData *pdest)
{
  Scaleform::Render::TreeShape::NodeData::operator=(pdest, (const Scaleform::Render::TreeShape::NodeData *)this);
  ++Scaleform::Render::ContextImpl::CopyCalls;
}
