void __thiscall Scaleform::GFx::Loader::Loader(
        Scaleform::GFx::Loader *this,
        const Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> *pfileOpener,
        const Scaleform::Ptr<Scaleform::GFx::ZlibSupportBase> *pzlib)
{
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::GFx::FileOpenerBase *v5; // ebx
  Scaleform::GFx::Resource *v6; // ecx
  Scaleform::RefCountVImpl *v7; // edi
  Scaleform::GFx::Loader::LoaderConfig config; // [esp+Ch] [ebp-Ch] BYREF

  this->__vftable = (Scaleform::GFx::Loader_vtbl *)&Scaleform::GFx::Loader::`vftable';
  pObject = (Scaleform::GFx::Resource *)pfileOpener->pObject;
  config.DefLoadFlags = 0;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  v5 = pfileOpener->pObject;
  v6 = (Scaleform::GFx::Resource *)pzlib->pObject;
  config.pFileOpener = (Scaleform::Ptr<Scaleform::GFx::FileOpenerBase>)pfileOpener->pObject;
  if ( v6 )
    Scaleform::RefCountImpl::AddRef(v6);
  config.pZLibSupport = (Scaleform::Ptr<Scaleform::GFx::ZlibSupportBase>)pzlib->pObject;
  v7 = (Scaleform::RefCountVImpl *)config.pZLibSupport.pObject;
  Scaleform::GFx::Loader::InitLoader(this, &config);
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
}
