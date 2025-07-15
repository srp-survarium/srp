void __thiscall Scaleform::Render::MeshProvider_RCImpl::AddRef(Scaleform::Render::MeshProvider_RCImpl *this)
{
  Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)&this[-1].RefCount);
}
