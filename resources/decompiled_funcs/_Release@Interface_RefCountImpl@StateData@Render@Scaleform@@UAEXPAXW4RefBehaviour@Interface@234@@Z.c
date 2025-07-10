void __thiscall Scaleform::Render::StateData::Interface_RefCountImpl::Release(
        Scaleform::Render::StateData::Interface_RefCountImpl *this,
        Scaleform::RefCountVImpl *data,
        Scaleform::Render::StateData::Interface::RefBehaviour b)
{
  if ( b != Ref_ReleaseTreeNodeOnly )
    Scaleform::RefCountImpl::Release(data);
}
