void __thiscall Scaleform::Render::MeshProvider_RCImpl::Release(Scaleform::Render::MeshProvider_RCImpl *this)
{
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)&this[-1].RefCount);
}
