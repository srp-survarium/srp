void __thiscall Scaleform::GFx::DisplayObjectBase::SetRendererString(
        Scaleform::GFx::DisplayObjectBase *this,
        char *str)
{
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::Render::ContextImpl::Entry *v3; // esi

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v3 = RenderNode;
  if ( RenderNode )
    ++RenderNode->RefCount;
  Scaleform::Render::TreeNode::SetRendererString(RenderNode, str);
  if ( v3 )
  {
    if ( v3->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v3);
  }
}
