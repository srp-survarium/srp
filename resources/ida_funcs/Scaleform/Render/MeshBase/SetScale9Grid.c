void __thiscall Scaleform::Render::MeshBase::SetScale9Grid(
        Scaleform::Render::MeshBase *this,
        Scaleform::GFx::Resource *s9g)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  if ( s9g )
    Scaleform::RefCountImpl::AddRef(s9g);
  pObject = (Scaleform::RefCountVImpl *)this->pScale9Grid.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pScale9Grid.pObject = (Scaleform::Render::Scale9GridData *)s9g;
}
