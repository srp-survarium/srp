Scaleform::GFx::Loader *__thiscall Scaleform::GFx::Loader::`vector deleting destructor'(
        Scaleform::GFx::Loader *this,
        char a2)
{
  Scaleform::RefCountVImpl *pImpl; // ecx
  Scaleform::GFx::ResourceLib *pStrongResourceLib; // ecx

  pImpl = (Scaleform::RefCountVImpl *)this->pImpl;
  this->__vftable = (Scaleform::GFx::Loader_vtbl *)&Scaleform::GFx::Loader::`vftable';
  if ( pImpl )
    Scaleform::RefCountImpl::Release(pImpl);
  pStrongResourceLib = this->pStrongResourceLib;
  if ( pStrongResourceLib )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pStrongResourceLib);
  this->__vftable = (Scaleform::GFx::Loader_vtbl *)&Scaleform::GFx::StateBag::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
