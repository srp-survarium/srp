void __thiscall Scaleform::Render::MaskNodeState::Interface::AddRef(
        Scaleform::Render::MaskNodeState::Interface *this,
        _DWORD *data,
        Scaleform::Render::StateData::Interface::RefBehaviour b)
{
  if ( b != Ref_NoTreeNode )
    ++data[1];
}
