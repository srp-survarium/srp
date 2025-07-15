const char *__thiscall Scaleform::GFx::DisplayObjectBase::GetRendererString(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::Render::ContextImpl::Entry *v2; // esi
  const char *result; // eax
  const char *v4; // edi

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v2 = RenderNode;
  if ( RenderNode )
    ++RenderNode->RefCount;
  result = Scaleform::Render::TreeNode::GetRendererString(RenderNode);
  v4 = result;
  if ( v2 )
  {
    if ( v2->RefCount-- == 1 )
    {
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v2);
      return v4;
    }
  }
  return result;
}
