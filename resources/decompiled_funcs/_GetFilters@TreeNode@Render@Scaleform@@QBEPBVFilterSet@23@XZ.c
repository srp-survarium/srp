const Scaleform::Render::FilterSet *__thiscall Scaleform::Render::TreeNode::GetFilters(
        Scaleform::Render::TreeNode *this)
{
  const Scaleform::Render::State *State; // eax

  State = Scaleform::Render::TreeNode::GetState(this, State_ActionControl);
  if ( State )
    return (const Scaleform::Render::FilterSet *)State->pData;
  else
    return 0;
}
