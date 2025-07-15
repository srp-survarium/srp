Scaleform::Render::BlendMode __thiscall Scaleform::GFx::DisplayObjectBase::GetBlendMode(
        Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *RenderNode; // eax
  const Scaleform::Render::State *State; // eax

  if ( !Scaleform::GFx::DisplayObjectBase::GetRenderNode(this) )
    return this->BlendMode;
  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  State = Scaleform::Render::TreeNode::GetState(RenderNode, State_Translator);
  if ( State )
    return (Scaleform::Render::BlendMode)State->pData;
  else
    return 0;
}
