void __thiscall Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeText::NodeData,Scaleform::Render::TreeNode::NodeData>::ConstructCopy(
        Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeText::NodeData,Scaleform::Render::TreeNode::NodeData> *this,
        Scaleform::Render::LinearHeap *heap)
{
  unsigned __int8 *v3; // eax

  ++Scaleform::Render::ContextImpl::ConstructCopyCalls;
  v3 = Scaleform::Render::LinearHeap::Alloc(heap, 0xA0u);
  if ( v3 )
    Scaleform::Render::TreeText::NodeData::NodeData(
      (Scaleform::Render::TreeText::NodeData *)v3,
      (const Scaleform::Render::TreeText::NodeData *)this);
}
