Scaleform::GFx::ASMovieRootBase *__thiscall Scaleform::GFx::ASMovieRootBase::`scalar deleting destructor'(
        Scaleform::GFx::ASMovieRootBase *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->__vftable = (Scaleform::GFx::ASMovieRootBase_vtbl *)&Scaleform::GFx::ASMovieRootBase::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->pASSupport.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
