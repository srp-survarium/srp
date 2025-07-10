Scaleform::Render::TreeNode *__thiscall Scaleform::Render::TreeShape::NodeData::CloneCreate(
        Scaleform::Render::TreeShape::NodeData *this,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::TreeShape::NodeData *v3; // esi

  v3 = (Scaleform::Render::TreeShape::NodeData *)context->pHeap->Alloc(context->pHeap, 160, 0);
  if ( v3 )
    Scaleform::Render::TreeShape::NodeData::NodeData(
      v3,
      (Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeShape::NodeData>)this);
  return (Scaleform::Render::TreeNode *)Scaleform::Render::ContextImpl::Context::createEntryHelper(context, v3);
}
