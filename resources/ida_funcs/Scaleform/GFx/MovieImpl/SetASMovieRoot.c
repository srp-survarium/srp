void __thiscall Scaleform::GFx::MovieImpl::SetASMovieRoot(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Resource *pasmgr)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx

  if ( pasmgr )
    Scaleform::RefCountImpl::AddRef(pasmgr);
  pObject = (Scaleform::RefCountVImpl *)this->pSavedASMovieRoot.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pSavedASMovieRoot.pObject = (Scaleform::GFx::ASMovieRootBase *)pasmgr;
  if ( pasmgr )
    Scaleform::RefCountImpl::AddRef(pasmgr);
  v4 = (Scaleform::RefCountVImpl *)this->pASMovieRoot.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  this->pASMovieRoot.pObject = this->pSavedASMovieRoot.pObject;
}
