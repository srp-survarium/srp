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


void __thiscall Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeRoot::NodeData,Scaleform::Render::TreeContainer::NodeData>::ConstructCopy(
        Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeRoot::NodeData,Scaleform::Render::TreeContainer::NodeData> *this,
        Scaleform::Render::LinearHeap *heap)
{
  unsigned __int8 *v3; // eax

  ++Scaleform::Render::ContextImpl::ConstructCopyCalls;
  v3 = Scaleform::Render::LinearHeap::Alloc(heap, 0xD0u);
  if ( v3 )
    Scaleform::Render::TreeRoot::NodeData::NodeData(
      (Scaleform::Render::TreeRoot::NodeData *)v3,
      (const Scaleform::Render::TreeRoot::NodeData *)this);
}


void __thiscall Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeShape::NodeData,Scaleform::Render::TreeNode::NodeData>::ConstructCopy(
        Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeShape::NodeData,Scaleform::Render::TreeNode::NodeData> *this,
        Scaleform::Render::LinearHeap *heap)
{
  unsigned __int8 *v3; // eax

  ++Scaleform::Render::ContextImpl::ConstructCopyCalls;
  v3 = Scaleform::Render::LinearHeap::Alloc(heap, 0xA0u);
  if ( v3 )
    Scaleform::Render::TreeShape::NodeData::NodeData(
      (Scaleform::Render::TreeShape::NodeData *)v3,
      (const Scaleform::Render::TreeShape::NodeData *)this);
}


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
