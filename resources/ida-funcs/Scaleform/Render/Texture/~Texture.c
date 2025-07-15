void __thiscall Scaleform::Render::Texture::~Texture(Scaleform::Render::Texture *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->__vftable = (Scaleform::Render::Texture_vtbl *)&Scaleform::Render::Texture::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->pManagerLocks.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
