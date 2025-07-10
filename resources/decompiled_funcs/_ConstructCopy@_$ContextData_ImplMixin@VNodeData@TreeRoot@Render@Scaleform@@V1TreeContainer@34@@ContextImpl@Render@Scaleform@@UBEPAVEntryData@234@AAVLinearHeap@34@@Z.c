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
