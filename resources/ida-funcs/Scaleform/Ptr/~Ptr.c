void __thiscall Scaleform::Ptr<Scaleform::Render::Texture>::~Ptr<Scaleform::Render::Texture>(
        Scaleform::Ptr<Scaleform::Render::Texture> *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
}
