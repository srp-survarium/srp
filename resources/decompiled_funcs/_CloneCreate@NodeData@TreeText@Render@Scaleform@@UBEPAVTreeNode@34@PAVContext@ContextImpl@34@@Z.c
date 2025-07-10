Scaleform::Render::TreeNode *__thiscall Scaleform::Render::TreeText::NodeData::CloneCreate(
        Scaleform::Render::TreeText::NodeData *this,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::TreeText::NodeData *v3; // esi

  v3 = (Scaleform::Render::TreeText::NodeData *)context->pHeap->Alloc(context->pHeap, 160, 0);
  if ( v3 )
    Scaleform::Render::TreeText::NodeData::NodeData(
      v3,
      (Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeText::NodeData>)this);
  return (Scaleform::Render::TreeNode *)Scaleform::Render::ContextImpl::Context::createEntryHelper(context, v3);
}
