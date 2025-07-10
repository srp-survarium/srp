void __thiscall Scaleform::GFx::DisplayObjectBase::SetFilters(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::FilterSet *filters)
{
  Scaleform::Render::TreeNode *RenderNode; // eax

  if ( Scaleform::GFx::DisplayObjectBase::GetRenderNode(this) )
  {
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetFilters(RenderNode, filters);
  }
}
