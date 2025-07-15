const Scaleform::Render::FilterSet *__thiscall Scaleform::GFx::DisplayObjectBase::GetFilters(
        Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *RenderNode; // eax
  const Scaleform::Render::State *State; // eax

  if ( Scaleform::GFx::DisplayObjectBase::GetRenderNode(this)
    && (RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this),
        (State = Scaleform::Render::TreeNode::GetState(RenderNode, State_ActionControl)) != 0) )
  {
    return (const Scaleform::Render::FilterSet *)State->pData;
  }
  else
  {
    return 0;
  }
}
