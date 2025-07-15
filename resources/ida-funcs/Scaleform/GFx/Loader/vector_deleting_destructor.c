Scaleform::GFx::Loader *__thiscall Scaleform::GFx::Loader::`vector deleting destructor'(
        Scaleform::GFx::Loader *this,
        char a2)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::RefCountVImpl *pImpl; // ecx
  Scaleform::RefCountVImpl *pStrongResourceLib; // ecx

  this->__vftable = (Scaleform::GFx::Loader_vtbl *)&Scaleform::GFx::Loader::`vftable';
  Instance = Scaleform::AmpServer::GetInstance();
  Instance->RemoveLoader(Instance, this);
  pImpl = (Scaleform::RefCountVImpl *)this->pImpl;
  if ( pImpl )
    Scaleform::RefCountImpl::Release(pImpl);
  pStrongResourceLib = (Scaleform::RefCountVImpl *)this->pStrongResourceLib;
  if ( pStrongResourceLib )
    Scaleform::RefCountImpl::Release(pStrongResourceLib);
  this->__vftable = (Scaleform::GFx::Loader_vtbl *)&Scaleform::GFx::StateBag::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
