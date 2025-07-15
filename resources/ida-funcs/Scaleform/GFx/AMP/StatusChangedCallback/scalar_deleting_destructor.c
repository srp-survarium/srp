Scaleform::GFx::AMP::StatusChangedCallback *__thiscall Scaleform::GFx::AMP::StatusChangedCallback::`scalar deleting destructor'(
        Scaleform::GFx::AMP::StatusChangedCallback *this,
        char a2)
{
  this->Scaleform::RefCountBase<Scaleform::GFx::AMP::StatusChangedCallback,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::AMP::StatusChangedCallback_vtbl *)&Scaleform::GFx::AMP::StatusChangedCallback::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::AMP::StatusChangedCallback,579>'};
  this->Scaleform::GFx::AMP::ConnStatusInterface::__vftable = (Scaleform::GFx::AMP::ConnStatusInterface_vtbl *)&Scaleform::GFx::AMP::ConnStatusInterface::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
