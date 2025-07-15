void __thiscall Scaleform::Render::TransformArgs::SetViewProj(
        Scaleform::Render::TransformArgs *this,
        const Scaleform::Render::TreeNode::NodeData *data,
        const Scaleform::Render::TransformArgs *t)
{
  const Scaleform::Render::ViewMatrix3DState *State; // ebp
  const Scaleform::Render::ProjectionMatrix3DState *v5; // eax

  if ( t )
  {
    this->viewState = t->viewState;
    this->projState = t->projState;
    this->bRecomputeViewProj = t->bRecomputeViewProj;
    memcpy((unsigned __int8 *)&this->ViewProj, (unsigned __int8 *)&t->ViewProj, sizeof(this->ViewProj));
  }
  if ( data )
  {
    if ( (data->Flags & 0x800) != 0 )
      State = (const Scaleform::Render::ViewMatrix3DState *)Scaleform::Render::StateBag::GetState(
                                                              &data->States,
                                                              State_FSCommandHandler);
    else
      State = 0;
    if ( (data->Flags & 0x1000) != 0 )
      v5 = (const Scaleform::Render::ProjectionMatrix3DState *)Scaleform::Render::StateBag::GetState(
                                                                 &data->States,
                                                                 State_ExternalInterface);
    else
      v5 = 0;
    if ( State )
    {
      this->viewState = State;
      this->bRecomputeViewProj = 1;
    }
    if ( v5 )
    {
      this->projState = v5;
      this->bRecomputeViewProj = 1;
    }
  }
}
