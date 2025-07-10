double __thiscall Scaleform::GFx::DisplayObjectBase::GetRendererFloat(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::Render::ContextImpl::Entry *v2; // esi
  float RendererFloat; // [esp+0h] [ebp-4h]

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v2 = RenderNode;
  if ( RenderNode )
    ++RenderNode->RefCount;
  RendererFloat = Scaleform::Render::TreeNode::GetRendererFloat(RenderNode);
  if ( v2 )
  {
    if ( v2->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v2);
  }
  return RendererFloat;
}
