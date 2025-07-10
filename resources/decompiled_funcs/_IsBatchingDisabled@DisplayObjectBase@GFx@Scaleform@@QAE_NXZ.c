bool __thiscall Scaleform::GFx::DisplayObjectBase::IsBatchingDisabled(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::Render::ContextImpl::Entry *v2; // esi
  bool IsBatchingDisabled; // bl

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v2 = RenderNode;
  if ( RenderNode )
    ++RenderNode->RefCount;
  IsBatchingDisabled = Scaleform::Render::TreeNode::IsBatchingDisabled(RenderNode);
  if ( v2 )
  {
    if ( v2->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v2);
  }
  return IsBatchingDisabled;
}
