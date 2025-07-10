void __thiscall Scaleform::Render::MaskNodeState::Interface::Release(
        Scaleform::Render::MaskNodeState::Interface *this,
        Scaleform::Render::ContextImpl::Entry *data,
        Scaleform::Render::StateData::Interface::RefBehaviour b)
{
  if ( b != Ref_NoTreeNode && data->RefCount-- == 1 )
    Scaleform::Render::ContextImpl::Entry::destroyHelper(data);
}
