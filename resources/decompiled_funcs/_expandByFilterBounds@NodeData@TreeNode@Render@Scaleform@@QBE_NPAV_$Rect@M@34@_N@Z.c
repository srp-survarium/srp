bool __thiscall Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(
        Scaleform::Render::TreeNode::NodeData *this,
        Scaleform::Render::Rect<float> *bounds,
        bool boundsEmpty)
{
  bool result; // al
  unsigned int State; // eax
  int v5; // edi
  unsigned int i; // esi

  result = boundsEmpty;
  if ( !boundsEmpty )
  {
    State = Scaleform::Render::StateBag::GetState(&this->States, State_ActionControl);
    if ( State )
    {
      v5 = *(_DWORD *)(State + 4);
      if ( v5 )
      {
        for ( i = 0; i < *(_DWORD *)(v5 + 12); ++i )
          Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(
            *(const Scaleform::Render::Filter **)(*(_DWORD *)(v5 + 8) + 4 * i),
            bounds);
      }
    }
    return 0;
  }
  return result;
}
