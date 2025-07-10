Scaleform::Render::TreeNodeArray *__thiscall Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeContainer::NodeData,Scaleform::Render::TreeNode::NodeData>::ConstructCopy(
        Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeContainer::NodeData,Scaleform::Render::TreeNode::NodeData> *this,
        Scaleform::Render::LinearHeap *heap)
{
  unsigned __int8 *v3; // eax
  Scaleform::Render::TreeNodeArray *v4; // esi

  ++Scaleform::Render::ContextImpl::ConstructCopyCalls;
  v3 = Scaleform::Render::LinearHeap::Alloc(heap, 0xA0u);
  v4 = (Scaleform::Render::TreeNodeArray *)v3;
  if ( !v3 )
    return 0;
  Scaleform::Render::TreeNode::NodeData::NodeData((Scaleform::Render::TreeNode::NodeData *)v3, this);
  v4->pData[0] = (unsigned int)&Scaleform::Render::TreeContainer::NodeData::`vftable';
  Scaleform::Render::TreeNodeArray::TreeNodeArray(v4 + 18, (const Scaleform::Render::TreeNodeArray *)&this[1]);
  return v4;
}
