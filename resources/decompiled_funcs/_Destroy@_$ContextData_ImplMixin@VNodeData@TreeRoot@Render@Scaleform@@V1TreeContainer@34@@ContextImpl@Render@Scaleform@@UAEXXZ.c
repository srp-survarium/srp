void __thiscall Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeRoot::NodeData,Scaleform::Render::TreeContainer::NodeData>::Destroy(
        Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeText::NodeData,Scaleform::Render::TreeNode::NodeData> *this)
{
  ++Scaleform::Render::ContextImpl::DestroyCalls;
  ((void (__thiscall *)(Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeText::NodeData,Scaleform::Render::TreeNode::NodeData> *, _DWORD))this->~Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeText::NodeData,Scaleform::Render::TreeNode::NodeData>)(
    this,
    0);
}
