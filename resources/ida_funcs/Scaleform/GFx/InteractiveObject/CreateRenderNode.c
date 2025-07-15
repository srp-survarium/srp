Scaleform::Ptr<Scaleform::Render::TreeNode> *__thiscall Scaleform::GFx::InteractiveObject::CreateRenderNode(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::Ptr<Scaleform::Render::TreeNode> *result,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::TreeNode::NodeData *v3; // eax
  Scaleform::Render::TreeNode::NodeData *v4; // esi
  Scaleform::Render::TreeNode *EntryHelper; // eax

  v3 = (Scaleform::Render::TreeNode::NodeData *)context->pHeap->Alloc(context->pHeap, 160, 0);
  v4 = v3;
  if ( v3 )
  {
    Scaleform::Render::TreeNode::NodeData::NodeData(v3, ET_Container);
    v4->__vftable = (Scaleform::Render::TreeNode::NodeData_vtbl *)&Scaleform::Render::TreeContainer::NodeData::`vftable';
    *(_DWORD *)&v4[1].Type = 0;
    v4[1].__vftable = 0;
  }
  EntryHelper = (Scaleform::Render::TreeNode *)Scaleform::Render::ContextImpl::Context::createEntryHelper(
                                                 context,
                                                 &v4->Scaleform::Render::ContextImpl::EntryData);
  if ( EntryHelper )
    ++EntryHelper->RefCount;
  result->pObject = EntryHelper;
  if ( EntryHelper )
  {
    if ( EntryHelper->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(EntryHelper);
  }
  return result;
}
