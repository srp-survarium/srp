bool __thiscall Scaleform::Render::RBGenericImpl::RenderBufferManager::Initialize(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::GFx::Resource *manager,
        Scaleform::Render::ImageFormat format,
        const Scaleform::Render::Size<unsigned long> *screenSize)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  bool v6; // zf
  unsigned int CtorReuseLimit; // eax
  bool result; // al

  if ( manager )
    Scaleform::RefCountImpl::AddRef(manager);
  pObject = (Scaleform::RefCountVImpl *)this->pTextureManager.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pTextureManager.pObject = (Scaleform::Render::TextureManager *)manager;
  this->DefImageFormat = format;
  v6 = ((unsigned __int8 (__thiscall *)(Scaleform::GFx::Resource *, Scaleform::Render::ImageFormat, int))manager->__vftable[1].~Scaleform::GFx::Resource)(
         manager,
         format,
         1024) == 0;
  CtorReuseLimit = this->CtorReuseLimit;
  this->RequirePow2 = v6;
  if ( CtorReuseLimit == -1 )
  {
    if ( !screenSize->Width && !screenSize->Height )
    {
      result = 1;
      this->ReuseLimit = 0;
      return result;
    }
    CtorReuseLimit = 16 * screenSize->Width * screenSize->Height;
  }
  this->ReuseLimit = CtorReuseLimit;
  return 1;
}
