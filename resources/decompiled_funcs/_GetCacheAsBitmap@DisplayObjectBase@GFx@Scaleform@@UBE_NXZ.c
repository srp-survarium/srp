bool __thiscall Scaleform::GFx::DisplayObjectBase::GetCacheAsBitmap(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *RenderNode; // eax
  const Scaleform::Render::State *State; // eax
  _BYTE *pData; // eax

  if ( Scaleform::GFx::DisplayObjectBase::GetRenderNode(this)
    && (RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this),
        (State = Scaleform::Render::TreeNode::GetState(RenderNode, State_ActionControl)) != 0)
    && (pData = State->pData) != 0 )
  {
    return pData[21];
  }
  else
  {
    return 0;
  }
}
