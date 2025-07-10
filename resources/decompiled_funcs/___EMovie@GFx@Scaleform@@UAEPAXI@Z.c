Scaleform::GFx::Movie *__thiscall Scaleform::GFx::Movie::`vector deleting destructor'(
        Scaleform::GFx::Movie *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::Movie_vtbl *)&Scaleform::GFx::Movie::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::Movie,327>'};
  this->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::Movie::`vftable'{for `Scaleform::GFx::StateBag'};
  pObject = (Scaleform::RefCountVImpl *)this->pASMovieRoot.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBag::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
